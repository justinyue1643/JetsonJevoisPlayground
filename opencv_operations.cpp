//
// Created by jay on 12/15/21.
//

#include "opencv_operations.hpp"

// https://cppsecrets.com/users/168511510411111711412197115105110104975764103109971051084699111109/C00-OpenCV-cvnormalize.php

cv::Mat loadImage(const std::string& path) {
    cv::Mat img = cv::imread(path);
    if (img.empty()) {
        // throw an error
        std::cerr << "loadImage(): Image could not be loaded" << std::endl;
    }
    std::cout << "loadImage(): Image was loaded!" << std::endl;

    return img;
}

void normalizePixel(cv::Vec3f& pixel) {
    float means[3] = {0.485, 0.456, 0.406};
    float stds[3] = {0.229, 0.224, 0.225};
    pixel[0] = (pixel[0] - means[0])/stds[0];
    pixel[1] = (pixel[1] - means[1])/stds[1];
    pixel[2] = (pixel[2] - means[2])/stds[2];
}

cv::Mat resizeImage(const cv::Mat& img, int width, int height) {
    cv::Mat resizedImg;
    cv::resize(img, resizedImg, cv::Size(width, height));

//    std::cout << resizedImg << std::endl;
    // extract color planes
    std::vector<cv::Mat> planes(3);
    cv::split(resizedImg, planes);


    double means[3] = {0.485, 0.456, 0.406};
    double stds[3] = {0.229, 0.224, 0.225};


    for (unsigned int i = 0; i < planes.size(); ++i) {
        std::cout << "Channel " << i << std::endl;
        std::cout << "---------" << i << std::endl;
        std::cout << "Before: " << planes.at(i) << std::endl;
        planes.at(i) /= 255.0;
        planes.at(i) = (planes.at(i) - means[i])/ stds[i];
        std::cout << "After: " << planes.at(i) << std::endl;
        std::cout << "\n" << std::endl;
    }
    cv::Mat normalizedImg;
    cv::merge(planes, normalizedImg);
//    std::cout << normalizedImg << std::endl;

    // normalize
//    cv::Mat normalizedImg = resizedImg.clone();
//    normalizedImg.forEach<cv::Vec3f>(
//            [](cv::Vec3f &pixel, const int* position) -> void {
//                normalizePixel(pixel);
//            }
//            );

    return normalizedImg;
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
