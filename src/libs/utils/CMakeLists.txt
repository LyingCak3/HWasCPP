
set( target Utils )

set( sources 
    )

set( headers 
        GenericFactory.hpp
    )

add_library( ${target} INTERFACE )

target_sources( ${target} INTERFACE ${headers} )

target_include_directories( ${target}
                                INTERFACE   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
