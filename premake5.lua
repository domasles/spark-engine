outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "Spark"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

project "Spark"
    location "Spark"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs "%{prj.name}/vendor/spdlog/include"

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SPARK_PLATFORM_WINDOWS",
            "SPARK_BUILD_DLL"
        }

        buildoptions "/utf-8"
        
        postbuildcommands {
            "{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "SPARK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SPARK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SPARK_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Spark/vendor/spdlog/include",
        "Spark/src"
    }

    links "Spark"

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines "SPARK_PLATFORM_WINDOWS"
        buildoptions "/utf-8"
    
    filter "configurations:Debug"
        defines "SPARK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SPARK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SPARK_DIST"
        optimize "On"
