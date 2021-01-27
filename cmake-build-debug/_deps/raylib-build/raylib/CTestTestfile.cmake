# CMake generated Testfile for 
# Source directory: C:/Users/s200490/CLionProjects/default/cmake-build-debug/_deps/raylib-src/src
# Build directory: C:/Users/s200490/CLionProjects/default/cmake-build-debug/_deps/raylib-build/raylib
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(pkg-config--static "C:/Users/s200490/CLionProjects/default/cmake-build-debug/_deps/raylib-src/src/../cmake/test-pkgconfig.sh" "--static")
set_tests_properties(pkg-config--static PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/s200490/CLionProjects/default/cmake-build-debug/_deps/raylib-src/src/CMakeLists.txt;59;add_test;C:/Users/s200490/CLionProjects/default/cmake-build-debug/_deps/raylib-src/src/CMakeLists.txt;0;")
subdirs("external/glfw")
