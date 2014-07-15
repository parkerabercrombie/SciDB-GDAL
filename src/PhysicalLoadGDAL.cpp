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

#include <gdal_priv.h>

#include <log4cxx/logger.h>

using namespace scidb;

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
	LOG4CXX_DEBUG(log4cxx::Logger::getRootLogger(), "XXXXXXXXXXXXXXXX execute ");

	InstanceID instanceId = query->getInstanceID();
	ostringstream outputString;
	outputString << "Hello, World! this is instance " << instanceId;

	boost::shared_ptr<Array> outputArray(new MemArray(_schema, query));
	
	boost::shared_ptr<ArrayIterator> outputArrayIter = outputArray->getIterator(0);

	Coordinates position(1, instanceId);
	shared_ptr<ChunkIterator> outputChunkIter = outputArrayIter->newChunk(position).getIterator(query, 0);
	outputChunkIter->setPosition(position);

	Value value;
	value.setString(outputString.str().c_str());
	outputChunkIter->writeItem(value);
	outputChunkIter->flush();

	return outputArray;
    }
};

namespace scidb
{
    REGISTER_PHYSICAL_OPERATOR_FACTORY(PhysicalLoadGDAL, "load_gdal", "load_gdal_impl");
}
