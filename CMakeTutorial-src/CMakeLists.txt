# -- TOP LEVEL CMakeLists.txt
cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# The version number for our project
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Mani
# -- Adding an option that user can choose when building this CMakeproject.
# -- should be in the top level header
# Should we use the MathFunctions library that we are going to build?
# This variable shows up in the GUI when you build this project using ccmake
option (USE_MYMATHFUNCTIONS "Use tutorial provided math implementation" ON) 

# Mani
# -- Configure a header file template to pass some of the CMake settings
#    to the source code. 
# - The first file (ending in .h.in) from the source folder should 
#   be considered like a template header file.
# - That will be specialized into an actual header file by the command 
#   'configure_file'. The idea is using CMake variables to do this.
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)
 
# Add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

if (USE_MYMATHFUNCTIONS)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)	# This will build the MathFunctions library
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions) 
endif (USE_MYMATHFUNCTIONS)

# Build your executable
add_executable(Tutorial tutorial.cxx)
target_link_libraries (Tutorial ${EXTRA_LIBS})


# -- NOTES
# 1. CMake variables that denote options are preceded by USE_
# 2. ${EXTRA_LIBS} is a variable that will be empty if  USE_MYMATHFUNCTIONS
#    is switched OFF when building this project. Nevertheless, the project will
#    still be built
