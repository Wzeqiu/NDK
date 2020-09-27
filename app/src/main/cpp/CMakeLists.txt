# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.


# 第一个参数是so库的名字
# 第二个参数是要生成的so库的类型，静态so库是STATIC 链接的源码一并打包,共享so库是SHARED 程序运行时被链接的
# 第三个参数是C/C++源文件，可以包括多个源文件

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# find_library函数用来从NDK目录下面查找特定的so库
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

# target_link_libraries函数用来把要生成的so库和依赖的其它so库进行链接，生成我们需要的so库文件

# 第一个参数是我们要生成的so库的名字去掉前缀和后缀后的名字
# 第二个参数是链接我们用find_library函数定义的查找的依赖库的名字log-lib，语法就是${依赖的库的名字}
target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )