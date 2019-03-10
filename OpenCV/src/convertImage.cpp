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