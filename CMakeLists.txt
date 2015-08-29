project(PROGRESSBAR_FOR_A_MORE_CIVILIZED_AGE)
cmake_minimum_required(VERSION 2.8.5)


###############################################################################
# Using Clang is awesome
# code based on http://stackoverflow.com/q/7031126
###############################################################################
option(USE_CLANG "build application with clang" ON) # OFF is the default
option(CMAKE_BUILD_TYPE "build type" Slow) # to show the progress
if(USE_CLANG)
  SET (CMAKE_C_COMPILER             "/usr/bin/clang")
  SET (CMAKE_C_FLAGS                "-Wall -Wextra -std=c99")
  SET (CMAKE_C_FLAGS_DEBUG          "-g")
  SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
  SET (CMAKE_C_FLAGS_RELEASE        "-O3 -DNDEBUG")
  SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")
  SET (CMAKE_C_FLAGS_SLOW           "-O0")

  SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
  SET (CMAKE_CXX_FLAGS                "-Wall -Wextra -std=c++11")
  SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
  SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
  SET (CMAKE_CXX_FLAGS_SLOW           "-O0")
else(USE_CLANG)
  SET (CMAKE_C_COMPILER             "/usr/bin/gcc")
  SET (CMAKE_C_FLAGS                "-Wall -Wextra -std=c99")
  SET (CMAKE_C_FLAGS_DEBUG          "-g")
  SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
  SET (CMAKE_C_FLAGS_RELEASE        "-O3 -DNDEBUG")
  SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")
  SET (CMAKE_C_FLAGS_SLOW           "-O0")

  SET (CMAKE_CXX_COMPILER             "/usr/bin/g++")
  SET (CMAKE_CXX_FLAGS                "-Wall -Wextra -std=c++11")
  SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
  SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
  SET (CMAKE_CXX_FLAGS_SLOW           "-O0")
endif(USE_CLANG)



###############################################################################
# Headers
###############################################################################
# for header-only libraries, this is enough :)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


###############################################################################
# Build executables
###############################################################################
add_executable(ProgressBarExample examples/progressbar_example.cc)

###############################################################################
# Custom targets
###############################################################################

# DOXYGEN
find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  message(fatal_error " Doxygen executable: " ${DOXYGEN_EXECUTABLE})
  add_custom_target(doc
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif(DOXYGEN_FOUND)
