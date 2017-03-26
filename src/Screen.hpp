#ifndef SCREEN_HPP
#define SCREEN_HPP

namespace mcDirr {

	class Screen {

		public:
			Screen();

			virtual void tick(int millisPassed) = 0;
			virtual void draw() = 0;

			bool isFinished();

			virtual ~Screen();

		protected:
			bool finished = false;
	};
}

#endif // SCREEN_HPP
