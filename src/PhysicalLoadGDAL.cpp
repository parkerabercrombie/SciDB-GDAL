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

class PhysicalLoadGDAL: public PhysicalOperator
{
public:
    PhysicalLoadGDAL(const string& logicalName,
                     const string& physicalName,
                     const Parameters& parameters,
                     const ArrayDesc& schema):
        PhysicalOperator(logicalName, physicalName, parameters, schema);
    { }

    boost::shared_ptr<Array> execute(vector< boost::shared_ptr<Array> >& inputArrays,
                                     boost::shared_ptr<Query> query)
    {

    }
};

REGISTER_LOGICAL_OPERATOR_FACTORY(PhysicalLoadGDAL, "load_gdal");
