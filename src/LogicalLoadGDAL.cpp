
#include <query/Operator.h>

class LogicalLoadGDAL: public scidb::LogicalOperator
{
public:
    LogicalLoadGDAL(const std::string &logicalName, const std::string &alias):
        LogicalOperator(logicalName, alias)
    {
        ADD_PARAM_CONSTANT("string"); // Raster file path
    }

    ArrayDesc inferSchema(std::vector<ArrayDesc> schemas, boost::shared_ptr<Query> query)
    {
        if (s.size() != 0) {
            throw SYSTEM_EXCEPTION(
                                   scidb::SCIDB_SE_INFER_SCHEMA,
                                   scidb::SCIDB_LE_ARRAY_ALREADY_EXISTS) << "input array";
        }


        return ArrayDesc();
    }

};

REGISTER_LOGICAL_OPERATOR_FACTORY(LogicalLoadGDAL, "load_gdal");
