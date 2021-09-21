cmake_minimum_required(VERSION 3.3)
project(algorithms-templates)  

# List of flags to enhance compiler warnings for c and c++ to make sure there are no outstanding warnings
set(CMAKE_C_FLAGS "-g -std=gnu99 -Wall -Wextra -Wuninitialized \
	-Wunused-variable -Wdouble-promotion -Wmissing-prototypes \
	-Wmissing-declarations -Werror=undef -Wno-unused-function ${CMAKE_C_FLAGS}")

set(CMAKE_CXX_FLAGS "-g -std=gnu++11 -Wall -Wextra -Wuninitialized \
	-Wunused-variable -Wdouble-promotion \
	-Wmissing-declarations -Werror=undef -Wno-unused-function ${CMAKE_CXX_FLAGS}")

# looks for all c/c++ source files in algorithms directory
file(GLOB algorithm_files "algorithms/*.c*")
add_executable(algorithms_main main.cpp ${algorithm_files})


include_directories(
        include/
        )


install (
        TARGETS                 algorithms_main
        LIBRARY                 DESTINATION /usr/lib
        RUNTIME                 DESTINATION /usr/bin
        PUBLIC_HEADER           DESTINATION /usr/inlcude
)
