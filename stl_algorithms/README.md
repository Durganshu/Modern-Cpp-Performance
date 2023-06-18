# Benchmarks for std::execution

With the introduction of the std::execution policy in C++17, developers gained even more control over the performance of STL algorithms, mainly through the ability to specify execution modes, including parallel execution. 

Here, we explore the performance implications of using STL algorithms with different std::execution policies

Tests should be run on the local machine with `Google Benchmark` locally installed. Please follow the [official documentation](https://github.com/google/benchmark) for installing `Google-benchmark`.

After successfully installing `Google-Benchmark`, proceed as follows:

### Pre-requisites

 GCC compiler (ideally the latest version, to support the latest C++ standards)
 
 Clang compiler (ideally the latest version, to support the latest C++ standards)

 If the latest version of compilers isn't available, make sure the existing compiler supports the C++ standard specified in the Makefile (by default C++20).

### Building benchmarks

```shell
git clone https://github.com/Durganshu/Modern-Cpp-Performance.git
cd Modern-Cpp-Performance && make
```

### Running the benchmarks

`./sort_benchmark` or `./transform_benchmark`

### Notable reference

https://www.modernescpp.com/index.php/performance-of-the-parallel-stl-algorithmn

