#include "stdafx.h"
#include "io.h"
#include "threads.h"
#include "pevents_c.h"

thrd_t thread;
pevent_t event_data_available;
pevent_t event_data_freed;
mtx_t mutex_data;
//mtx_t mutex_enqueue;
typedef struct {
	uint64_t size;
	bitarray** data;
	uint64_t start;
	uint64_t count;
	bool done;
	FILE* file;
} io_queue_t;
io_queue_t* thread_arg;

int io_proc(void* queue_v)
{
	io_queue_t* queue = queue_v;
	while (queue->done != true || queue->count > 0)
	{
		if (queue->count > 0)
		{
			mtx_lock(&mutex_data);
			bitarray* item = queue->data[queue->start];
			queue->start = (queue->start + 1) % queue->size;
			queue->count--;
			mtx_unlock(&mutex_data);

			pevent_set(event_data_freed);
			bitarray_serialize_to_file(item, queue->file);
			bitarray_delete(item);
		}
		else
		{
			// Wait for available data
			thrd_yield();
			pevent_wait(event_data_available, 10);
		}
	}
	return 0;
}

void io_init(FILE* file, const uint64_t queue_length)
{
	thread_arg = malloc(sizeof(io_queue_t));
	thread_arg->size = queue_length;
	thread_arg->start = 0;
	thread_arg->count = 0;
	thread_arg->done = false;
	thread_arg->data = malloc(queue_length * sizeof(bitarray*));
	thread_arg->file = file;
	thrd_create(&thread, io_proc, thread_arg);

	event_data_available = pevent_create(false, false);
	event_data_freed = pevent_create(false, false);

	mtx_init(&mutex_data, mtx_plain);
	//mtx_init(&mutex_enqueue, mtx_plain);
}

void io_enqueue(bitarray* source)
{
	//mtx_lock(&mutex_enqueue);
	while (thread_arg->count >= thread_arg->size)
	{
		// Wait for available slot
		thrd_yield();
		pevent_wait(event_data_freed, 10);
	}
	mtx_lock(&mutex_data);
	thread_arg->data[(thread_arg->start + thread_arg->count) % thread_arg->size] = source;
	thread_arg->count++;
	mtx_unlock(&mutex_data);
	pevent_set(event_data_available);
	//mtx_unlock(&mutex_enqueue);
}

void io_end()
{
	thread_arg->done = true;
	pevent_set(event_data_available);
	thrd_join(thread, NULL);
	thrd_detach(thread);
	free(thread_arg->data);
	free(thread_arg);
	pevent_destroy(event_data_available);
	pevent_destroy(event_data_freed);
	mtx_destroy(&mutex_data);
	//mtx_destroy(&mutex_enqueue);
}
