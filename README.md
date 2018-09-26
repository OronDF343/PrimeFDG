# PrimeFDG
Find prime numbers using an optimized, multithreaded and segmented Sieve of Eratosthenes implementation, written in C with OpenMP.

The successor to my previous related projects.

# Performance
Multithreaded scaling is not great due to the ordered I/O operations used for saving the results. This can be addressed in a future update by either preallocating the file (probably what I'll end up doing) OR writing to multiple files in parallel, but will only bring benefits for high-performance storage technology.

The algorithm is optimized for both speed and memory usage, and is segmented, so performance is not the absolute best possible, but it is pretty fast.

Testing performed 26-09-2018 on the following hardware:
* CPU: AMD Ryzen 7 1700 @ 3.8GHz (8 cores, 16 threads)
* RAM: 2x16GB Hynix dual-rank DDR4 memory @ 2933MHz CL14 with tweaked subtimings
* Target volume 1: ImDisk Toolkit 20161231 RAM Disk, AWE physical memory (no dynamic allocation), 1GiB NTFS

In the future I'll test the following volumes as well: (expect slower results / worse scaling)
* Target volume 2: Samsung 960 EVO 500GB NVMe TLC SSD, NTFS partition #2 (shared with system volume)
* Target volume 3: Micron 1100 2048TB TLC SSD, exFAT
* Target volume 4: Western Digital Red 4TB HDD, NTFS

Results: (time in seconds, average of 4 runs, Gp = billion primes)

Test | 1 thread | 2 threads | 4 threads | 8 threads | 16 threads
--- | --- | --- | --- | --- | ---
1Gp Vol.1 | 3.605 | 2.2877 | 1.562 | 1.2344 | 0.7560
10Gp Vol.1 | 43.939 | 28.131 | 18.266 | 15.503 | 15.244
