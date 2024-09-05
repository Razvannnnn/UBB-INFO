# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TESTQT_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TESTQT_autogen.dir\\ParseCache.txt"
  "TESTQT_autogen"
  )
endif()
