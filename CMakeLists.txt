project(elegant-progressbar-for-a-more-civilized-age-dev)
cmake_minimum_required(VERSION 3.0.2)


###############################################################################
# Using Clang is awesome
# code based on http://stackoverflow.com/q/7031126
###############################################################################
string(FIND ${CMAKE_CXX_COMPILER} "clang++" CXX_COMPILER_IS_CLANG++)
string(FIND ${CMAKE_CXX_COMPILER} "g++" CXX_COMPILER_IS_G++)

option(CMAKE_BUILD_TYPE "build type" Slow) # to show the progress

if(${CXX_COMPILER_IS_CLANG++})  
  SET (CMAKE_CXX_FLAGS                "-Wall -Wextra -std=c++11")
  SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
  SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
  SET (CMAKE_CXX_FLAGS_SLOW           "-O0")
endif(${CXX_COMPILER_IS_CLANG++})
  
if(${CXX_COMPILER_IS_G++})  
  SET (CMAKE_CXX_FLAGS                "-Wall -Wextra -std=c++11")  
  SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
  SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
  SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
  SET (CMAKE_CXX_FLAGS_SLOW           "-O0")
endif(${CXX_COMPILER_IS_G++})  

###############################################################################
# Progressbar for a More Civilized Age Config
###############################################################################
# for header-only libraries, this is enough :)
find_package(elegant-progressbar-for-a-more-civilized-age 1.0.0 REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR})

###############################################################################
# Build executables
###############################################################################
add_executable(ProgressBarExample examples/progressbar_example.cpp)

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
