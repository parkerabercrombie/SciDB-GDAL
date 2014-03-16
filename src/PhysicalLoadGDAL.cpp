/**
 * Physical operator interface for the SciDB GDAL loader.
 *
 * Copyright (c) 2014 Parker Abercrombie
 *
 * Distributed under the MIT License. (See accompanying file LICENSE
 * or copy at http://opensource.org/licenses/MIT)
 */

// std
#include <string>

// boost
#include <boost/shared_ptr.hpp>

// scidb
#include <query/Operator.h>

class PhysicalLoadGDAL: public scidb::PhysicalOperator
{
public:
  PhysicalLoadGDAL(const std::string& logicalName,
		   const std::string& physicalName,
		   const Parameters& parameters,
		   const scidb::ArrayDesc& schema):
      scidb::PhysicalOperator(logicalName, physicalName, parameters, schema)
    { }

    boost::shared_ptr<scidb::Array> execute(vector< boost::shared_ptr<scidb::Array> >& inputArrays,
					    boost::shared_ptr<scidb::Query> query)
    {
      return boost::shared_ptr<scidb::Array>();
    }
};

namespace scidb
{
    REGISTER_PHYSICAL_OPERATOR_FACTORY(PhysicalLoadGDAL, "load_gdal", "load_gdal_impl");
}
