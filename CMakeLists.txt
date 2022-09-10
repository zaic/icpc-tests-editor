cmake_minimum_required(VERSION 3.20)

set(QT_CREATOR_SKIP_CONAN_SETUP ON)
set(QT_CREATOR_SKIP_VCPKG_SETUP TRUE)
set(CMAKE_TOOLCHAIN_FILE build/conan_toolchain.cmake)

project(IcpcTestsEditor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
