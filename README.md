# scample

Dabbling with C and [raylib](https://www.raylib.com/) on Windows.

## Pre-requisites

### Tools required

- MinGW build tools (contains gcc, g++ etc)
- Make
- CMake
- raylib

On Windows, Make and CMake can be installed from [scoop](https://scoop.sh/).

```
scoop install make cmake
```

### Setup raylib

raylib is required to build this project. Start off by cloning both `raylib` and `raygui` into anywhere on your system.

```
git clone https://github.com/raysan5/raylib
git clone https://github.com/raysan5/raygui
```

After that, change directory into `raylib/src`.

```
cd raylib/src
```

Run the `make` command to build the artifacts.

```
make
```

You should see a file named `libraylib.a` appeared in the directory. That's all you need to do.

## Installation

Clone this repository locally.

```
git clone https://github.com/data-miner00/scample
```

Go to `CMakeLists.txt` and update the path to raylib and raygui. Note that it needs to be at the `/src` subdirectory that contains the header files and the library file.

```
set(RAYLIB_PATH "<my-base-path>/raylib/src")
set(RAYGUI_PATH "<my-base-path>/raygui/src")
```

Create a build directory for store the artifacts generated by cmake.

```
mkdir build && cd build
```

Link the CMake file.

```
cmake ..
```

Build the artifacts.

```
cmake --build .
```

At this point, there should be a file named `scample.exe`

Simply run the file to see it in action.

```
./scample.exe
```

Alternatively, if you use Neovim with clangd as the lsp, you can copy the `compile_commands.json` file to the root file.

```
cp compile_commands.json ..
```

## References

- [Making a Desktop App with a Game Library](https://www.youtube.com/watch?v=KSKzaeZJlqk)