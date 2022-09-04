--* Module to export JSON Compile-Commands
require("vendor/premake-export-compile-commands/export-compile-commands")

--* important folder paths
rootDir = path.getabsolute(".")
outDir = rootDir .. "/build/"

binDir = outDir .. "/bin"
tmpDir = outDir .. "/tmp"
prjDir = outDir .. "/projects"

srcDir = rootDir .. "/src"
incDir = rootDir .. "/include"
testDir = rootDir .. "/test"

--* container for all projects
workspace "hCL"

  language "C++"
  cppdialect "C++20"

  --* output locations
  location(prjDir)
  objdir(tmpDir .. "/%{prj.name}/%{cfg.buildcfg}")
  targetdir(binDir .. "/%{cfg.buildcfg}")

  configurations {
    "debug",
    "release"
  }

  --* os specific settings
  if (os.target() == "macosx") then
    architecture "Universal"
  else
    architecture "x64"
  end

  --* common compilation and linkage flags
  warnings "Extra"
  visibility "Hidden"

  flags {
    "FatalWarnings",
    "RelativeLinks",
    "MultiProcessorCompile",
    "Maps",
    "LinkTimeOptimization"
  }

  filter "configurations:release"
    symbols "Off"
    optimize "Full"
    runtime "Release"

  filter "configurations:debug"
    defines {"DEBUG"}
    symbols "On"
    optimize "Off"
    runtime "Debug"
  filter {}

--* Add test project
dofile("test/premake5.lua")
