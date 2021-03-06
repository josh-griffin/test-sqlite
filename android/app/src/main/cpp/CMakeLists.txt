# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

project("testsqlite")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
include_directories(
        ../../../../../node_modules/react-native/React
        ../../../../../node_modules/react-native/React/Base
        ../../../../../node_modules/react-native/ReactCommon/jsi
)

add_library(
        joshtest
        SHARED
         ../../../../../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
        ../../../../../cpp/sqlite3.h
        ../../../../../cpp/sqlite3.c
#        ../../../../../cpp/sqlite_adapter.cpp
        ../../../../../cpp/testjosh.cpp
)

# add_library(
#         sqlite
#         SHARED
#         sqlite3.c
# )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                        joshtest
        android
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )