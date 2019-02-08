CXX=g++

DEBUG=-g
CPPFLAGS=$(DEBUG) -Wall -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -I/usr/include/SDL2/ -std=c++11
LDFLAGS=$(DEBUG) -Wall -std=c++11
LDLIBS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -I /usr/include/SDL2/

SRC = $(shell find src/ -name "*.cpp")
OBJ = $(patsubst src/%.cpp,build/%.o,$(SRC))

.PHONY: all native wasm clean

all: native wasm

wasm: 
	emcc $(SRC) -Wall --bind -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -std=c++11 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -O3 -o index.js --preload-file media/ --use-preload-plugins

native: build/Game


build/Game: $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@ 

$(OBJ): build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

.depend: $(SRC)
	$(CXX) -MM $^ > $@ && \
	sed -Ei 's#^(.*\.o: *)src/(.*/)?(.*\.cpp)#build/\2\1src/\2\3#' $@

clean:
	rm build/*.o
	rm build/Game

include .depend
