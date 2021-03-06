# Try to find the SciDB installation.
#
# Defines:
#   SCIDB_FOUND - System has SciDB
#   SCIDB_INCLUDE_DIRS - SciDB header file directories
#
# Copyright (c) 2014 Parker Abercrombie
#
# Distributed under the MIT License. (See accompanying file LICENSE
# or copy at http://opensource.org/licenses/MIT)

# Find SciDBAPI.h
find_path(SCIDB_INCLUDE_DIR
  NAMES
    SciDBAPI.h
  PATH_SUFFIXES
    scidb/$ENV{SCIDB_VER}/include
  PATHS
    /opt
)

# Find SciDB plugin directory.
# TODO: can we do this without needing to assume that certain plugin is present?
find_path(SCIDB_PLUGIN_DIR
  NAMES
    libmpi.so
  PATH_SUFFIXES
    scidb/$ENV{SCIDB_VER}/lib/scidb/plugins
  PATHS
    /opt
)

set(SCIDB_INCLUDE_DIRS ${SCIDB_INCLUDE_DIR})
#set(SCIDB_PLUGINS_DIRS ${SCIDB_PLUGIN_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SciDB DEFAULT_MSG SCIDB_INCLUDE_DIR)

mark_as_advanced(SCIDB_INCLUDE_DIR)
