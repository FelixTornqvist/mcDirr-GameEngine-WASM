#ifndef GUIBUTTON_HPP
#define GUIBUTTON_HPP

#include <functional>
#include <SDL.h>

#include "GUIElement.hpp"

namespace mcDirr {
	class GUIButton : public GUIElement {
		public:
			template<class AnyClass>
			static GUIButton* getInstance(SDL_Surface* surf, AnyClass *object, void (AnyClass::*func)() );
			static GUIButton* getInstance(SDL_Surface* surf, void (*funk)());

			virtual void tick(int millisPassed) override;
			virtual void customTick(int millisPassed) override;
			virtual void mouseClick() override;

			virtual ~GUIButton();

		protected:
			GUIButton(SDL_Surface* surf, std::function<void()> action);

		private:
			std::function<void()> action;
	};

	template<class AnyClass>
	GUIButton* GUIButton::getInstance(SDL_Surface* surf, AnyClass *object, void (AnyClass::*func)() ) {
		return new GUIButton(surf, std::bind(func, object));
	}
}

#endif // GUIBUTTON_HPP
