cmake_minimum_required(VERSION 3.22)

# You must have the ESP-IDF devkit installed to build this project!
# https://docs.espressif.com/projects/esp-idf/en/latest/esp32/
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# NOTE(poe): I copied this build script from the hello-world example 
project(eink_dev)
