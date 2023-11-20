project "TwoNet"
	kind "StaticLib"
	language "C++"

	targetdir ("lib/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	pchheader "TwoNet/tpch.h"
	pchsource "src/tpch.cpp" 

	files
	{
		"src/**.cpp",
		"include/TwoNet/**.h"
	}

	includedirs {
		"include",
		solutionDir .. "%{includeDirs.SPDLOG}"
	}

	defines { }

	links {
		"ws2_32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "Off"

	filter "configurations:Debug"
		symbols "On"
		defines {
			"TWONET_DEBUG",
			"TWONET_ASSERT_ENABLED"
		}
	
