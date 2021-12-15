//
// Created by jay on 12/15/21.
//

#ifndef JETSONJEVOISPLAYGROUND_PYTORCH_OPERATIONS_HPP
#define JETSONJEVOISPLAYGROUND_PYTORCH_OPERATIONS_HPP

#include <iostream>
#include <torch/torch.h>
#include <torch/script.h>
#include <string>

int loadModel(int argc, torch::jit::script::Module& model, const std::string& path);

#endif //JETSONJEVOISPLAYGROUND_PYTORCH_OPERATIONS_HPP
