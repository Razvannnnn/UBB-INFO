# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Melodii1Practic_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Melodii1Practic_autogen.dir\\ParseCache.txt"
  "Melodii1Practic_autogen"
  )
endif()
