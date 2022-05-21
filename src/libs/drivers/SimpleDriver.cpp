
#include "SimpleDriver.hpp"

#include <iostream>

kac::cudalearn::SimpleDriver::SimpleDriver() :
    DriverInterface()
{
}

kac::cudalearn::SimpleDriver::~SimpleDriver()
{
}

void
kac::cudalearn::SimpleDriver::Initialize()
{
    std::cout << "Calling " << __FILE__ << " Initialize function";
}

void
kac::cudalearn::SimpleDriver::Execute()
{
    std::cout << "Calling " << __FILE__ << " Execute function";
}

void
kac::cudalearn::SimpleDriver::Finalize()
{
    std::cout << "Calling " << __FILE__ << " Finalize function";
}
