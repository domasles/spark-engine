#pragma once

#ifdef SPARK_PLATFORM_WINDOWS
	extern Spark::App* Spark::createApp();

	int main(int argc, char** argv) {
		Spark::Log::init();

		SPARK_CORE_WARN("Initialized the core logger.");
		SPARK_CLIENT_INFO("Initialized the client logger.");

		auto app = Spark::createApp();

		app->run();
		delete app;
	}
#endif
