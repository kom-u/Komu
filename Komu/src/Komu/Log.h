#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Komu
{
    class KOMU_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define KM_CORE_TRACE(...)    ::Komu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KM_CORE_INFO(...)     ::Komu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KM_CORE_WARN(...)     ::Komu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KM_CORE_ERROR(...)    ::Komu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KM_CORE_FATAL(...)    ::Komu::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define KM_TRACE(...)         ::Komu::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KM_INFO(...)          ::Komu::Log::GetClientLogger()->info(__VA_ARGS__)
#define KM_WARN(...)          ::Komu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KM_ERROR(...)         ::Komu::Log::GetClientLogger()->error(__VA_ARGS__)
#define KM_FATAL(...)         ::Komu::Log::GetClientLogger()->fatal(__VA_ARGS__)


