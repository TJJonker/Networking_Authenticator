project "TwoNet"
	kind "StaticLib"
	language "C++"

	targetdir ("lib/" .. outputdir)
	objdir ("bin-int/" .. outputdir)

	pchheader "tpch.h"
	pchsource "src/tpch.cpp" 

	files
	{
		"src/**.cpp",
		"include/TwoNet/**.h"
	}

	includedirs {
		"include/TwoNet"
	}

	defines { }

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "Off"

	filter "configurations:Debug"
		symbols "On"
	
