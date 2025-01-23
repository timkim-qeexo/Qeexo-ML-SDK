#include "QxML.h"
#include "arm_math.h"
#include "arm_nnfunctions.h"

// Example model parameters (these should be replaced with actual model parameters)
#define INPUT_SIZE 128
#define OUTPUT_SIZE 2

// Example weights and biases (these should be replaced with actual model weights and biases)
extern float model_weights[INPUT_SIZE * OUTPUT_SIZE];
extern float model_biases[OUTPUT_SIZE];

// Initialize the ML model
void QxML_Init(void) {
    // Initialize the model (e.g., load weights and biases)
}

// Perform inference with the ML model
int QxML_Infer(const float *input_data, uint32_t input_length) {
    if (input_length != INPUT_SIZE) {
        return -1; // Error: input length does not match model input size
    }

    float output_data[OUTPUT_SIZE];

    // Perform the matrix multiplication and add the bias
    arm_matrix_instance_f32 input_matrix;
    arm_matrix_instance_f32 weight_matrix;
    arm_matrix_instance_f32 bias_matrix;
    arm_matrix_instance_f32 output_matrix;

    arm_mat_init_f32(&input_matrix, 1, INPUT_SIZE, (float *)input_data);
    arm_mat_init_f32(&weight_matrix, INPUT_SIZE, OUTPUT_SIZE, model_weights);
    arm_mat_init_f32(&bias_matrix, 1, OUTPUT_SIZE, model_biases);
    arm_mat_init_f32(&output_matrix, 1, OUTPUT_SIZE, output_data);

    arm_mat_mult_f32(&input_matrix, &weight_matrix, &output_matrix);
    arm_mat_add_f32(&output_matrix, &bias_matrix, &output_matrix);

    // Apply softmax to the output
    arm_softmax_f32(output_data, OUTPUT_SIZE, output_data);

    // Determine the class with the highest probability
    int predicted_class = 0;
    float max_prob = output_data[0];
    for (int i = 1; i < OUTPUT_SIZE; i++) {
        if (output_data[i] > max_prob) {
            max_prob = output_data[i];
            predicted_class = i;
        }
    }

    return predicted_class;
}