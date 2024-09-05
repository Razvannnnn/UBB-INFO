# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Elevi_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Elevi_autogen.dir\\ParseCache.txt"
  "Elevi_autogen"
  )
endif()
