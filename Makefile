# Compiler
CXX = g++
CXXFLAGS = -I./include -std=c++20 -Wall -Wextra

# Source files
SRC = src/main.cpp src/sdl/Game.cpp
OBJ = main.o Game.o

# Libraries
LDFLAGS = -L./lib -lsfml-graphics -lsfml-window -lsfml-system

# Targets
all: compile link run

compile:
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o
	$(CXX) $(CXXFLAGS) -c src/sdl/Game.cpp -o Game.o

link:
	$(CXX) $(OBJ) -o main $(LDFLAGS)

run:
	./main.exe

clean:
	rm -f $(OBJ) main.exe
