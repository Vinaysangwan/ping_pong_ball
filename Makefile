# Compiler
CXX = g++
CXXFLAGS = -I./include -std=c++23 -Wall -Wextra

# Linker
LDFLAGS = -L./lib -lsfml-window -lsfml-system -lsfml-graphics

# Object Files
OBJ = output/main.o output/Game.o output/Home.o output/Play.o output/Player.o  

# Target
all: compile link run

compile:
	$(CXX) $(CXXFLAGS) -c -o output/main.o src/main.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Game.o src/core/Game.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Home.o src/screen/Home.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Play.o src/screen/Play.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Player.o src/entity/Player.cpp

link:
	$(CXX) $(CXXFLAGS) -o main $(OBJ) $(LDFLAGS)

run:
	./main.exe

clean:
	rm -rf ./output/*