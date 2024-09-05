# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PracticTractoare_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PracticTractoare_autogen.dir\\ParseCache.txt"
  "PracticTractoare_autogen"
  )
endif()
