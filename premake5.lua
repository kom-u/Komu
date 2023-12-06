workspace "Komu"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Komu/vendor/glfw/include"

include "Komu/vendor/glfw"

project "Komu"
    location "Komu"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "kmpch.h"
    pchsource "%{prj.name}/src/kmpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links 
	{ 
		"GLFW",
		"opengl32.lib",
        "dwmapi.lib",
        "gdi32.lib",
        "user32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "KM_PLATFORM_WINDOWS",
            "KM_BUILD_DLL",
        }

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

    filter "configurations:Debug"
        defines "KM_DEBUG"
        symbols "On"


    filter "configurations:Release"
        defines "KM_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KM_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Komu/src",
        "Komu/vendor/spdlog/include"
    }

    links
    {
        "Komu"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "KM_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "KM_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KM_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KM_DIST"
        optimize "On"
