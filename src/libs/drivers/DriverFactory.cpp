
#include "DriverFactory.hpp"

kac::cudalearn::DriverFactory&
kac::cudalearn::DriverFactory::GetFactory()
{
    static kac::cudalearn::DriverFactory factory;

    return factory;
}


kac::cudalearn::DriverFactory::DriverFactory()
    : machines_()
    {}

void
kac::cudalearn::DriverFactory::AddMachine( const std::string name, const FactoryFunctor& functor )
{
    machines_.insert( std::make_pair( name, functor ) );
}


std::unique_ptr<kac::cudalearn::DriverInterface::DriverInterface>
kac::cudalearn::DriverFactory::CreateMachine( std::string name )
{
    return machines_.at( name )();
}
