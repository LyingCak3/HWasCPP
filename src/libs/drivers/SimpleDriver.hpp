
#ifndef SimpleDriver_hpp
#define SimpleDriver_hpp

#include "DriverInterface.hpp"

namespace kac
{

namespace cudalearn
{

class SimpleDriver : public DriverInterface
{

public:

    SimpleDriver();

    ~SimpleDriver();

    void virtual SetupArguments( boost::program_options::options_description& driverDesc );

    void virtual ParseArguments( boost::program_options::variables_map& map );

    void virtual Initialize();

    void virtual Execute();

    void virtual Finalize();

};

}

}

#endif
