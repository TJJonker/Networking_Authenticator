project "Chat_Client"
	kind "ConsoleApp"
	language "C++"
	dependson "TwoNet"
	staticruntime "off"

	targetdir (solutionDir .. "/bin/" .. outputdir .. "/%{prj.name}")
	objdir (solutionDir .. "/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "src/pch.cpp" 

	files
	{
		"src/**.cpp",
		"src/**.h"
	}

	includedirs {
		"src",
		solutionDir .. "%{includeDirs.TWONET}",
		solutionDir .. "%{includeDirs.SPDLOG}"
	}

	libdirs {
		solutionDir .. "%{libraryDirs.TWONET}"
	}

	links {
		"TwoNet.lib",
		"ws2_32.lib"
	}

	defines { }

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
		defines {
			"TWONET_DEBUG",
			"TWONET_ASSERT_ENABLED"
		}
	
