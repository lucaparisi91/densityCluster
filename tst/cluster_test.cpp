#include "gtest/gtest.h"
#include "mpi.h"
#include "../src/cluster.h"

auto fillSquares( Eigen::Tensor<real_t,DIMENSIONS> & data, std::array<int,DIMENSIONS> left,std::array<int,DIMENSIONS> right)
{
    for(int i=left[0]; i<=right[0];i++)
    {
        for(int j=left[1];j<=right[1];j++)
        {
            for(int k=left[2];k<=right[2];k++ )
            {
                data(i,j,k)=1;
            }
        }
    }
}


auto testColorSquares( Eigen::Tensor<int,DIMENSIONS> & data, std::array<int,DIMENSIONS> left,std::array<int,DIMENSIONS> right,int color)
{
    for(int i=left[0]; i<=right[0];i++)
    {
        for(int j=left[1];j<=right[1];j++)
        {
            for(int k=left[2];k<=right[2];k++ )
            {
                ASSERT_EQ(data(i,j,k) , color );
            }
        }
    }
}

TEST(cluster,squares)
{

    Eigen::Tensor<real_t,DIMENSIONS> data(100,100,100);
    Eigen::Tensor<int,DIMENSIONS> decomposition(100,100,100);
    data.setConstant(0);
    decomposition.setConstant(0);

    fillSquares(data,{10,10,10},{50,50,50});
    //gp::decompose::traverseDepthFirst(15,15,15,data,0.5,decomposition,1);
    gp::decompose::decompose(data,0.5,decomposition);

    testColorSquares( decomposition ,{10,10,10},{50,50,50} ,1);
    

    testColorSquares( decomposition ,{0,0,0},{9,99,99} ,-1);
    testColorSquares( decomposition ,{51,0,0},{99,99,99} ,-1);

    data.setConstant(0);
    fillSquares(data,{10,10,10},{20,20,20});
    fillSquares(data,{50,10,10},{60,20,20});
    gp::decompose::decompose(data,0.5,decomposition);

    testColorSquares( decomposition ,{10,10,10},{20,20,20} ,1);
    testColorSquares( decomposition ,{50,10,10},{60,20,20} ,2);


}