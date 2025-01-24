#ifndef QX_ML_H
#define QX_ML_H

#include <stdint.h>

/**
 * @brief Initialize the ML model.
 */
void QxML_Init(void);

/**
 * @brief Perform inference with the ML model.
 * 
 * @param input_data The input data array.
 * @param input_length The length of the input data array.
 * @return int The predicted class.
 */
int QxML_Infer(const float *input_data, uint32_t input_length);

#endif // QX_ML_H