
#ifndef DriverFactory_hpp
#define DriverFactory_hpp

#include <map>
#include <memory>

#include "DriverInterface.hpp"
#include "GenericFactory.hpp"

namespace kac
{

namespace cudalearn
{

class DriverFactory : public factory::GenericFactory<DriverInterface>
{
public:

    static DriverFactory& GetFactory();

    DriverFactory( DriverFactory& ) = delete;
    DriverFactory( DriverFactory&& ) = delete;

    DriverFactory& operator=( DriverFactory& ) = delete;

private:

    DriverFactory() : factory::GenericFactory<DriverInterface>() {};

};

}

}

#endif
