#ifndef GUITEXTFIELD_HPP
#define GUITEXTFIELD_HPP

#include <memory>
#include <string>

#include <SDL.h>
#include <SDL_ttf.h>

#include "GUIText.hpp"

namespace mcDirr {

	class GUITextField : public GUIText {

		public:
			static std::shared_ptr<GUITextField> getInstance(TTF_Font* font, const SDL_Color& color, int width);

			virtual void draw() const override;
			virtual void tick(int ) override;
			virtual void mouseClick() override;
			void setFocused(bool focs);

			void setX(int x) override;
			void setY(int y) override;
			void setWidth(int w) override;
			void setHeight(int h) override;

			virtual ~GUITextField();

		protected:
			GUITextField(TTF_Font* font, const SDL_Color& color, int width);
			void updateText() override;

		private:
			bool focus = false;
			SDL_Rect textDest;
	};
}

#endif // GUITEXTFIELD_HPP