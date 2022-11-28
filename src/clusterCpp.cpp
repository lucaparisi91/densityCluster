#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>
#include <mpi.h>
#include "traits.h"
#include <pybind11/stl.h>
#include "pyTools.h"
namespace py = pybind11;
#include "cluster.h"


namespace pyInterface
{
    class decomposition
    {
        public:

        auto decompose( const py::array_t<complex_t> & pyPsi, real_t densityCutOff)
        {
            auto psi = toTensor<complex_t, DIMENSIONS + 1 >(pyPsi);
            _decomposition = std::make_shared<Eigen::Tensor<int,DIMENSIONS+1> >( psi.dimensions() );

            _decomposition->setConstant(0);
            gp::decompose::decompose(psi,densityCutOff,*_decomposition);
            return toArray(*_decomposition);
        }

        private:

        std::shared_ptr<Eigen::Tensor<int,DIMENSIONS+1> > _decomposition;

    };

}


PYBIND11_MODULE( clusterCpp, m ) {
     py::class_<pyInterface::decomposition>(m, "decomposition")
     .def(py::init<>())
     .def("decompose",&pyInterface::decomposition::decompose)
  ;           
}