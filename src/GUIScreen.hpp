#ifndef GUISCREEN_HPP
#define GUISCREEN_HPP

#include <memory>
#include <list>

#include "Screen.hpp"
#include "GUIElement.hpp"

namespace mcDirr {

	class GUIScreen : public Screen {

		public:
			static GUIScreen* getInstance();

			void tick(int millisPassed) override;
			void draw() override;

			void add(std::shared_ptr<GUIElement> element);
			void setBackground(SDL_Surface* bg);

			virtual ~GUIScreen();

		protected:
			GUIScreen() {}

		private:
			SDL_Texture* background = nullptr;
			std::list<std::shared_ptr<GUIElement>> guiElements;

			/** SDL_PointInRect only exist in newer versions of SDL :'( */
			bool pointInRect(Sint32 px, Sint32 py, SDL_Rect rect);
	};
}

#endif // GUISCREEN_HPP
