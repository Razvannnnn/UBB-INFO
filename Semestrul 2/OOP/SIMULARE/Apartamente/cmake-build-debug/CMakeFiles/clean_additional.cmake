# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Apartamente_autogen"
  "CMakeFiles\\Apartamente_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Apartamente_autogen.dir\\ParseCache.txt"
  )
endif()
