import numpy as np
import matplotlib.pylab as plt
from cluster import cluster
import h5py

f = h5py.File('droplet_id_test.h5', 'r')
x=np.array(f["g1"]["x"] )
shape=f["g1"]["psiR"].shape
density=(np.array(f["g1"]["psiR"])**2 + np.array(f["g1"]["psiI"])**2)
bbox=np.array([[-16,16],[-16,16],[-16,16]])
clustering = cluster.decompose(density, cutOff=np.min(density) + (np.max(density) - (np.min(density)) )*5e-2  ) + 1

plt.imshow(density[:,:,0])
plt.show()

plt.imshow(clustering[:,:,0] )
plt.show()