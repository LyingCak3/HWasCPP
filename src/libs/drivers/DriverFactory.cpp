
#include "DriverFactory.hpp"

kac::cudalearn::DriverFactory& kac::cudalearn::DriverFactory::GetFactory()
{
    static kac::cudalearn::DriverFactory factory;
    return factory;
}
