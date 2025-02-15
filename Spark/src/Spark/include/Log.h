#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "Core.h"

namespace Spark {
	class SPARK_API Log {
		public:
			static void init();

			inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
			inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> coreLogger;
			static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

#define SPARK_CORE_TRACE(...) ::Spark::Log::getCoreLogger()->trace(__VA_ARGS__)
#define SPARK_CORE_INFO(...) ::Spark::Log::getCoreLogger()->info(__VA_ARGS__)
#define SPARK_CORE_WARN(...) ::Spark::Log::getCoreLogger()->warn(__VA_ARGS__)
#define SPARK_CORE_ERROR(...) ::Spark::Log::getCoreLogger()->error(__VA_ARGS__)
#define SPARK_CORE_FATAL(...) ::Spark::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define SPARK_CLIENT_TRACE(...) ::Spark::Log::getClientLogger()->trace(__VA_ARGS__)
#define SPARK_CLIENT_INFO(...) ::Spark::Log::getClientLogger()->info(__VA_ARGS__)
#define SPARK_CLIENT_WARN(...) ::Spark::Log::getClientLogger()->warn(__VA_ARGS__)
#define SPARK_CLIENT_ERROR(...) ::Spark::Log::getClientLogger()->error(__VA_ARGS__)
#define SPARK_CLIENT_FATAL(...) ::Spark::Log::getClientLogger()->fatal(__VA_ARGS__)
