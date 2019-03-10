# 02 - Premier programme

Petit programme pour vérifier l'installation et commencer à développer avec OpenCV
Le programme suivant va charger et afficher à l'écran une image présente en local sur la machine puis attendre un évenement clavier pour terminer le programme.

### Header

On commence par include le header d'openCV. On inclut ici *opencv.hpp* qui est le header générique comprenant tous les autres headers fournis par openCV (*highgui, imgproc, etc ...*)

```cpp
#include <opencv2/opencv.hpp>
```

### Type MAT

Dans openCV, le type principale pour gérer des images est le type *Mat* qui correspond à une matrice qui contiendra toute les données relatives à nos images

```cpp
cv::Mat srcImage;
```

### Chargement de l'image

On charge ensuite notre image dans notre varialbe *srcImage* grâce à la fonction *imread*.

```cpp
srcImage = cv::imread("<path_to_image>");
```

On check ensuite si l'image chargé, n'est pas vide, pour les futurs process.

```cpp
if (srcImage.empty()) {
  std::cout << "Input image has no data, please check it" << std::endl;
  return 0;
}
```

### Affichage à l'écran

Pour afficher l'image à l'écran, on commence par créer une fenêtre qui contiendra notre image puis on appel la fonction *imshow* avec le nom de notre fenetre et l'image à afficher

```cpp
cv::namedWindow("Input Image", cv::WINDOW_AUTOSIZE);
cv::imshow("Input Image", srcImage);
```

### Attente de l'évement clavier

La fonction *waitKey* permet de gérer les évenements claviers. La fonction prend en paramètre un delai qui correspond le délai d'attente avant de passer à l'instruction suivante. La valeur 0 indique un temps d'attente infini.

```cpp
cv::waitKey(0);
```

### Code final

On suppose ici que l'image *tortue.png* est présente dans le même dossier que celui du code source.

```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main (int argc, char** argv) {
  cv::Mat srcImage;
  srcImage = cv::imread("./tortue.jpg");
  
  if (srcImage.empty()) {
    std::cout << "Input image has no data, please check it" << std::endl;
    return 0;
  }
  
  cv::namedWindow("Input Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Input Image", srcImage);
  
  cv::waitKey(0);
  
  return EXIT_SUCCESS;
}
```

Il nous ensuite à compiler grâce à la commande *g++*.

```sh
g++ -std=c++11 -Wall -O2 loadImage.cpp -o loadImage `pkg-config --cflags --libs opencv4`
```

Puis à lancer l'application *loadImage* généré :

```sh
./loadImage
```
