
#ifndef DriverInterface_hpp
#define DriverInterface_hpp

#include <boost/program_options.hpp>

#include <vector>

namespace kac
{

namespace cudalearn
{

class DriverInterface
{

public:

    DriverInterface(){};

    ~DriverInterface(){};

    void virtual SetupArguments( boost::program_options::options_description& driverDesc ) = 0;

    void virtual ParseArguments( boost::program_options::variables_map& map ) = 0;

    void virtual Initialize() = 0;

    void virtual Execute() = 0;

    void virtual Finalize() = 0;

protected:

private:

};

}

}

#endif
