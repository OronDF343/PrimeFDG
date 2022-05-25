# PrimeFDG
Find prime numbers using an optimized, multithreaded and segmented Sieve of Eratosthenes implementation, written in C with OpenMP.

The successor to my previous related projects.

## Usage

**Note: The usage has changed recently**

```
Usage: primefdg <command> [<argument>=<value>...]
(the syntax is similar to dd)

Available commands:
help: Prints this message. This command does not accept arguments.
test: Runs a memcpy speed test. This command does not accept arguments.
sieve: Finds prime numbers within a given range.
mem: Calculates the estimated memory usage of a sieve command with the same arguments.

Available arguments:
start: The start of the range in which to find prime numbers. Supports exponent specifiers. Values below 3 are set to 3. If unspecified, will be set to 0.
end: The end of the range in which to find prime numbers. Supports exponent specifiers. Required.
threads: The number of threads to use for computation. If unspecified or equal to 0, will be set to the number of CPU threads available.
chunks: The number of tasks that the computation will be split into. Supports exponent specifiers. This is an advanced option that can be used to tune performance. If unspecified, the value will be calculated as such: threads * 2^MAX(floor(log10(end)) - 1, 0)
maxmem: Limits the maximum amount of memory to use for computation. Supports exponent specifiers.
outfile: The path to a file to which the computation results will be stored. If unspecified, the results will be discarded immediately.

Usage example: primefdg sieve start=1 end=1e12 threads=8

Exponent specifiers (base 10): k,m,g,t,e
Exponent specifiers (base 2): K,M,G,T
```

## Building
### On Linux (CMake + GCC/Clang)
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
* Visual Studio 2019 (version 16.9 or newer) or 2022
* Desktop C++ workload
* MSVC v142 toolchain
* Windows SDK version 10

## Performance

Testing performed 2022-03-04:
* CPU: AMD Ryzen 9 3900X (12 cores, 24 threads)
* RAM: 64GB (4x16) DDR4 @ 3733MHz CL16 with tweaked subtimings
* OS: Windows 10 x64 20H2
* The results were not saved to file, in order to measure pure calculation performance
* Command line: `primefdg sieve end=<range> threads=<threads>`
* Results are based on a very small number of runs (1 <= N <= 10)
* Number of primes does not include the prime `2`

Results: (time in seconds)

Range | Primes found | 1 thread | 2 threads | 4 threads | 8 threads | 16 threads | 24 threads | Peak memory usage
--- | --- | --- | --- | --- | --- | --- | --- | ---
10^9 | 50847533 | \~0.61 | \~0.32 | \~0.19 | \~0.12 | \~0.09 | \~0.08 | <1 MB
10^10 | 455052510 | 7.85 | 3.71 | 1.84 | 1.15 | 1.02 | 0.85 | 2 MB
10^11 | 4118054812 | 88.42 | 44.92 | 23.05 | 12.24 | 10.28 | 7.86 | 7 MB
10^12 | 37607912017 | 3500.51 | 1947.48 | 584.79 | 139.84 | 111.67 | 88.43 | 31 MB
