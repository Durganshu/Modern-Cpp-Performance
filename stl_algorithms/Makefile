CXX := g++
CXXFLAGS := -std=c++20 -O3
INCLUDES := -isystem benchmark/include
LDFLAGS := -Lbenchmark/build/src -lbenchmark -lpthread -ltbb

all: transform_benchmark sort_benchmark

transform_benchmark: transform_performance.cpp
	$(CXX) $(CXXFLAGS) $< $(INCLUDES) $(LDFLAGS) -o $@

sort_benchmark: sort_performance.cpp
	$(CXX) $(CXXFLAGS) $< $(INCLUDES) $(LDFLAGS) -o $@

clean:
	rm -f transform_benchmark sort_benchmark

.PHONY: all clean

