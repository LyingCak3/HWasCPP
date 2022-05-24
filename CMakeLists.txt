
##
# Set CMake version and policies
##
cmake_minimum_required( VERSION 3.20.0 FATAL_ERROR )

##
# Set Language standards
##
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED TRUE )
set( CMAKE_CXX_EXTENSIONS FALSE )

set( CMAKE_CUDA_STANDARD 17 )
set( CMAKE_CUDA_STANDARD_REQUIRED TRUE )

##
# Define the project
##
project( CUDALearning CXX C CUDA )

# Project wide includes
include( FindPackageHandleStandardArgs )

# Additional project wide CMake settings
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/$<CONFIG> )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/$<CONFIG> )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin/$<CONFIG> )

set( CMAKE_SKIP_RPATH FALSE )
set( CMAKE_BUILD_RPATH_USE_ORIGIN TRUE )

##
# Project external dependencies
##
find_package( CUDAToolkit REQUIRED )

find_package( Boost 1.79...<999.999 REQUIRED CONFIG COMPONENTS program_options )
find_package_handle_standard_args( Boost CONFIG_MODE )


##
# Project Level Variables
##

set( PROJECT_CXX_FLAGS
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-pedantic>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Werror>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wshadow>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wsign-compare>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wundef>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wuninitialized>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wunused-parameter>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wunused-variable>
    $<$<CXX_COMPILER_ID:GNU>:-Wall>
    $<$<CXX_COMPILER_ID:GNU>:-Wextra>
    $<$<CXX_COMPILER_ID:GNU>:-Wunused>
)

set( PROJECT_LINKER_FLAGS
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wl,--enable-new-dtags>
)

add_subdirectory( src )
