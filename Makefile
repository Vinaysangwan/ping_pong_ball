# Compiler
CXX = g++
CXXFLAGS = -I./include -std=c++23 -Wall -Wextra -O3

# Linker
LDFLAGS = -L./lib -lsfml-window -lsfml-system -lsfml-graphics

# Object Files
OBJ = output/main.o output/Game.o output/GameManager.o output/Times.o output/Home.o output/Play.o output/Player.o output/Fonts.o output/Texts.o output/Buttons.o

#Executable
EXE = main.exe

# Target
all: compile link run

compile:
	$(CXX) $(CXXFLAGS) -c -o output/main.o src/main.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Game.o src/core/Game.cpp
	$(CXX) $(CXXFLAGS) -c -o output/GameManager.o src/game_manager/GameManager.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Times.o src/times/Times.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Home.o src/screen/Home.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Play.o src/screen/Play.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Player.o src/entity/Player.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Fonts.o src/fonts/Fonts.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Texts.o src/texts/Texts.cpp
	$(CXX) $(CXXFLAGS) -c -o output/Buttons.o src/components/Buttons.cpp

link:
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJ) $(LDFLAGS)

run:
	./$(EXE)

clean:
	rm -rf ./output/* ./$(EXE)