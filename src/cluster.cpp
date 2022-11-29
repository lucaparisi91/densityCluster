
#include "cluster.h"
#include <iostream>
namespace gp
{

    namespace decompose
    {

        auto pbc( int i , int L)
        {
            return i<0 ? i+L : ( i>=L ? i- L : i  ) ;
        }


        void decompose( const tensor_t & psi, real_t cutOff,Eigen::Tensor<int,DIMENSIONS> & decomposition)
        {
            int color=1;
            decomposition.setConstant(0);
            const auto & dimensions = decomposition.dimensions();

            for(int i=0;i<dimensions[0];i++)
                for(int j=0;j<dimensions[1];j++)
                    for(int k=0;k<dimensions[2];k++)
                    {
                        if ( decomposition(i,j,k)==0 )
                        {
                            
                            traverseDepthFirst(i,j,k,psi,cutOff,decomposition,color);

                            if (decomposition(i,j,k)!=-1)
                            {
                                color+=1;
                            }
                        }
                    }
        }

        void traverseDepthFirst(int i, int j,int k,
            const tensor_t & psi, real_t cutOff,Eigen::Tensor<int,DIMENSIONS> & decomposition, int color)
        {
            const auto & dimensions = psi.dimensions();

            if (decomposition(i,j,k)!=0)
            {
                return;
            }
            else
            {
                auto density=psi(i,j,k);

                if ( density > cutOff )
                {
                    decomposition(i,j,k)=color;
                }
                else
                {
                    decomposition(i,j,k)=-1;
                    return;
                }

            }

            for (int ii=-1;ii<=1;ii++)
                for (int jj=-1;jj<=1;jj++)
                    for (int kk=-1;kk<=1;kk++)
                        {
                            auto i2 = pbc(i + ii,dimensions[0]);
                            auto j2 = pbc(j + jj,dimensions[1]);
                            auto k2 = pbc(k + kk,dimensions[2]);

                            if ( decomposition(i2,j2,k2)==0 )
                            {    
                                traverseDepthFirst(i2,j2,k2,psi,cutOff,decomposition,color );
                            }

                        }

    };

    }
    

};