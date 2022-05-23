
#ifndef GenericFactory_hpp
#define GenericFactory_hpp

#include <map>
#include <memory>

namespace kac
{

namespace cudalearn
{

namespace factory
{

template< typename T >
class GenericFactory;

namespace detail
{

template< typename... T>
class MachineConstructor
{

public:

    std::unique_ptr<nullptr_t> operator()()
    {
        return nullptr;
    }

};

template< typename T >
class MachineConstructor<T>
{

public:

    template< typename... ARGS >
    std::unique_ptr<T> operator()( ARGS&&... args )
    {
        return std::unique_ptr<T>( new T( std::forward<ARGS>(args)... ) );
    }

};

template< typename T, typename N >
class MachineConstructor<T, N>
{
public:

    template< typename... ARGS > 
    std::unique_ptr<T> operator()( ARGS&&... args )
    {
        return std::unique_ptr<T>( new N( std::forward<ARGS>(args)... ) );
    }
};

template< typename... T >
class RegisterMachine
{
public:
    RegisterMachine( const std::string name ) = delete;
};

template< typename T >
class RegisterMachine<T>
{
public:
    RegisterMachine( const std::string name )
    {
        GenericFactory<T>::AddMachine( name, MachineConstructor< T >() );
    }

};

template< typename T, typename N >
class RegisterMachine<T, N>
{
public:
    RegisterMachine( const std::string name )
    {
        GenericFactory<T>::AddMachine( name, MachineConstructor<T, N>() );
    }

};

}

template< typename T >
class GenericFactory
{

public:

    template< typename N >
    using RegisterMachine = detail::RegisterMachine<T, N>;

    static GenericFactory<T>& GetFactory(){
        static GenericFactory<T> factory;
        return factory;
    };

    template< typename... ARGS>
    static void AddMachine( const std::string name, detail::MachineConstructor<ARGS...> constructor )
    {
        GetFactory().machines_.insert( std::make_pair( name, constructor ) );
    }

    template< typename... ARGS >
    static std::unique_ptr<T> ConstructMachine( const std::string name, ARGS&&... args )
    {
        return GetFactory().machines_.at( name )->operator()( std::forward<ARGS>( args )... );
    }

protected:

    GenericFactory() : machines_() {};

    std::map< const std::string, const detail::MachineConstructor<> > machines_; 


};

}

}

}

#endif
