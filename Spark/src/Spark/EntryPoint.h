#pragma once

#ifdef SPARK_PLATFORM_WINDOWS
	extern Spark::App* Spark::CreateApp();

	int main(int argc, char** argv) {
		auto app = Spark::CreateApp();

		app->Run();
		delete app;
	}
#endif