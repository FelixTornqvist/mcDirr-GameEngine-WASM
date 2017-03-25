#ifndef GUIBUTTON_HPP
#define GUIBUTTON_HPP

#include <functional>
#include <SDL.h>
#include <memory>

#include "GUIElement.hpp"

namespace mcDirr {
	class GUIButton : public GUIElement {
		public:
			template<class AnyClass>
			static std::shared_ptr<GUIButton> getInstance(SDL_Surface* surf, AnyClass *object, void (AnyClass::*func)() );
			static std::shared_ptr<GUIButton> getInstance(SDL_Surface* surf, void (*funk)());

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
	std::shared_ptr<GUIButton> GUIButton::getInstance(SDL_Surface* surf, AnyClass *object, void (AnyClass::*func)() ) {
		return std::shared_ptr<GUIButton>( new GUIButton(surf, std::bind(func, object)) );
	}
}

#endif // GUIBUTTON_HPP
