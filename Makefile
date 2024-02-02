# ###################### FLAGS EXPLANATION ######################
# #	
# #	-Wall : turns on many warnings, but not "all."
# #	-Wextra : turns on even more warnings, but still not all.
# #	-Wpedantic : Issue all the warnings demanded by strict ISO C++.
# #	-Wduplicated-branches : warn if if-else branches have identical bodies.
# #	-Wduplicated-cond : warn about duplicated conditions in an if-else-if chain.
# #	-Wswitch-enum : warn when a switch on an enum type is missing one of the enums.
# #	
# ###################### FLAGS EXPLANATION ######################

# Makefile for building a C++ project

CXX = g++

# Compilation options
INCLUDESDIR = -I src/.
CXXFLAGS = $(INCLUDESDIR)

# Source and target directories
SRC_DIR = src
BIN_DIR = bin

# List all .cpp source files in the src/ directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Generate a list of object file names by replacing .cpp with .o
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRC_FILES))

# Executable program name
TARGET = prim

# Default target compiles the program
all: $(BIN_DIR) $(BIN_DIR)/$(TARGET)
	mv $(BIN_DIR)/$(TARGET) $(TARGET)

# Create the bin/ directory only if it doesn't exist
$(BIN_DIR):
	@if [ ! -d "$(BIN_DIR)" ]; then mkdir -p $(BIN_DIR); fi

# Compile the program
$(BIN_DIR)/$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES)

# Generic rule for creating object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean object files and the executable
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/$(TARGET) $(BIN_DIR)/libmylib.a $(BIN_DIR)/libmylib.so
	rm -f $(TARGET)
	rmdir bin/ 2>/dev/null || true

# Build a static library named libmylib.a
slib: $(BIN_DIR) $(OBJ_FILES)
	ar rcs $(BIN_DIR)/libmylib.a $^

# Build a shared library named libmylib.so
dlib: $(BIN_DIR) $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -shared -o $(BIN_DIR)/libmylib.so $^

# Target to compile the program in debug mode
debug: CXXFLAGS += -g
debug: all

# Phony target to avoid conflicts with files of the same name
.PHONY: all clean