# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Rochii_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Rochii_autogen.dir\\ParseCache.txt"
  "Rochii_autogen"
  )
endif()
