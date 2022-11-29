/*
Partition the field into differents droplets based on a cutOff
*/

#include "traits.h"

namespace gp
{

    namespace decompose
    {
        
        void traverseDepthFirst(int i, int j,int k,
        const tensor_t & psi, real_t cutOff , Eigen::Tensor<int,DIMENSIONS> & decomposition, int color);

        void decompose( const tensor_t & psi, real_t cutOff,Eigen::Tensor<int,DIMENSIONS> & decomposition);
        
    }
        

};

    