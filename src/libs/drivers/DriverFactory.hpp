
#ifndef DriverFactory_hpp
#define DriverFactory_hpp

#include <map>
#include <memory>

#include "DriverInterface.hpp"

namespace kac
{

namespace cudalearn
{

class DriverFactory
{

public:

    typedef std::unique_ptr<DriverInterface>(*FactoryFunctor)();

    template< typename T >
    class RegisterMachine
    {
    public:
        RegisterMachine( const std::string name )
        {
            DriverFactory::GetFactory().AddMachine( name, 
                [](){ return std::unique_ptr<DriverInterface>( new T() ); }
            );
        }
    };

    static DriverFactory& GetFactory();

    ~DriverFactory() {};

    DriverFactory( DriverFactory const& ) = delete;

    void operator=( DriverFactory const& ) = delete;

    void AddMachine( const std::string name, const FactoryFunctor& functor );

    std::unique_ptr<DriverInterface> CreateMachine( const std::string name ); 


private:

    DriverFactory();

    std::map< const std::string, FactoryFunctor> machines_;

};

}

}

#endif
