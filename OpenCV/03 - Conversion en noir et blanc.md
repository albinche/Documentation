# 03 - Conversion en noir et blanc

Dans cet exemple nous allons voir comment charger une image, la transformer en niveau de gris et afficher à l'écran les deux images.

### Header

Cette fois-çi au lieu d'inclure directement *opencv.hpp*, on inclu seulement les modules dont nous avons réellement besoin : **highgui** et **imgproc**.

```cpp
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
```

### Chargement de l'image

On charge l'image et on check si que l'opération à bien réussi de la même manière que dans l'exemple précédent.

```cpp
cv::Mat srcImage = cv::imread("./tortue.png");
if (srcImage.empty()) {
    return EXIT_FAILURE;
}
```

### Conversion en niveau de gris

La conversion d'image étant une opération classique dans le traitement d'image, OpenCV met directement à disposition la fonction *cvtColor* qui permet de convertir l'image passé en paramètre dans l'un de modes disponibles. 
A ça, nous allons créer une deuxième variable *dstImage* dans laquelle nous viendrons mettre le résultat de la conversion pour pouvoir l'afficher ensuite.

```cpp
cv::Mat dstImage;
cv::cvtColor(srcImage, dstImage, cv::COLOR_BGR2GRAY);
```

### Affichage

Concernant l'affichage, c'est le même process que précédemment sauf que nous allons créer une deuxième fenêtre qui nous servira pour l'image en noir et blanc. On appel ensuite la fonction *waitKey* pour gérer les évenements clavier.

```cpp
cv::namedWindow("Input Image", cv::WINDOW_AUTOSIZE);
cv::namedWindow("Output Image", cv::WINDOW_AUTOSIZE);
cv::imshow("Input Image", srcImage);
cv::imshow("Output Image", dstImage);
cv::waitKey(0); 
```

### Code final

```cpp
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main (int argc, char** argv) {
  cv::Mat srcImage;
  cv::Mat dstImage;

  srcImage = cv::imread("./tortue.jpg");
  
  if (srcImage.empty()) {
    std::cout << "Input image has no data, please check it" << std::endl;
    return 0;
  }
  
  cv::cvtColor(srcImage, dstImage, cv::COLOR_BGR2GRAY);
  cv::namedWindow("Input Image", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Output Image", cv::WINDOW_AUTOSIZE);

  cv::imshow("Input Image", srcImage);
  cv::imshow("Output Image", dstImage);
  cv::waitKey(0);
  
  return EXIT_SUCCESS;
}
```

Il nous ensuite à compiler grâce à la commande *g++*.

```sh
g++ -std=c++11 -Wall -O2 convertImage.cpp -o convertImage `pkg-config --cflags --libs opencv4`
```

Puis à lancer l'application *convertImage* généré :

```sh
./convertImage
```
