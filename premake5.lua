workspace "Networking Authenticator"
	architecture "x64"
	startproject "Authenticator" 

	configurations {
		"Debug",
		"Release"
	}

solutionDir = "%{wks.location}/"
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDirs = {}
includeDirs["SPDLOG"] = "Authenticator/vendor/SPDLOG/include"
includeDirs['MYSQL'] = "Authenticator/vendor/MYSQL/" .. outputdir .. "/include"
includeDirs["PROTOBUFF"] = "Authenticator/vendor/ProtoBuff/" .. outputdir .. "/include"
includeDirs["PROTOS"] = "Authenticator/vendor/ProtoBuff/Protos_Build"
includeDirs["TWONET"] = "Authenticator/vendor/TwoNet/include"
includeDirs["OPENSSL"] = "Authenticator/vendor/OpenSSL/include"

libraryDirs = {}
libraryDirs['PROTOBUFF'] = "Authenticator/vendor/ProtoBuff/" .. outputdir .. "/lib"
libraryDirs['MYSQL'] = "Authenticator/vendor/MYSQL/" .. outputdir .. "/lib64/vs14"
libraryDirs["TWONET"] = "Authenticator/vendor/TwoNet/lib/" .. outputdir
libraryDirs["OPENSSL"] = "Authenticator/vendor/OpenSSL/lib"

include "Authenticator/vendor/TwoNet"
include "Authenticator"
include "Chat_Server"
include "Chat_Client"
