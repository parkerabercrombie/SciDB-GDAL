
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
