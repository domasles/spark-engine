#pragma once

#include "Core.h"

namespace Spark {
	class SPARK_API App {
		public:
			App();
			virtual ~App();

			void run();
	};

	// NOTE: this function HAS to be defined in client apps

	App* createApp();
}
