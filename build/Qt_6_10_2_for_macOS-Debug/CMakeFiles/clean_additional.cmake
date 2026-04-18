# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CloudOptima_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CloudOptima_autogen.dir/ParseCache.txt"
  "CloudOptima_autogen"
  )
endif()
