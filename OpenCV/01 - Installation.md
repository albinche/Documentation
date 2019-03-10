# 01 - Installation

## Mise à jour système

```sh
sudo apt update
sudo apt upgrade
```

## Installation des paquets

```sh
sudo apt install build-essential
sudo apt install cmake git pkg-config 
sudo apt install libgtk2.0-dev libavcodec-dev libavformat-dev libswscale-dev
```

## Récupération des sources

**Depuis le repository github [OpenCV](https://github.com/opencv/opencv)**
```sh
git clone https://github.com/opencv/opencv.git
```
Cette méthode permet de récupérer la dernière version disponible au moment du clonage.

**Depuis le site officiel [OpenCV](https://opencv.org/releases.html)**

Il suffit de télécharger l'archive de la version et ensuite l'extraire dans le dossier voulu.

## Compilation/Instalation

```sh
cd opencv
mkdir build
cd build
```

On génère ensuite le Makefile grâce à *cmake* avec toutes les options définies.
L'ensemble des options disponibles ainsi que leur valeur par défaut peuvent être affiché grâce à cette [manipulation](https://github.com/esme-ultrone/Documentation/blob/master/Divers/01%20-%20Lister%20option%20CMake.md)

```sh
cmake -D CMAKE_BUILD_TYPE=Release \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D OPENCV_GENERATE_PKGCONFIG=YES ..
```

On peut ensuite compiler avec la commande *make* :

```sh
make -j4      # Use 4 thread to compile
```

Puis l'installation en utilisant *make* une seconde fois :

```sh
sudo make install
```

Par sécurité, on utilise *ldconfig* pour la configuration des liens dynamiques

```sh
sudo ldconfig -v
```
