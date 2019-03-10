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