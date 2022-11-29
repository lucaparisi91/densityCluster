import numpy as np
import clusterCpp

def decompose( density, cutOff ):
    """
    INPUTS
    density : 3D array
    cutOff: real scalar
    OUTPUTS:
    decomposition : 3D array of indices. Indices equal to zero indicate no cluster
    """
    
    decomp=clusterCpp.decomposition()
    decomposition=decomp.decompose(density,cutOff)

    return np.copy(np.array(decomposition) )


