//
// Created by jay on 12/15/21.
//
#include "pytorch_operations.hpp"

void printRandomTensor(unsigned int row, unsigned int col) {
    torch::Tensor t1 = torch::randn({2,3});
    std::cout << "Random Tensor:\n" << t1 << std::endl;
}

int loadModel(int argc, torch::jit::script::Module& model, const std::string& path) {
    // printRandomTensor(2, 3);

    if (argc != 2)  {
        std::cerr << "loadModel() argc error: " << path << std::endl;
    }

    try {
        model = torch::jit::load(path);
    }
    catch(const c10::Error& e) {
        std::cerr << "loadModel(): error loading the model" << std::endl;
        std::cerr << "------------------------------------" << std::endl;
        std::cerr << e.msg() << std::endl;
        std::cerr << e.what() << std::endl;

        return -1;
    }

    std::cout << "loadModel(): Model loaded successfully!" << std::endl;
    return 1;
}
