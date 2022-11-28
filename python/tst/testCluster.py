import numpy as np
import clusterCpp as _cluster
import unittest

class testCluster(unittest.TestCase):

    def test_squares(self):
        psi=np.zeros(shape=(10,10,10,1) )
        psi[2:8,3:4,3:6,0]=1
        psi[9,5:6,7:9,0 ]=1


        decomp=_cluster.decomposition()
        clustering = decomp.decompose(psi,0.5)
        self.assertEqual( np.sum(clustering == 1 ) , 18 )
        self.assertEqual( np.sum(clustering == 2 ) , 2 )
        

if __name__ == '__main__':
    unittest.main()
