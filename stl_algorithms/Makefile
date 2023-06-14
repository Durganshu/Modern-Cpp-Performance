CPPFLAGS = -O3 -std=c++20 -isystem benchmark/include  -Lbenchmark/build/src -lbenchmark -lpthread -ltbb
LINK_TARGET = sort_performance transform_performance

#g++ transform_performance.cpp -std=c++20 -O3  -o transform_benchmark
# OBJS1 = 

OBJS = \
	sort_performance.o \
	transform_performance.o \

REBUILDABLES = $(OBJS) $(LINK_TARGET) 

all : $(LINK_TARGET)

clean: 
	rm -f $(REBUILDABLES)


% : %.o
	$(CXX) -c $(CPPFLAGS)  $^ -o $@

# Here is a Pattern Rule, often used for compile-line.
# It says how to create a file with a .o suffix, given a file with a .c suffix.
# The rule's command uses some built-in Make Macros:
# $@ for the pattern-matched target
# $lt; for the pattern-matched dependency

%.o : %.c
	$(CXX)  -Wall -o $@ -c $<
  
# stl_performance.o : stl_performance.h

