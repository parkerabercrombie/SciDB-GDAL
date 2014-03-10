###################################################################
# Cmake build file for SciDB GDAL loader.
#
# Copyright (c) 2014 Parker Abercrombie
#
# Distributed under the MIT License. (See accompanying file LICENSE
# or copy at http://opensource.org/licenses/MIT)
###################################################################

set(LoadGDAL_VERSION_MAJOR 1)
set(LoadGDAL_VERSION_MINOR 0)

# Shared library
set (plugin_src
    LogicalLoadGDAL.cpp
    PhysicalLoadGDAL.cpp
)
add_library(loadgdal SHARED ${plugin_src})
target_link_libraries(loadgdal ${GDAL_LIBRARIES} ${Boost_LIBRARIES})
