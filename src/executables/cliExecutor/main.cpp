
#include "DriverFactory.hpp"
#include "DriverInterface.hpp"

int main( int argc, char* argv )
{

    std::unique_ptr< kac::cudalearn::DriverInterface > driver = kac::cudalearn::DriverFactory::GetFactory().CreateMachine( "SimpleDriver" );

    driver->Initialize();

    driver->Execute();

    driver->Finalize();

    return 0;

}
