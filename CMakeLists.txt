cmake_minimum_required(VERSION 3.15)

# Set the project name to your project name, my project isn't very descriptive
project(gtkmm-base CXX)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Option specifications
option(ENABLE_TESTING "Enable Test Builds" ON)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

find_package(PkgConfig REQUIRED)
pkg_check_modules(gtkmm-3.0 REQUIRED gtkmm-3.0)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()

set(AUX_SOURCE
    src/MainApplication.cpp
    src/MainWindow.cpp
)

add_executable(sample src/main.cpp ${AUX_SOURCE})
target_include_directories(sample PUBLIC ./ ${gtkmm-3.0_INCLUDE_DIRS})

#${gtkmm-3.0_CFLAGS} ${gtkmm-3.0_CFLAGS_OTHER}
target_link_libraries(sample PRIVATE project_warnings project_options ${gtkmm-3.0_LIBRARIES} ${gtkmm-3.0_CFLAGS})

