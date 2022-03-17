#include "pevents_c.h"
#ifdef _WIN32
#include <Windows.h>
#endif
#include "pevents.h"

#ifdef __cplusplus
extern "C" {
#endif

pevent_t pevent_create(bool manualReset, bool initialState)
{
    return reinterpret_cast<pevent_t>(neosmart::CreateEvent(manualReset, initialState));
}

int pevent_destroy(pevent_t event)
{
    return neosmart::DestroyEvent(reinterpret_cast<neosmart::neosmart_event_t>(event));
}

int pevent_wait(pevent_t event, uint64_t milliseconds)
{
    return neosmart::WaitForEvent(reinterpret_cast<neosmart::neosmart_event_t>(event), milliseconds);
}

int pevent_set(pevent_t event)
{
    return neosmart::SetEvent(reinterpret_cast<neosmart::neosmart_event_t>(event));
}

int pevent_reset(pevent_t event)
{
    return neosmart::ResetEvent(reinterpret_cast<neosmart::neosmart_event_t>(event));
}

#ifdef WFMO

int pevent_wait_multiple(pevent_t *events, int count, bool waitAll, uint64_t milliseconds)
{
    return neosmart::WaitForMultipleEvents(reinterpret_cast<neosmart::neosmart_event_t*>(events), count, waitAll, milliseconds);
}

int pevent_wait_multiple_get_index(pevent_t *events, int count, bool waitAll, uint64_t milliseconds, int *index)
{
    return neosmart::WaitForMultipleEvents(reinterpret_cast<neosmart::neosmart_event_t*>(events), count, waitAll, milliseconds, index);
}

#endif
#ifdef PULSE

int pevent_pulse(pevent_t event)
{
    return neosmart::PulseEvent(reinterpret_cast<neosmart::neosmart_event_t>(event));
}

#endif

#ifdef __cplusplus
}
#endif
