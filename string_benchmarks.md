# Benchmarks on strings (std::string vs std::string_view)

This file contains a list of benchmarks created for identifying the best-performing ways of using strings in C++.

## const char* vs std::string

Clang, [O3](https://quick-bench.com/q/o_LHrPJ1VJhxHMlF-UmM_CQZ75g)

## Declaring/Initializing short std::string vs long std::string

GCC, [O3](https://quick-bench.com/q/gzql16zeY7IvT7oOsejBZMoiUI4) vs [Og](https://quick-bench.com/q/-2lDRQ4MrTtiVSRvJiBzsa0SQYk)

Clang, [O3](https://quick-bench.com/q/QFP9CNyFjhXiCywr69F_eJ3K9Hk) vs [Og](https://quick-bench.com/q/5F-fdvkYCl5j68xhmUIVRni2n2o)

## Declaring/Initializing short std::string_view vs long std::string_view

GCC, [O3](https://quick-bench.com/q/xX0Ji2dPTtt-fN_QTFX_K-m39CQ) vs [Og](https://quick-bench.com/q/KjepIZQnC4HU_tbtqAXOO6p-hYo)

Clang, [O3](https://quick-bench.com/q/hg-Aj1T5cqywBTUfFM1Eu_v9fv0) vs [Og](https://quick-bench.com/q/po86SAaJFwV0WmIYlSLnvifia4w)

## Declaring/Initializing std::string vs std::string_view

GCC, [O3](https://quick-bench.com/q/TvPOJs_YDb2IsZxtnPrpRm5dJKs)

## Extracting substrings

GCC, [O3](https://quick-bench.com/q/h7c7--iZ6o-yYNrGg8cK5q0ah8s) 

Clang, [O3](https://quick-bench.com/q/0P5eyQhnCaFI9FP2rzd0dsSxf48)

## Copying strings

GCC, [O3](https://quick-bench.com/q/B6S6z8g_O8lWTCMmC5TRpV99kw4) 

Clang, [O3](https://quick-bench.com/q/a9R1ourte5reisjcYO4R8blwIww)

## Finding in strings

GCC (C++17), [O3](https://quick-bench.com/q/hpV_Fxo-Oe5zTOjDRzyVLfBJZMI) vs [Og](https://quick-bench.com/q/X_uPKtGGYCMsSfF8O7JshWWy7zk)

Clang (C++17), [O3](https://quick-bench.com/q/HPqxjDvbNnl56Q1PHQRnDQrX3ms) vs [Og](https://quick-bench.com/q/oHy5DXOa_eus2FklaCLryPXw8M8)

GCC (C++20), [O3](https://quick-bench.com/q/10fSVgnjuk_T_7MNDiJ_-HJGEmQ) vs [Og](https://quick-bench.com/q/svmXjgn64UgHhGO0vEDXFcpX-Do)

Clang (C++20), [O3](https://quick-bench.com/q/PsZYEy6HLt66-mMuEz0vKZB8TGQ) vs [Og](https://quick-bench.com/q/u2NrF5COcw9ZQkun5ff544ZaS68)


## References

https://stackoverflow.com/questions/40127965/how-exactly-is-stdstring-view-faster-than-const-stdstring
https://www.cppstories.com/2018/07/string-view-perf/
https://shaharmike.com/cpp/std-string/
https://giodicanio.com/2023/04/26/cpp-small-string-optimization/
