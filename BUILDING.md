## Building

### Linux
Build release: `./build.sh release`

Build debug: `./build.sh debug`

You may need to install one or all of the following packages before you can successfully build:

```
build-essential
libgtk-3-dev
freeglut3-dev
libx11-dev
```


NOTE: To generate compile_commands.json for clangd, add `-c` to build command:

`./build.sh debug -c` or `./build.sh release -c`

### Windows:
Run `build.bat`. Visual Studio project should start automatically. Select the type of build (Debug or Release) and build the project.