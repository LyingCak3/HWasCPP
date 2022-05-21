
#include "SimpleDriver.hpp"

#include <iostream>

#include "DriverFactory.hpp"

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

kac::cudalearn::DriverFactory::RegisterMachine<kac::cudalearn::SimpleDriver> _SimpleDriver( "SimpleDriver" );
