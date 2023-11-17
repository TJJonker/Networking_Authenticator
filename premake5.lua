workspace "Networking Authenticator"
	architecture "x64"
	startproject "Authenticator" 

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

solutionDir = "%{wks.location}/"
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDirs = {}
includeDirs["SPDLOG"] = "Authenticator/vendor/SPDLOG/include"
includeDirs['MYSQL'] = "Authenticator/vendor/MYSQL/" .. outputdir .. "/include"

libraryDirs = {}
libraryDirs['MYSQL'] = "Authenticator/vendor/MYSQL/" .. outputdir .. "/lib64/vs14"

include "Authenticator"
