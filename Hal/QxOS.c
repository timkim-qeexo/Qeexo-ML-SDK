#include "QxOS.h"
#include <cstddef>

// Initialize Board Support Package
void QxOS_BSP_Init(void) {
    // Initialize the CMSIS-RTOS2 kernel
    osKernelInitialize();
}

// Create a new thread
QxOS_Thread_t QxOS_Thread_Create(void (*task)(void *), const char *name, int priority) {
    osThreadAttr_t attr = {
        .name = name,
        .priority = (osPriority_t)priority
    };
    return osThreadNew((osThreadFunc_t)task, NULL, &attr);
}

// Terminate the specified thread
void QxOS_Thread_Terminate(QxOS_Thread_t thread) {
    osThreadTerminate(thread);
}

// Suspend the specified thread
void QxOS_Thread_Suspend(QxOS_Thread_t thread) {
    osThreadSuspend(thread);
}

// Resume the specified thread
void QxOS_Thread_Resume(QxOS_Thread_t thread) {
    osThreadResume(thread);
}

// Create a new mutex
osMutexId_t QxOS_Mutex_Create(void) {
    return osMutexNew(NULL);
}

// Terminate the specified mutex
void QxOS_Mutex_Terminate(osMutexId_t mutex) {
    osMutexDelete(mutex);
}

// Lock the specified mutex
void QxOS_Mutex_Lock(osMutexId_t mutex) {
    osMutexAcquire(mutex, osWaitForever);
}

// Unlock the specified mutex
void QxOS_Mutex_Unlock(osMutexId_t mutex) {
    osMutexRelease(mutex);
}

// Create a new mailbox
osMessageQueueId_t QxOS_Mailbox_Create(uint32_t msg_count, uint32_t msg_size) {
    return osMessageQueueNew(msg_count, msg_size, NULL);
}

// Delete the specified mailbox
void QxOS_Mailbox_Delete(osMessageQueueId_t mq) {
    osMessageQueueDelete(mq);
}

// Send a message to the specified mailbox
void QxOS_Mailbox_Send(osMessageQueueId_t mq, void *msg) {
    osMessageQueuePut(mq, msg, 0, osWaitForever);
}

// Receive a message from the specified mailbox
void QxOS_Mailbox_Receive(osMessageQueueId_t mq, void *msg) {
    osMessageQueueGet(mq, msg, NULL, osWaitForever);
}

// Create a new timer
osTimerId_t QxOS_Timer_Create(void (*callback)(void *), osTimerType_t type, void *argument) {
    return osTimerNew((osTimerFunc_t)callback, type, argument, NULL);
}

// Delete the specified timer
void QxOS_Timer_Delete(osTimerId_t timer) {
    osTimerDelete(timer);
}

// Start the specified timer
void QxOS_Timer_Start(osTimerId_t timer, uint32_t ticks) {
    osTimerStart(timer, ticks);
}

// Stop the specified timer
void QxOS_Timer_Stop(osTimerId_t timer) {
    osTimerStop(timer);
}