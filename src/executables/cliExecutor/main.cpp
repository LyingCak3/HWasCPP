
#include "DriverFactory.hpp"
#include "DriverInterface.hpp"

#include "boost/program_options.hpp"

#include <iostream>
#include <vector>

namespace po = boost::program_options;

int main( int argc, char** argv )
{

    po::options_description desc( "Options" );
    desc.add_options()
        ( "help", "produce help message" )
        ( "driver", po::value< std::string >(), "Driver to execute" )
    ;

    po::variables_map vm;
    po::parsed_options parsed = po::command_line_parser( argc, argv ).options(desc).allow_unregistered().run();
    po::store( parsed, vm );
    po::notify( vm );

    std::vector< std::string > pass_to_driver = po::collect_unrecognized( parsed.options, po::include_positional );

    if ( vm.count( "help" ) )
    {
        std::cout << desc << std::endl;
        return 0;
    }

    std::unique_ptr< kac::cudalearn::DriverInterface > driver = kac::cudalearn::DriverFactory::GetFactory().ConstructMachine( "SimpleDriver" );

    driver->ParseArguments(argc, argv);

    driver->Initialize();

    driver->Execute();

    driver->Finalize();

    return 0;

}
