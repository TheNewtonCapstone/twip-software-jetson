# pragma once

#include <iostream>
#include <cmath>
#include <cstdint>
#include "rclcpp/rclcpp.hpp"
#include <onnxruntime_c_api.h>
#include <onnxruntime_cxx_api.h>

class OnnxHandler{
    public:
        OnnxHandler(const std::string _path, const int _num_inputs, const int _num_outputs);
        int run(); 
        std::vector<float>& get_input_buffer();
        std::vector<float>& get_output_buffer();      

    private:
        std::string path;
        int num_inputs;
        int num_outputs;

        Ort::Env env;
        Ort::Session session{nullptr};
        Ort::RunOptions opt{nullptr};

    
        Ort::Value input_tensor{nullptr};
        std::array<int64_t, 1> input_shape;  // use of an array is required by the CreateTensor() function
        std::vector<float> input_buffer;
    

        Ort::Value output_tensor{nullptr};
        std::array<int64_t, 1> output_shape;
        std::vector<float> output_buffer;


};