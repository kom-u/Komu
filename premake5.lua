workspace "Komu"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Komu"
    location "Komu"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
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
        "Komu/vendor/spdlog/include",
        "Komu/src"
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