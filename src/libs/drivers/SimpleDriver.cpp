
#include "SimpleDriver.hpp"

#include <iostream>

#include "DriverFactory.hpp"

namespace po = boost::program_options;

kac::cudalearn::SimpleDriver::SimpleDriver() :
    DriverInterface()
{
}

kac::cudalearn::SimpleDriver::~SimpleDriver()
{
}

void
kac::cudalearn::SimpleDriver::SetupArguments( boost::program_options::options_description& driverDesc )
{

    std::cout << "Calling " << __FILE__ << " SetupArguments function" << std::endl;

    po::options_description desc( "SimpleDriver Options" );

    desc.add_options()
        ( "model", "Model to execute." )
    ;


    driverDesc.add( std::move( desc ) );
}

void
kac::cudalearn::SimpleDriver::ParseArguments( boost::program_options::variables_map& map)
{
    std::cout << "Calling " << __FILE__ << " ParseArguments function" << std::endl;
    std::cout << "\tNumber of args: " << map.size() << std::endl;
    for ( auto t = map.begin(); t != map.end(); ++t )
    {
        std::cout << "\t" << t->first << ": " << t->second.as<std::string>() << std::endl;
    }
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

kac::cudalearn::DriverFactory::RegisterMachine<kac::cudalearn::SimpleDriver> _SimpleDriver( "SimpleDriver", kac::cudalearn::DriverFactory::GetFactory() );

