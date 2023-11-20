#include "TwoNet/tpch.h"

#ifdef TWONET_DEBUG
#include "spdlog/sinks/stdout_color_sinks.h"
#include "TwoNet/Debug/Log.h"

namespace TwoNet {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("TWONET");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
}
#endif