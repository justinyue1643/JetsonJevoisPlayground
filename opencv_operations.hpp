//
// Created by jay on 12/15/21.
//

#ifndef JETSONJEVOISPLAYGROUND_OPENCV_OPERATIONS_HPP
#define JETSONJEVOISPLAYGROUND_OPENCV_OPERATIONS_HPP

#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat loadImage(const std::string& path);
void displayVideo();
cv::Mat resizeImage(const cv::Mat& img, int width, int height);

#endif //JETSONJEVOISPLAYGROUND_OPENCV_OPERATIONS_HPP
