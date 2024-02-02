# Variables
CXX = g++
CXXFLAGS = -O3 -std=c++17
INCLUDES = -I./include
LIBS = -L./lib
SRCS = $(wildcard ./src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGETS = PrimL PrimM

# Default target
all: $(TARGETS)

# Rule to build the targets
PrimL: $(filter-out ./src/PrimM.cpp, $(SRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

PrimM: $(filter-out ./src/PrimL.cpp, $(SRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Rule to build the objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to clean the build
clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all clean