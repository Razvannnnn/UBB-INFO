# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PracticProduse_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PracticProduse_autogen.dir\\ParseCache.txt"
  "PracticProduse_autogen"
  )
endif()
