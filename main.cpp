#include "opencv_operations.hpp"
#include "pytorch_operations.hpp"

int main(int argc, const char* argv[]) {
    // displayVideo();
    torch::jit::script::Module model;
    loadModel(argc, model, argv[1]);

    cv::Mat img = loadImage("/home/jay/CLionProjects/JetsonJevoisPlayground/test_images/trash1.jpg");
    cv::Mat resizedImg = resizeImage(img, 256, 256);

    std::vector<torch::jit::IValue> inputs;
//    torch::Tensor input = torch::ones({1, 3, 256, 256});
//    input = input.to(torch::kCUDA);
//    inputs.push_back(input);

    torch::Tensor input = convertImgToTensor(resizedImg);
    input = input.to(torch::kCUDA);
    inputs.push_back(input);

    at::Tensor output = model.forward(inputs).toTensor().to(torch::kCPU);
    std::cout << output << std::endl;
    std::cout << predict(output) << std::endl;

    return 0;
}
