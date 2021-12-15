#include "opencv_operations.hpp"
#include "pytorch_operations.hpp"

int main(int argc, const char* argv[]) {
    displayVideo();

    torch::jit::script::Module model;
    loadModel(argc, model, argv[1]);

    return 0;
}
