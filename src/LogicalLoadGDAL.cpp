/**
 * Logical operator interface for the SciDB GDAL loader.
 *
 * Copyright (c) 2014 Parker Abercrombie
 *
 * Distributed under the MIT License. (See accompanying file LICENSE
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <SciDBAPI.h>
#include <query/Operator.h>
#include <log4cxx/logger.h>

#include <query/FunctionDescription.h>
#include <query/FunctionLibrary.h>
#include <query/Operator.h>
#include <query/TypeSystem.h>

using namespace scidb;

static log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("scidb.loadgdal"));

class LogicalLoadGDAL: public scidb::LogicalOperator
{
public:
    LogicalLoadGDAL(const std::string &logicalName, const std::string &alias):
        LogicalOperator(logicalName, alias)
    {
        ADD_PARAM_CONSTANT("string"); // Raster file path
    }

    scidb::ArrayDesc inferSchema(std::vector<scidb::ArrayDesc> schemas,
				 boost::shared_ptr<scidb::Query> query)
    {
        if (schemas.size() != 0) {
            throw SYSTEM_EXCEPTION(scidb::SCIDB_SE_INFER_SCHEMA,
                                   scidb::SCIDB_LE_ARRAY_ALREADY_EXIST) << "input array";
        }

        const std::string &filePath = evaluate(((boost::shared_ptr<OperatorParamLogicalExpression>&)_parameters[0])->getExpression(), query, TID_STRING).getString();
        LOG4CXX_DEBUG(logger, "XXXXXXXXXXXXXXXX infer schema " << filePath);

        AttributeDesc outputAttribute(0, "instance_status", TID_STRING, 0, 0);
        Attributes outputAttributes(1, outputAttribute);

        outputAttributes = addEmptyTagAttribute(outputAttributes);

        DimensionDesc outputDimension("instance_no", 0, MAX_COORDINATE, 1, 0);
        Dimensions outputDimensions(1, outputDimension);

        return scidb::ArrayDesc("hello_instances", outputAttributes, outputDimensions);
    }
};

namespace scidb
{
    REGISTER_LOGICAL_OPERATOR_FACTORY(LogicalLoadGDAL, "load_gdal");
}
