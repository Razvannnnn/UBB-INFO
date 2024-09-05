# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\tractoare_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tractoare_autogen.dir\\ParseCache.txt"
  "tractoare_autogen"
  )
endif()
