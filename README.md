# PrimeFDG
Find prime numbers using an optimized, multithreaded and segmented Sieve of Eratosthenes implementation, written in C with OpenMP.

The successor to my previous related projects.

## Building
### On Linux (CMake + GCC)
Prerequisites (on Debian):
```
sudo apt install git build-essential cmake
```
Compiling release build:
```
git pull https://github.com/OronDF343/PrimeFDG.git
cd PrimeFDG
cmake . -DCMAKE_BUILD_TYPE:STRING=Release
make
```

It is also possible to use VSCode with the following extension packs:
* C/C++ Extension Pack
* CMake Tools

### On Windows (MSVC)
Prerequisites:
* Visual Studio 2019 version 16.9 or newer
* Desktop C++ workload
* MSVC v142 toolchain
* Windows SDK version 10

## Performance

Testing performed 2022-03-04:
* CPU: AMD Ryzen 9 3900X (12 cores, 24 threads)
* RAM: 64GB (4x16) DDR4 @ 3733MHz CL16 with tweaked subtimings
* OS: Windows 10 x64 20H2
* The results were not saved to file, in order to measure pure calculation performance
* Command line: `PrimeFDG.exe 1 <range> <threads>`
* Results are based on a very small number of runs (1 <= N <= 10)
* Number of primes does not include the prime `2`

Results: (time in seconds)

Range | Primes found | 1 thread | 2 threads | 4 threads | 8 threads | 16 threads | 24 threads | Peak memory usage
--- | --- | --- | --- | --- | --- | --- | --- | ---
10^9 | 50847533 | \~0.61 | \~0.32 | \~0.19 | \~0.12 | \~0.09 | \~0.08 | <1 MB
10^10 | 455052510 | 7.85 | 3.71 | 1.84 | 1.15 | 1.02 | 0.85 | 2 MB
10^11 | 4118054812 | 88.42 | 44.92 | 23.05 | 12.24 | 10.28 | 7.86 | 7 MB
10^12 | 37607912017 | 3500.51 | 1947.48 | 584.79 | 139.84 | 111.67 | 88.43 | 31 MB
