#ifndef SPRITE_H
#define SPRITE_H
#include <string>

namespace mcDirr {
	class Sprite {
		public:
			Sprite(std::string mess);
			virtual void tick(int timeDiff);
			virtual void const draw();

			virtual ~Sprite();

		protected:

		private:
			std::string msg;
	};
}
#endif // SPRITE_H
