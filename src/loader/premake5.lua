--* main project that loads all backends.
project "hCL"

  kind "SharedLib"

  location(prjDir .. "/%{prj.name}")

  includedirs {
    incDir,
    srcDir .. "/loader/include",
  }

  files {
      incDir .. "/**",
      srcDir .. "/loader/**.cpp",
      srcDir .. "/loader/**.hpp",
  }

  --* precompiled header for everything not xcode (xcode doesn't find pch)
  filter "action:not xcode*"
    pchsource(srcDir .. "/pch.cpp")
    pchheader("pch.hpp")

  vpaths {
    ["Import/*"] = incDir .. "/**",
    ["Sources/*"] = srcDir .. "/loader/**.cpp",
    ["Headers/*"] = srcDir .. "/loader/**.hpp"
  }

  defines { "hCL_EXPORT_API" }
