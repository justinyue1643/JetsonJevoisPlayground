//
// Created by jay on 12/15/21.
//

#ifndef JETSONJEVOISPLAYGROUND_PYTORCH_OPERATIONS_HPP
#define JETSONJEVOISPLAYGROUND_PYTORCH_OPERATIONS_HPP

#include <iostream>
#include <torch/torch.h>
#include <torch/script.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <map>

int loadModel(int argc, torch::jit::script::Module& model, const std::string& path);
torch::Tensor convertImgToTensor(const cv::Mat& img);
std::string predict(const at::Tensor& predictionTensor);

#endif //JETSONJEVOISPLAYGROUND_PYTORCH_OPERATIONS_HPP
