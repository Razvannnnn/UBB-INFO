# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Practiccc_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Practiccc_autogen.dir\\ParseCache.txt"
  "Practiccc_autogen"
  )
endif()
