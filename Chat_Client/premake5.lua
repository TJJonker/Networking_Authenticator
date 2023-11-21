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
		"src/**.h",
		solutionDir .. "Authenticator/vendor/ProtoBuff/Protos_Build/**.cc",
		solutionDir .. "Authenticator/vendor/ProtoBuff/Protos_Build/**.h"
	}

	includedirs {
		"src",
		solutionDir .. "%{includeDirs.TWONET}",
		solutionDir .. "%{includeDirs.SPDLOG}",
		solutionDir .. "%{includeDirs.PROTOBUFF}",
		solutionDir .. "%{includeDirs.PROTOS}"
	}

	libdirs {
		solutionDir .. "%{libraryDirs.TWONET}",
		solutionDir .. "%{libraryDirs.PROTOBUFF}"
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
		
		links {
			"libprotobufd.lib"
		}
	
