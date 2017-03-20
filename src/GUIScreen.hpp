#ifndef GUISCREEN_HPP
#define GUISCREEN_HPP

#include <list>

#include "Screen.hpp"
#include "GUIElement.hpp"

namespace mcDirr {
	class GUIScreen : public Screen {
		public:
			static GUIScreen* getInstance(Screen* nxt);

			void tick(int millisPassed) override;
			void draw() override;

			void add(GUIElement* element);
			void setBackground(SDL_Surface* bg);

			virtual ~GUIScreen();

		protected:
			GUIScreen(Screen* next);

		private:
			SDL_Texture* background = nullptr;
			std::list<GUIElement*> guiElements;

			/** SDL_PointInRect only exist in newer versions of SDL :'( */
			bool pointInRect(Sint32 px, Sint32 py, SDL_Rect rect);
	};
}
#endif // GUISCREEN_HPP
