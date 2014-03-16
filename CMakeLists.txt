#########################################################
# SciDB-GDAL
#
# Copyright (c) 2014 Parker Abercrombie
#
# Distributed under the MIT License. (See accompanying file LICENSE
# or copy at http://opensource.org/licenses/MIT)
#########################################################

cmake_minimum_required(VERSION 2.6)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(LoadGDAL_VERSION_MAJOR 1)
set(LoadGDAL_VERSION_MINOR 0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")

find_package(SciDB REQUIRED)

# Use the version of Boost provided by SciDB
set(BOOST_ROOT /opt/scidb/13.12/3rdparty/boost)

# TODO need to find Boost relative to SciDB, don't use hard coded path
set(Boost_NO_SYSTEM_PATHS TRUE)
set(Boost_NO_BOOST_CMAKE TRUE)

find_package(GDAL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

include_directories(
  ${Boost_INCLUDE_DIRS}
  ${SCIDB_INCLUDE_DIRS}
  ${GDAL_INCLUDE_DIRS}
)

add_subdirectory("src")
