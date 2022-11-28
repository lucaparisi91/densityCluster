
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(../init.cmake)
add_library(cluster cluster.cpp )
configure(cluster)


#pybind11_add_module( gpCpp gpCpp.cpp pyTools.cpp )
#target_link_libraries(gpCpp PUBLIC gp_lib)
#configure(gpCpp)




