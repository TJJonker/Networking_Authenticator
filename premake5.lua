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

libraryDirs = {}

include "Authenticator"
