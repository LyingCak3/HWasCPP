

set( target drivers )

set( sources
        DriverFactory.cpp
        SimpleDriver.cpp
    )

set( headers 
        DriverInterface.hpp
        DriverFactory.hpp
        SimpleDriver.hpp
    )

add_library( ${target} SHARED ${sources} ${headers} )

target_compile_options( ${target} 
                            PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${PROJECT_CXX_FLAGS}>
    )

target_include_directories( ${target} 
                                PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    ) 


target_link_libraries( ${target} 
                        PUBLIC  Utils
                                Boost::program_options
    )
