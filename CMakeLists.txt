PROJECT(APTO CXX)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# A CMake Policy involving the use of shared libraries on OS X
# was introduced.  To avoid a warning, we must explicitly state
# whether or not to use this new feature.  Arbitrarily, I am
# deciding to enable it.
CMAKE_POLICY(SET CMP0042 NEW) 

INCLUDE(CMakeDependentOption)

# Default location for installed software/configs/ docs is the build directory.
SET(CMAKE_INSTALL_PREFIX
  "${PROJECT_BINARY_DIR}"
  CACHE PATH
  "Install path prefix, prepended onto install directories."
  FORCE
)

# Final software is built directly into the work subdirectory.
SET(EXECUTABLE_OUTPUT_PATH
  "${PROJECT_BINARY_DIR}/bin"
  CACHE PATH
  "Single output directory for building all executables."
)

SET(LIBRARY_OUTPUT_PATH
  "${PROJECT_BINARY_DIR}/lib"
  CACHE PATH
  "Built libraries are placed here before installation."
)


IF(UNIX)
  IF(EMSCRIPTEN)
    SET(MAX_OPT -O2)
  ELSE(EMSCRIPTEN)
    SET(MAX_OPT -O3)
  ENDIF(EMSCRIPTEN)

  SET(CMAKE_CXX_FLAGS_DEBUG
    "-g -DDEBUG"
    CACHE STRING "Flags used by the compiler during debug builds." FORCE)
  SET(CMAKE_CXX_FLAGS_MINSIZEREL
    "-Os -DNDEBUG"
    CACHE STRING "Flags used by the compiler during release minsize builds." FORCE)
  SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO
     "-O${MAX_OPT} -g -DDEBUG"
    CACHE STRING "Flags used by the compiler during release builds." FORCE)
  SET(CMAKE_CXX_FLAGS_RELEASE
     "-O${MAX_OPT} -DNDEBUG"
    CACHE STRING "Flags used by the compiler during release builds." FORCE)
ENDIF(UNIX)

# Default build mode compiles c++ and c code with debug info and no
# optimizations.
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE
    Release
    CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
    FORCE
  )
ENDIF(NOT CMAKE_BUILD_TYPE)


ADD_SUBDIRECTORY(src)

INSTALL(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include FILES_MATCHING PATTERN "*.h")

OPTION(APTO_UNIT_TESTS
   "Enable the unit-tests executable"
   ON
   )
IF (EMSCRIPTEN)
   SET(APTO_UNIT_TESTS OFF)
ENDIF(EMSCRIPTEN)

IF(APTO_UNIT_TESTS)
   ADD_SUBDIRECTORY(utils/unittest/googletest)
   ADD_SUBDIRECTORY(unittests)
ENDIF(APTO_UNIT_TESTS)

