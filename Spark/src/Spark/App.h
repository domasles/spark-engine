#pragma once

#include "Core.h"

namespace Spark {
	class SPARK_API App {
		public:
			App();
			virtual ~App();

			void Run();
	};

	// NOTE: this function HAS to be defined in client apps
	App* CreateApp();
}
