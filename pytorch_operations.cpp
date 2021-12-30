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

// https://pytorch.org/vision/stable/transforms.html
at::Tensor convertImgToTensor(const cv::Mat& img) {
    std::cout << "convertImgToTensor(): start" << std::endl;

    at::Tensor tensorImg = torch::from_blob(img.data, {1, 3, img.rows, img.cols}, torch::kByte);
    tensorImg = tensorImg.toType(torch::kFloat);

//    std::cout << "convertImgToTensor(): tensor size is " << tensorImg.sizes() << std::endl;
//
//    std::cout << "convertImgToTensor(): printing tensor" << std::endl;
//    std::cout << "-------------------------------------" << std::endl;
//
//    std::cout << tensorImg << std::endl;
//    std::cout << tensorImg.slice(0,1) << std::endl;
//    std::cout << tensorImg.data() << std::endl;
//
//
//    std::cout << "-------------------------------------" << std::endl;

    return tensorImg;
}

// https://www.fatalerrors.org/a/0tp90Ts.html
std::string predict(const at::Tensor& predictionTensor) {
    std::map<unsigned int, std::string> classes{
            {0, "Landfill"},
            {1, "Recycle"},
            {2, "Compost"}
    };
    int index = predictionTensor.argmax(1).item<int>();
    return classes[index];
}
