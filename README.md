# mcDirr-GameEngine
This is an attempt at porting https://github.com/FelixTornqvist/mcDirr-GameEngine (a game and game engine we made in a C++ course) to WebAssembly.

Live demo can be found at https://felixtornqvist.github.io/mcDirr-GameEngine-WASM/. Use W, A and D keys to move, space to fire and the escape key for the pause menu.

## Building
Run `make native` to build a native version of the game (SDL2, SDL2_image, SDL2_ttf and SDL2_mixer libraries required).
Run `make wasm` to build a webassembly version of the game (Emscripten http://emscripten.org/ required).
Run `make` to build both versions.

## Running
In the root of the repository, run `build/Game` to run the native version of the game.
To run the webassembly version, first start a local web server in the root of the repository with `python -m SimpleHTTPServer 8080` and then open http://localhost:8080/ in a web browser.
