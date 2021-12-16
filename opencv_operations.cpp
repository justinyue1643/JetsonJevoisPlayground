//
// Created by jay on 12/15/21.
//

#include "opencv_operations.hpp"

cv::Mat loadImage(const std::string& path) {
    cv::Mat img = cv::imread(path);
    if (img.empty()) {
        // throw an error
        std::cerr << "loadImage(): Image could not be loaded" << std::endl;
    }
    std::cout << "loadImage(): Image was loaded!" << std::endl;

    return img;
}

cv::Mat resizeImage(const cv::Mat& img, int width, int height) {
    cv::Mat resizedImg;
    cv::resize(img, resizedImg, cv::Size(width, height));

    return resizedImg;
}

void displayVideo() {
    std::cout << "displayVideo(): Show camera stream" << std::endl;
    cv::VideoCapture cap(0, cv::CAP_ANY);
    std::string windowName = "Jetson Jevois Playground";
    cv::Mat frame;

    cv::namedWindow(windowName);
    while (true) {
        cap >> frame;
        cv::imshow(windowName, frame);

        if (cv::waitKey(10) == 27) {
            std::cout << "displayVideo(): Quitting..." << std::endl;
            break;
        }
    }
}
