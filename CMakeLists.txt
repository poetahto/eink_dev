cmake_minimum_required(VERSION 3.22)

# You must have the ESP-IDF devkit installed to build this project!
# https://docs.espressif.com/projects/esp-idf/en/latest/esp32/
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# "Trim" the build. Include the minimal set of components, main, and anything it depends on.
idf_build_set_property(MINIMAL_BUILD ON)

# NOTE(poe): I copied this build script from the hello-world example 
project(eink_dev)
