cmake_minimum_required(VERSION 3.10)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(ProjectName "fastapp")
set(Subsystem "CONSOLE")

set(VersionMajor 0)
set(VersionMinor 1)
set(VersionPatch 0)

project("${ProjectName}" VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MT")

#app executable
add_executable("${ProjectName}"
        #src files
        src/main.cpp
        #header files
)

target_compile_definitions("${ProjectName}" PUBLIC VERSION_MAJOR=${VersionMajor})
target_compile_definitions("${ProjectName}" PUBLIC VERSION_MINOR=${VersionMinor})
target_compile_definitions("${ProjectName}" PUBLIC VERSION_PATCH=${VersionPatch})
target_compile_definitions("${ProjectName}" PUBLIC APP_NAME="${ProjectName}")