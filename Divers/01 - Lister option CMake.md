# 01 - Lister option CMake

Il est possible de lister toutes les options disponibles d'un fichier CMakelists.txt.
Pour cela, dans le dossier contenant le fichier, il faut effectuer la manipulation suivante :

```sh
mkdir build
cd build
cmake ..
cmake -LA | awk '{if(f)print} /-- Cache values/{f=1}'
```

Le résultat sera une liste de toute les options possibles ainsi que la valeur par défaut associé à chacune que vous pouvez modifier lors de l'appel à la commande *cmake*.

Example de résultat
```
AUTOGEMM_ARCHITECTURE:STRING=Hawaii
BLAS_DEBUG_TOOLS:BOOL=OFF
BLAS_DUMP_CLBLAS_KERNELS:BOOL=OFF
BLAS_KEEP_KERNEL_SOURCES:BOOL=ON
BLAS_PRINT_BUILD_ERRORS:BOOL=ON
```
