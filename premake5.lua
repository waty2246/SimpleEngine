require("common")

local myPath = _MAIN_SCRIPT_DIR .. "/"
local myName = "SimpleEngine"

workspace(myName)
	location(GetLocationPath())
	filename("_" .. myName)
    startproject(myName)
	
	configurations
	{
		"DebugDirectX12",
		"ReleaseDirectX12",
		"DebugDirectX11",
		"ReleaseDirectX11",
		"DebugOpenGL",
		"ReleaseOpenGL",
		"DebugVulkan",
		"ReleaseVulkan",
	}
	
	configuration "*DirectX11"
		defines { "GRAPHICS_DIRECTX11"}
	configuration "*DirectX12"
		defines { "GRAPHICS_DIRECTX12"}
	configuration "*OpenGL"
		defines { "GRAPHICS_OPENGL"}
	configuration "*Vulkan"
		defines { "GRAPHICS_VULKAN"}
	configuration {}
	
	project(myName)
		kind "WindowedApp"
		location(GetLocationPath())
		language "C++"
		
		entrypoint "WinMainCRTStartup"
		
		files
		{
			myPath .. "src/**",
			myPath .. "premake5.lua",
			myPath .. "devtools/**.lua",
			myPath .. "README.md",
		}
		
		filter "files:**hlsl"
			shadermodel "5.1"
			shaderobjectfileoutput "%%(Filename).cso"
		filter { "files:**_ps.hlsl" }
		   shadertype "Pixel"
		   shaderentry "main"
		filter { "files:**_vs.hlsl" }
		   shadertype "Vertex"
		   shaderentry "main"
		filter {}
		
		vpaths
		{
			["premake"] = { "**.lua" },
			["docs"]	= {"**.md"},
		}

		includedirs
		{
			myPath .. "src/",
		}
		
		links
		{
			-- misssing linking to directx11, opengl, vulkan here !!!
			"d3d12.lib",
			"dxgi.lib",
			"d3dcompiler.lib",
		}