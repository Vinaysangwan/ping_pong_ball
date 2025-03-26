# Compiler
CXX = g++
CXXFLAGS = -I./include -std=c++23 -Wall -Wextra
LDFLAGS = -L./lib -lsfml-window -lsfml-system -lsfml-graphics

# Automatically find .cpp files and convert them to .o
SRC = $(wildcard src/*.cpp src/**/*.cpp)
OBJ = $(patsubst src/%.cpp, output/%.o, $(SRC))

# Target
all: compile link run

compile: $(OBJ)

# Compile each .cpp file to .o
output/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -O3 -c $< -o $@

# Link all .o files into executable
link: $(OBJ)
	$(CXX) $(CXXFLAGS) -O3 -o main $(OBJ) $(LDFLAGS)

run:
	./main.exe

clean:
	rm -rf output/* main
