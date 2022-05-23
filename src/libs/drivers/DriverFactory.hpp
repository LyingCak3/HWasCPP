
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

using DriverFactory = factory::GenericFactory<DriverInterface>;

}

}

#endif
