
set( target Utils )

set( sources 
        GenericFactory.cpp
    )

set( headers 
        GenericFactory.hpp
    )

add_library( ${target} ${sources} ${headers} )

target_include_directories( ${target}
                                PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
