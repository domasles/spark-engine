#pragma once

#ifdef SPARK_PLATFORM_WINDOWS
	#ifdef SPARK_BUILD_DLL
		#define SPARK_API __declspec(dllexport)
	#else
		#define SPARK_API __declspec(dllimport)
	#endif
#else
	#error Spark Engine currently works only on Windows!
#endif
