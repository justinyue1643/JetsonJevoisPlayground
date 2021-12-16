#include "opencv_operations.hpp"
#include "pytorch_operations.hpp"

int main(int argc, const char* argv[]) {
    // displayVideo();

    cv::Mat img = loadImage("/home/jay/CLionProjects/JetsonJevoisPlayground/test_images/trash1.jpg");
    std::cout << "r,c = " << img.rows << ", " << img.cols << std::endl;
    cv::Mat resizedImg = resizeImage(img, 256, 256);
    std::cout << "r,c = " << resizedImg.rows << ", " << resizedImg.cols << std::endl;

    torch::jit::script::Module model;
    loadModel(argc, model, argv[1]);

    std::vector<torch::jit::IValue> inputs;
    torch::Tensor onesInput = torch::ones({1, 3, 256, 256});
    onesInput = onesInput.to(torch::kCUDA);
    inputs.push_back(onesInput);


    at::Tensor output = model.forward(inputs).toTensor();
    std::cout << output << std::endl;


    return 0;
}
