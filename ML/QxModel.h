#ifndef QX_MODEL_H
#define QX_MODEL_H

#include <stdint.h>

// Initialize the model
void QxModel_Init(void);

// Train the model with CSV data
void QxModel_Train(const char *csv_file_A, const char *csv_file_B);

// Perform inference with new input data
int QxModel_Infer(const float *input_data, uint32_t input_length);

#endif // QX_MODEL_H