# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\EDRH_m_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EDRH_m_autogen.dir\\ParseCache.txt"
  "EDRH_m_autogen"
  )
endif()
