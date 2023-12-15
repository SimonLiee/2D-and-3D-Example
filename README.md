# Example of 2D and 3D

Project in [Raylib](https://www.raylib.com/) C. 

Example of how to compile to both 2D and 3D graphics without affecting or having to change game logic.

Had to cheat a bit to make the camera centered. Had to set a macro to compile camera position differently whether compiling for 2D or 3D.

## How to run

Compile with 2D graphics by running `make build_2D` in the base directory.

Compile with 3D graphics by running `make build_4D` in the base directory.

Should produce a binary file in bin named build_osx. Run binary with `./bin/build_osx`.

Alternatively compile and build with a single command `make build_and_run2D` or `make build_and_run3D`.

Builds for OSX. If running on another platform you might have to configure the build differently.
