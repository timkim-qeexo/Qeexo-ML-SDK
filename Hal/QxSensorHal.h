#ifndef QX_SENSOR_HAL_H
#define QX_SENSOR_HAL_H

typedef struct {
    void (*init)(void);
    void (*enable)(int odr, int fsr);
    void (*disable)(void);
    void (*read)(void *data);
    void (*read_fifo)(void *data);
    int* (*get_odrs)(void);
    int* (*get_fsrs)(void);
} QxSensor_t;

void QxSensorHal_Register(QxSensor_t *sensor);

#endif // QX_SENSOR_HAL_H