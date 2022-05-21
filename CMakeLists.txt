

cmake_minimum_required( VERSION 3.18.2 FATAL_ERROR )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED TRUE )
set( CMAKE_CXX_EXTENSIONS FALSE )

set( CMAKE_CUDA_STANDARD 17 )
set( CMAKE_CUDA_STANDARD_REQUIRED TRUE )

project( CUDALearning CXX C CUDA )
include( FindPackageHandleStandardArgs )

find_package( CUDAToolkit REQUIRED )

find_package( Boost 1.79 REQUIRED CONFIG )
find_package_handle_standard_args( Boost CONFIG_MODE )

# set( CMAKE_CUDA_COMPILER ${CUDAToolkit_NVCC_EXECUTABLE} )

# enable_language( CUDA )

##
# Project Level Variables
##

set( PROJECT_CXX_FLAGS
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-pedantic>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Werror>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wshadow>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wsign-compare>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wstrict-prototypes>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wundef>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wuninitialized>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wunused-parameter>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-Wunused-variable>
    $<$<CXX_COMPILER_ID:NVHPC,GNU>:-W>
)

add_subdirectory( src )
