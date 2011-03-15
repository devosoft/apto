SET(APTO_CORE_SOURCES)

SET(CORE_DIR ${PROJECT_SOURCE_DIR}/unittests/core)
SET(CORE_SOURCES
  ${CORE_DIR}/Array.cc
  ${CORE_DIR}/ArrayUtils.cc
  ${CORE_DIR}/ConditionVariable.cc
  ${CORE_DIR}/FileSystem.cc
  ${CORE_DIR}/List.cc
  ${CORE_DIR}/Map.cc
  ${CORE_DIR}/Mutex.cc
  ${CORE_DIR}/Pair.cc
  ${CORE_DIR}/RWLock.cc
  ${CORE_DIR}/Set.cc
  ${CORE_DIR}/SmartPtr.cc
  ${CORE_DIR}/String.cc
  ${CORE_DIR}/StringBuffer.cc
  ${CORE_DIR}/Thread.cc
  ${CORE_DIR}/ThreadSpecific.cc
)
SOURCE_GROUP(unittests\\core FILES ${CORE_SOURCES})
LIST(APPEND APTO_CORE_SOURCES ${CORE_SOURCES})

SET(PLATFORM_DIR ${PROJECT_SOURCE_DIR}/unittests/platform)
SET(PLATFORM_SOURCES
  ${PLATFORM_DIR}/FloatingPoint.cc
)
SOURCE_GROUP(unittests\\platform FILES ${PLATFORM_SOURCES})
LIST(APPEND APTO_CORE_SOURCES ${PLATFORM_SOURCES})

SET(STAT_DIR ${PROJECT_SOURCE_DIR}/unittests/stat)
SET(STAT_SOURCES
  ${STAT_DIR}/ContingencyTable.cc
  ${STAT_DIR}/Functions.cc
)
SOURCE_GROUP(unittests\\stat FILES ${STAT_SOURCES})
LIST(APPEND APTO_CORE_SOURCES ${STAT_SOURCES})

INCLUDE_DIRECTORIES(../include ../utils/unittest/googletest/include)

ADD_EXECUTABLE(apto-test main.cc ${APTO_CORE_SOURCES})
TARGET_LINK_LIBRARIES(apto-test aptoshared gtest)
