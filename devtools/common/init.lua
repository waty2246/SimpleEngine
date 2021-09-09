require "vstudio"

newoption
{
	trigger = "location_path",
	description = "Output generated project files",
	value = "path"
}

function string.startsWith(str,pattern)
	return str:sub(1,#pattern) == pattern
 end
 
 function string.endsWith(str,pattern)
	return str:sub(#str - #pattern + 1,#str) == pattern
 end
 
 function GetAction()
	return _ACTION
end

function GetOptions(key)
	return _OPTIONS[key]
end

if GetAction()<"vs2017" then
	print("Please use visual studio 2017 or above to generate project files !!!")
	os.exit()
end

function GetLocationPath()
	local locationPath = GetOptions("location_path")
	if locationPath ~=nil then
		if not locationPath:endsWith("/") then
			locationPath = locationPath .. "/"
		end
	end
	return _MAIN_SCRIPT_DIR .. "/" .. (locationPath or "_/")
end

cppdialect "c++17"
buildoptions "/std:c++17"

system "windows"

staticruntime "On"

defines
{
	"WIN32_LEAN_AND_MEAN"
}

flags 
{
	"FatalWarnings",
	"NoPCH",
}

platforms
{
	"x64",
}

configuration "Debug*"
	symbols "on"
	defines { "_DEBUG"}
	targetsuffix "_d"

configuration "*Release*"
	defines { "NDEBUG"}
	optimize "on"
	
configuration {}