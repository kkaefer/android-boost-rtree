# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

add_library(native-lib SHARED
    src/main/cpp/native-lib.cpp
)

target_include_directories(native-lib SYSTEM
    PRIVATE libs/boost_1_63_0
)
