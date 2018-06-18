SOURCES = Main.cpp GameEngine.cpp Sprite.cpp Background.cpp FramedSprite.cpp AnimatedSprite.cpp System.cpp VisualSprite.cpp MobileSprite.cpp AnimatedMobileSprite.cpp ImmobileSprite.cpp Projectile.cpp SantaHero.cpp EvilCat.cpp Particle.cpp Obstacle.cpp Loader.cpp Level.cpp GUIText.cpp GUITextField.cpp PauseScreen.cpp GUIScreen.cpp GUIElement.cpp GUIButton.cpp Screen.cpp 

CC = emcc

game: 
	$(CC) $(SOURCES) -Wall -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -std=c++11 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -O3 -o index.js --preload-file ..@/media/ --use-preload-plugins
