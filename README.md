## Clustering
A C++ code with python binding for clustering based on density. Resturns a numpy array of indices. The index 0 represents a cell which is not part of any cluster. An example is found in python/examples.
## Requirements
Requires Eigen , CMake and a modern version of python. Often found installed by default on HPC machines ( including rocket ).
## Install
```
cd python
python setup.py build
pip install .
```
## Notes
Currently naive algorithm. Slow and aggressive use of the stack. May have to use
```
ulimit -s unlimited
```