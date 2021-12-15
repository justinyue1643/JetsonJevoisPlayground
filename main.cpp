#include "opencv_operations.hpp"
#include "pytorch_operations.hpp"

int main(int argc, const char* argv[]) {
    // displayVideo();

    loadImage("/home/jay/CLionProjects/JetsonJevoisPlayground/test_images/trash1.jpg");
    torch::jit::script::Module model;
    loadModel(argc, model, argv[1]);



    return 0;
}
