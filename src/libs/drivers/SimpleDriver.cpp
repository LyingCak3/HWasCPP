
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
kac::cudalearn::SimpleDriver::ParseArguments( int argc, char* argv )
{
    std::cout << "Calling " << __FILE__ << " ParseArguments function" << std::endl;
    std::cout << "\tNumber of args: " << argc << std::endl;
    std::cout << "\tArguments: " << argv << std::endl; 
}

void
kac::cudalearn::SimpleDriver::Initialize()
{
    std::cout << "Calling " << __FILE__ << " Initialize function" << std::endl;
}

void
kac::cudalearn::SimpleDriver::Execute()
{
    std::cout << "Calling " << __FILE__ << " Execute function" << std::endl;
}

void
kac::cudalearn::SimpleDriver::Finalize()
{
    std::cout << "Calling " << __FILE__ << " Finalize function" << std::endl;
}

kac::cudalearn::DriverFactory::RegisterMachine<kac::cudalearn::SimpleDriver> _SimpleDriver( "SimpleDriver" );

