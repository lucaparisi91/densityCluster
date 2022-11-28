
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


function(configure target)

  target_link_libraries(${target} PRIVATE stdc++fs)
  #target_link_libraries(${target} PRIVATE hdf5)
  #target_link_libraries (${target} Eigen3::Eigen )

  #set_target_properties(${target} PROPERTIES COMPILE_FLAGS ${TARGET_COMPILE_FLAGS} )

  #if(OpenMP_CXX_FOUND)
  #    target_link_libraries(${target} PUBLIC OpenMP::OpenMP_CXX)
  #endif()

endfunction()


find_package(Python 3.6 COMPONENTS Interpreter Development REQUIRED)
#find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_compile_options(
  -Wfatal-errors
       $<$<CONFIG:RELEASE>:-O3>
       $<$<CONFIG:DEBUG>:-O0>
       $<$<CONFIG:DEBUG>:-g>
)

add_compile_definitions(
        $<$<CONFIG:RELEASE>:NDEBUG>
        $<$<CONFIG:RELEASE>:BOOST_DISABLE_ASSERTS>
)