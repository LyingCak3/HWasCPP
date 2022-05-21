
set( target cliExecutor )

set( sources main.cpp )

add_executable( ${target} ${sources} )

target_link_libraries( ${target} 
                        PRIVATE drivers
)   

target_link_options( ${target}
                        PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${PROJECT_LINKER_FLAGS}>
)
