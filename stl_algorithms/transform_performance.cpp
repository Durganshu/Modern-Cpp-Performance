
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


static void standardTransform(benchmark::State& state) {
  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
    
  std::vector<double> myVector(randValues);
  for (auto _ : state) {
    std::transform( myVector.begin(), myVector.end(),       
		   myVector.begin(), 
                   [](double arg){ return std::tan(arg); });                             // (1)
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(standardTransform)->UseRealTime();

static void sequentialTransform(benchmark::State& state) {
  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
    
  std::vector<double> myVector(randValues);
  
  for (auto _ : state) {

    std::transform(std::execution::seq, myVector.begin(), myVector.end(),      
		   myVector.begin(), 
                   [](double arg){ return std::tan(arg); }
                  );
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(sequentialTransform)->UseRealTime();

static void parallelTransform(benchmark::State& state) {
  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
    
  std::vector<double> myVector(randValues);
  for (auto _ : state) {
    std::transform(std::execution::par, myVector.begin(), myVector.end(),  
		   myVector.begin(), 
                   [](double arg){ return std::tan(arg); }
                  );
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(parallelTransform)->UseRealTime();

static void parallelUnsequencedTransform(benchmark::State& state) {
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
BENCHMARK(parallelUnsequencedTransform)->UseRealTime();


static void vectorizedTransform(benchmark::State& state) {
  std::vector<double> randValues;
  randValues.reserve(size);
   
  std::mt19937 engine;
  std::uniform_real_distribution<> uniformDist(0, pi / 2);
  for (int i = 0 ; i < size ; ++i) randValues.push_back(uniformDist(engine));
    
  std::vector<double> myVector(randValues);
  for (auto _ : state) {
    std::transform(std::execution::unseq, myVector.begin(), myVector.end(),  
		   myVector.begin(), 
                   [](double arg){ return std::tan(arg); }
                  );                             
    benchmark::DoNotOptimize(myVector);
  }
}
// Register the function as a benchmark
BENCHMARK(vectorizedTransform)->UseRealTime();

BENCHMARK_MAIN();