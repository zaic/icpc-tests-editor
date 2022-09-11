# icpc-tests-editor

GUI-based test editor for competitive programming tasks.

# How to build

## Prerequisites

First, you need modern c++ compiler with c++20 standard support.

Then, project use [cmake](https://cmake.org/) in build process, which is also required.

And last, install [conan](https://conan.io/) package manager. Usually `pip install conan` is enough. But you do better to read docs if have never heard about it before.

## Compilation

Install third party dependencies using conan:

* `cd build`
* `conan install .. --build=missing -s build_type=Release`

For debugging you can also install debug library versions:

* `conan install .. --build=missing -s build_type=Debug`

Generate project build files using cmake:

* `cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake`

Probably (on Windows), you need to add some specific options and specify generator:

* `cmake .. -G "Visual Studio 17" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake`

Now you can compile the project:

* `cmake --build . --config Release`
