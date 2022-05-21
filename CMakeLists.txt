

cmake_minimum_required( VERSION 3.18.2 FATAL_ERROR )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED TRUE )

set( CMAKE_CUDA_STANDARD 17 )
set( CMAKE_CUDA_STANDARD_REQUIRED TRUE )

project( CUDALearning CXX C CUDA )
include( FindPackageHandleStandardArgs )

find_package( CUDAToolkit REQUIRED )

find_package( Boost 1.79 REQUIRED CONFIG )
find_package_handle_standard_args( Boost CONFIG_MODE )

# set( CMAKE_CUDA_COMPILER ${CUDAToolkit_NVCC_EXECUTABLE} )

# enable_language( CUDA )

set( target CuLearning )

add_library( ${target} SHARED )

target_link_libraries( ${target} 
                            PRIVATE     CUDA::cudart        
    )

add_subdirectory( src )
