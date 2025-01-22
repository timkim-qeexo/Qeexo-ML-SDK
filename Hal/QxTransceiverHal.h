#ifndef QX_TRANSCEIVER_HAL_H
#define QX_TRANSCEIVER_HAL_H

typedef struct {
    void (*open)(void);
    void (*write)(const void *data, int len);
    void (*read)(void *data, int len);
} QxTransceiver_t;

void QxTransceiverHal_Register(QxTransceiver_t *transceiver);

#endif // QX_TRANSCEIVER_HAL_H