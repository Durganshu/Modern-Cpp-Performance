# Benchmarks on smart pointers in C++

This file contains a list of benchmarks created for identifying the best-performing ways of using smart pointers in C++.

## Initializing unique_ptr

GCC, [O3](https://quick-bench.com/q/ACnNT3zXRrjS1NP9PWIw8VzIdU4) vs [Og](https://quick-bench.com/q/b2Ss8pWI7K_oUpZ6RThb3pylBsg)

Clang, [O3](https://quick-bench.com/q/a0z0UfF_gyIrnDFSs9Msu1Ifd6w) vs [Og](https://quick-bench.com/q/a0z0UfF_gyIrnDFSs9Msu1Ifd6w)

## Initializing shared_ptr
GCC, [O3](https://quick-bench.com/q/ZM8HlIUV4ahbiSrDwCEHIuYBPj0) vs [Og](https://quick-bench.com/q/TPfEP7KuVfanfCkrfmmqBDfsnDw)

Clang, [O3](https://quick-bench.com/q/6OTtHNQnqE3SlOOfPf8kRxSxyyE) vs [Og](https://quick-bench.com/q/kxZEjLoWGhDZu_OFEJLOhn0ssqM)

## Intializing shared_ptr using a different shared_ptr

GCC, [O3](https://quick-bench.com/q/XtDGcjlb4eifKfndqHRX878_E_0) vs [Og](https://quick-bench.com/q/Mc2b7BgzhbGYUJ0UURDEXNWzvRI)

Clang, [O3](https://quick-bench.com/q/VQh0_Hh4_tH4v1LwJkIHwtKM_UQ) vs [Og](https://quick-bench.com/q/Y5Y_GxGTEqm4123955sFI6Qv_Vw)

## shared_ptr vs unique_ptr vs new/delete

GCC, [O3](https://quick-bench.com/q/tiMEhw8c69s7audDHJJmo0wfhb4) vs [Og](https://quick-bench.com/q/EBaFFkefA7wjN6kugjh7feGCxHo)

Clang, [O3](https://quick-bench.com/q/yg0HMXW2Bk3YFYsh7kjEnqn9DRY) vs [Og](https://quick-bench.com/q/ueIcar-K86k_E43DCd_41cxzxN8)

## Passing shared_ptr of inherited class to functions accepting shared_ptr of base class

GCC, [O3](https://quick-bench.com/q/5uq2818GQKE4dAxVJNpYjL_qgqc) vs [Og](https://quick-bench.com/q/0HxHf2YBVh55j0S9pJ07osMpGDc)

Clang, [O3](https://quick-bench.com/q/7mpk5XnvwHUyGEAKuKIfy2yXQmI) vs [Og](https://quick-bench.com/q/dH4ktywTa8IYhIDe0_mSXvGgEDQ)

## References

https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
https://learn.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170
https://learn.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=msvc-170
https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r23-use-make_unique-to-make-unique_ptrs
https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r22-use-make_shared-to-make-shared_ptrs
