#include "QxSensorHal.h"

// Example sensor functions
void Sensor_Init(void) {
    // Initialize sensor
}

void Sensor_Enable(int odr, int fsr) {
    // Enable sensor with specified ODR and FSR
}

void Sensor_Disable(void) {
    // Disable sensor
}

void Sensor_Read(void *data) {
    // Read sensor data
}

void Sensor_Read_FIFO(void *data) {
    // Read sensor data from FIFO
}

int* Sensor_Get_ODRs(void) {
    // Return list of supported ODRs
    static int odrs[] = {10, 20, 50, 100};
    return odrs;
}

int* Sensor_Get_FSRs(void) {
    // Return list of supported FSRs
    static int fsrs[] = {2, 4, 8, 16};
    return fsrs;
}

void QxSensorHal_Register(QxSensor_t *sensor) {
    sensor->init = Sensor_Init;
    sensor->enable = Sensor_Enable;
    sensor->disable = Sensor_Disable;
    sensor->read = Sensor_Read;
    sensor->read_fifo = Sensor_Read_FIFO;
    sensor->get_odrs = Sensor_Get_ODRs;
    sensor->get_fsrs = Sensor_Get_FSRs;
}