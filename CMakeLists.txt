cmake_minimum_required(VERSION 3.10)

project(ada-example CXX)

find_package(ada CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC_USE_STATIC_CRT)
    if(MSVC)
        foreach(flag_var
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if(${flag_var} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
            endif(${flag_var} MATCHES "/MD")
        endforeach(flag_var)
    endif()
endif()

add_executable(pctutil pctutil.cpp)
target_compile_features(pctutil INTERFACE cxx_std_17)
if(MSVC)
    target_compile_options(pctutil PRIVATE /utf-8)
endif()
target_link_libraries(pctutil PRIVATE ada::ada)
