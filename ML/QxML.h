#ifndef QX_ML_H
#define QX_ML_H

#include <stdint.h>

// Initialize the ML model
void QxML_Init(void);

// Perform inference with the ML model
int QxML_Infer(const float *input_data, uint32_t input_length);

#endif // QX_ML_H