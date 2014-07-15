###################################################################
# Cmake build file for SciDB GDAL loader.
#
# Copyright (c) 2014 Parker Abercrombie
#
# Distributed under the MIT License. (See accompanying file LICENSE
# or copy at http://opensource.org/licenses/MIT)
###################################################################

# Define the PROJECT_ROOT macro. The SciDB StringUtils header requires
# this macro to construct relative file paths.
set_property(DIRECTORY PROPERTY COMPILE_DEFINITIONS
  PROJECT_ROOT="${CMAKE_CURRENT_SOURCE_DIR}"
)

# Include the current directory in the path so that SciDB can find
# the MurmurHash header in the extern directory. This header is referenced
# via a relative path in Hashing.h, but is not included in the SciDB install.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Shared library
set (plugin_src
    LogicalLoadGDAL.cpp
    PhysicalLoadGDAL.cpp
)
add_library(loadgdal SHARED ${plugin_src})
target_link_libraries(loadgdal ${GDAL_LIBRARIES} ${Boost_LIBRARIES})

install(TARGETS loadgdal DESTINATION ${SCIDB_PLUGIN_DIR})
