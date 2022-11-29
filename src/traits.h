#ifndef TRAITS_H
#define TRAITS_H

#include <unsupported/Eigen/CXX11/Tensor>
#include <array>
#include <complex>
#define DIMENSIONS 3

using real_t = double;

using complex_t = std::complex<real_t>;
using value_t = complex_t;
using tensor_t = Eigen::Tensor<real_t,DIMENSIONS> ;

struct geometry;


#if DIMENSIONS==1
    #define TRUNCATE_D(a,b,c) a
    #define EXPAND_D(a ) a[0]
    
#endif

#if DIMENSIONS==2
    #define TRUNCATE_D(a,b,c) a,b
    #define EXPAND_D(a ) a[0],a[1]
    
#endif

#if DIMENSIONS==3
    #define TRUNCATE_D(a,b,c) a,b,c
    #define EXPAND_D(a ) a[0],a[1],a[2]

    
#endif

#define TOL 1e-6

#endif
