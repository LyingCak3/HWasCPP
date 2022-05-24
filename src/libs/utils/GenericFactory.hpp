
#ifndef GenericFactory_hpp
#define GenericFactory_hpp

#include <map>
#include <memory>
#include <functional>

namespace kac
{

namespace cudalearn
{

namespace factory
{

template< typename T, typename... ARGS >
class GenericFactory
{

public:

    typedef T   BaseType;
    typedef std::function<std::unique_ptr<T>(ARGS...)> Functor;

    bool AddMachine( const std::string name, Functor constructor )
    {
        auto result = machines_.emplace( name, constructor );
        return result.second;
    }

    std::unique_ptr<T> ConstructMachine( const std::string name, ARGS&&... args )
    {
        return machines_.at( name )( std::forward<ARGS>( args )... );
    }

    template< typename N = BaseType >
    class DefaultMachineConstructor
    {
    public:
        std::unique_ptr<T> operator()( ARGS&&... args )
        {
            return std::unique_ptr<T>( new N( std::forward<ARGS>(args)... ) );
        }
    };

    template< typename N = BaseType >
    class RegisterMachine
    {
    public:
        RegisterMachine( const std::string name, GenericFactory<T, ARGS...>& factory, Functor construtor = DefaultMachineConstructor<N>() )
        {
            factory.AddMachine( name, construtor );
        }

    };

protected:

    GenericFactory() : machines_() {};

    std::map< const std::string, Functor > machines_; 

};

}

}

}

#endif
