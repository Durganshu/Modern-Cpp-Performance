#include <benchmark/benchmark.h>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <execution>
#include <iostream>
#include <random>
#include <string>
#include <vector>

constexpr int size = 50000;  
  
const double pi = std::acos(-1);

static void standardSort(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
  std::vector<double> myVector(randValues);

  for (auto _ : state) {
    // standard sequential sort                              
    std::sort(myVector.begin(), myVector.end());                         
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(standardSort)->UseRealTime();

static void sequentialSort(benchmark::State& state) {

  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
  std::vector<double> myVector(randValues);

  for (auto _ : state) {
    // standard sequential sort                              
    std::sort(std::execution::seq, myVector.begin(), myVector.end());                           
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(sequentialSort)->UseRealTime();

static void parallelSort(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
  std::vector<double> myVector(randValues);

  for (auto _ : state) {
    // standard sequential sort                              
    std::sort(std::execution::par, myVector.begin(), myVector.end());                             
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(parallelSort)->UseRealTime();

static void parallelUnsequencedSort(benchmark::State& state) {
  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
    
  std::vector<double> myVector(randValues);
  for (auto _ : state) {
    std::transform(std::execution::par_unseq, myVector.begin(), myVector.end(),  
		   myVector.begin(), 
                   [](double arg){ return std::tan(arg); }
                  );                             
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(parallelUnsequencedSort)->UseRealTime();

static void vectorizedSort(benchmark::State& state) {
  
  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
  std::vector<double> myVector(randValues);

  // Code inside this loop is measured repeatedly
  for (auto _ : state) {
                    
    std::sort(std::execution::unseq, myVector.begin(), myVector.end());                           
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(vectorizedSort)->UseRealTime();

BENCHMARK_MAIN();