workspace("oneninefourtwo")
    configurations { "debug", "release" }
    platforms({ "win64" })

    location("projects")
    objdir("tmp/%{prj.name}")

    filter({ "platforms:win64" })
        system("windows")
        architecture "x86_64"
    filter({ "configurations:release" })
        optimize("on")

    filter({})

    startproject("game")

project("game")
    location("projects/game")
    kind("ConsoleApp")
    language("C++")
    targetdir("bin/%{cfg.buildcfg}")
    debugdir("data")

    files({
        "source/**.h",
        "source/**.cpp"
    })

    vpaths({
        ["*"] = { "source/**.h", "source/**.cpp" }
    })

    links({ "sdl2", "sdl2main" })
    libdirs({ "extern/SDL2/lib/x64" })
    includedirs({ "source", "extern/SDL2/include" })
