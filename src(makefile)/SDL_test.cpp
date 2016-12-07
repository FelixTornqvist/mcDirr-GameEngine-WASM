#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#endif

#include <iostream>
#include <string>
using namespace std;

#define FPS 60

int oldmain(int argvc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(0);
	TTF_Init();
	SDL_Window* win = SDL_CreateWindow("Window", 100, 100, 500, 400, 0);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);

	Mix_Chunk* music = Mix_LoadWAV("media/bgMusic.wav");
	Mix_PlayChannel(-1, music, -1);
	Mix_Chunk* klick = Mix_LoadWAV("media/klick.wav");

	TTF_Font* fonten = TTF_OpenFont("media/Ubuntu-B.ttf", 24);
	string rubrik = "Gubbe";
	SDL_Color txtVit = { 255,255,255 };
	SDL_Surface* rubSurface = TTF_RenderText_Solid(fonten, rubrik.c_str(), txtVit);
	SDL_Texture* rubrTexture = SDL_CreateTextureFromSurface(ren, rubSurface);
	int rubrW = rubSurface->w, rubrH = rubSurface->h;
	SDL_Rect rubrRect = { 250,0,rubrW, rubrH };
	SDL_FreeSurface(rubSurface);

	SDL_Surface* bild = SDL_LoadBMP("media/gubbe.bmp");
	if (bild == nullptr) {
		cerr << "Bild hittas inte!" << endl;
		return 13;
	}
	int w = bild->w, h = bild->h;
	int x = 0, y = 0;
	SDL_Rect dest = { x,y,w,h };
	Uint32 white = SDL_MapRGB(bild->format, 255, 255, 255);
	SDL_SetColorKey(bild, SDL_ENABLE, white);
	SDL_Texture* gubbTexture = SDL_CreateTextureFromSurface(ren, bild);
	SDL_FreeSurface(bild);

	SDL_Surface* gubbe2Surface = IMG_Load("media/ebbug.png");
	SDL_Texture* gubbe2 = SDL_CreateTextureFromSurface(ren, gubbe2Surface);
	int w2, h2, x2 = 0, y2 = 0;
	w2 = gubbe2Surface->w;
	h2 = gubbe2Surface->h;
//	SDL_QueryTexture(gubbe2, NULL, NULL, &w2, &h2);

	SDL_FreeSurface(gubbe2Surface);

	SDL_Surface* bg = SDL_LoadBMP("media/bg.bmp");
	SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(ren, bg);
	SDL_FreeSurface(bg);

	int varv = 0;
	int dir = 1;
	bool goOn = true;
	bool moving = false;
	const int TIDPERVARV = 1000 / FPS;
	while (goOn) {
		Uint32 nextTick = SDL_GetTicks() + TIDPERVARV;
		SDL_Event eve;
		while (SDL_PollEvent(&eve)) {
			switch (eve.type) {
			case SDL_QUIT: goOn = false; break;
			case SDL_MOUSEBUTTONDOWN: {
				Mix_PlayChannel(-1, klick, 0);
				SDL_Point p = { eve.button.x, eve.button.y };
				if (SDL_PointInRect(&p, &dest) && eve.button.button == SDL_BUTTON_LEFT)
					moving = true;
			}
			break;
			case SDL_MOUSEMOTION:
				if (moving) {
					x += eve.motion.xrel;
					y += eve.motion.yrel;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				moving = false;
				break;
			case SDL_KEYDOWN:
				switch (eve.key.keysym.sym) {
				case SDLK_END: goOn = false; break;
				case SDLK_RIGHT: x+=5; break;
				case SDLK_LEFT: x--; break;
				case SDLK_UP: y--; break;
				case SDLK_DOWN: y++; break;
				} // inre switch
				break;
			} // switch
		} // inre while

		varv++;
		if (varv % 10 == 0) {
			if (x2 > 500 - w2 || x2 < 0)
				dir = -dir;
			x2 += dir;
		}
		string varvStr = to_string(varv);
		SDL_Surface* varvSurf = TTF_RenderText_Solid(fonten, varvStr.c_str(), txtVit);
		SDL_Texture* varvTxt = SDL_CreateTextureFromSurface(ren, varvSurf);
		SDL_Rect varvRect = { 400, 300, varvSurf->w, varvSurf->h };

		SDL_RenderClear(ren);
		SDL_RenderCopy(ren, bgTexture, NULL, NULL);
		dest.x = x; dest.y = y;
		SDL_RenderCopy(ren, gubbTexture, NULL, &dest);
		SDL_Rect dest2 = { x2,y2, w2, h2 };
		SDL_RenderCopy(ren, gubbe2, NULL, &dest2);
		SDL_RenderCopy(ren, rubrTexture, NULL, &rubrRect);
		SDL_RenderCopy(ren, varvTxt, NULL, &varvRect);
		SDL_RenderPresent(ren);

		SDL_FreeSurface(varvSurf);
		SDL_DestroyTexture(varvTxt);

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);

	} // yttre while

	SDL_DestroyTexture(rubrTexture);
	SDL_DestroyTexture(gubbe2);
	SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(gubbTexture);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}
