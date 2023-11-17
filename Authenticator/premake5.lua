project "Authenticator"
	kind "ConsoleApp"
	language "C++"

	targetdir (solutionDir .. "/bin/" .. outputdir .. "/%{prj.name}")
	objdir (solutionDir .. "/bin-int/" .. outputdir .. "/%{prj.name}")

	-- pchheader "pch.h"
	-- pchsource "src/pch.cpp" 

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src"
	}

	libdirs {
	}

	links {
	}


	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "on"

		defines {
		}

		prebuildcommands {
		}

		postbuildcommands {
		}


	filter "configurations:Debug"
		defines "VOID_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VOID_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VOID_DIST"
		optimize "On"
	
