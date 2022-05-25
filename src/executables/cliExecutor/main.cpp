
#include "DriverFactory.hpp"
#include "DriverInterface.hpp"

#include "boost/program_options.hpp"

#include <iostream>
#include <vector>

namespace po = boost::program_options;

int main( int argc, char** argv )
{

    po::options_description all( "All Options" );
    all.add_options()
        ( "help", "Produce this help message" )
    ;

    po::options_description desc( "Executor Options" );
    desc.add_options()
        ( "driver", po::value< std::string >()->default_value( "SimpleDriver" ), "Driver to execute" )
    ;

    all.add( desc );

    std::unique_ptr< kac::cudalearn::DriverInterface > driver( nullptr );

    {
        po::variables_map vm;
        po::command_line_parser parser = po::command_line_parser( argc, argv );
        po::store( parser.options(desc).allow_unregistered().run(), vm );
        po::notify( vm );

        std::string driverName;

        if ( 0 != vm.count( "driver" ) )
        {
            driverName = vm.at( "driver" ).as<std::string>();
        }

        driver = kac::cudalearn::DriverFactory::GetFactory().ConstructMachine( driverName );
    }

    driver->SetupArguments( all );

    po::variables_map vm;
    po::command_line_parser parser = po::command_line_parser( argc, argv );
    po::store( parser.options(all).run(), vm );
    po::notify( vm );

    if ( 0 != vm.count( "help" ) )
    {
        std::cout << all << std::endl;
        return 0;
    } 

    driver->ParseArguments( vm );

    driver->Initialize();

    driver->Execute();

    driver->Finalize();

    return 0;

}
