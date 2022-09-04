--* test project
project "hCL-test"

  kind "ConsoleApp"

  location(prjDir .. "/%{prj.name}")

  externalincludedirs {
    rootDir .. "/vendor/googletest/googletest/include",
    rootDir .. "/vendor/googletest/googletest"
  }

  includedirs {
    incDir,
    testDir .. "/include",
    --* These two added for compile_commands.json, otherwise externalincludedirs silences their warnings.
    rootDir .. "/vendor/googletest/googletest/include",
    rootDir .. "/vendor/googletest/googletest"
  }

  files {
      incDir .. "/**",
      testDir .. "/**.cpp",
      testDir .. "/**.hpp",
      rootDir .. "/vendor/googletest/googletest/src/gtest-all.cc"
  }

  --* precompiled header
  pchsource(testDir .. "/pch.cpp")
  pchheader("pch.hpp")

  vpaths {
    ["Import/*"] = incDir .. "/**",
    ["Sources/*"] = testDir .. "/**.cpp",
    ["Headers/*"] = testDir .. "/**.hpp",
    ["GoogleTest/*"] = rootDir .. "/vendor/googletest/googletest/**"
  }
