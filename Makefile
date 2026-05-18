# =========================================
# Simple C++ Makefile
# =========================================

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++20 -O2

# Target executable
TARGET = app

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# =========================================
# Build Rules
# =========================================

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================================
# Utility Targets
# =========================================

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)

rebuild: clean all

# =========================================
# Phony Targets
# =========================================

.PHONY: all clean run rebuild
