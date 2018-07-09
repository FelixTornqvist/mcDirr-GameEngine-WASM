CXX=g++

DEBUG=-g
CPPFLAGS=$(DEBUG) -Wall -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -I/usr/include/SDL2/ -std=c++11
LDFLAGS=$(DEBUG) -Wall -std=c++11
LDLIBS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -I /usr/include/SDL2/

SRC = $(shell find src/ -name "*.cpp")
OBJ = $(patsubst src/%.cpp,build/%.o,$(SRC))

.PHONY: all

all: build/Game

build/Game: $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@ 

$(OBJ): build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

.depend: $(SRC)
	$(CXX) -MM $^ > $@ && \
	sed -Ei 's#^(.*\.o: *)src/(.*/)?(.*\.cpp)#build/\2\1src/\2\3#' $@

include .depend
