#include "QxOS.h"

// Initialize Board Support Package
void QxOS_BSP_Init(void) {
    // Initialize the CMSIS-RTOS2 kernel
    osKernelInitialize();
}

/**
 * @brief Create a new thread.
 * 
 * @param task The task function to be executed by the thread.
 * @param name The name of the thread.
 * @param priority The priority of the thread.
 * @return QxOS_Thread_t The created thread.
 */
QxOS_Thread_t QxOS_Thread_Create(void (*task)(void *), const char *name, int priority) {
    osThreadAttr_t attr = {
        .name = name,
        .priority = (osPriority_t)priority
    };
    return osThreadNew((osThreadFunc_t)task, NULL, &attr);
}

/**
 * @brief Terminate the specified thread.
 * 
 * @param thread The thread to be terminated.
 */
void QxOS_Thread_Terminate(QxOS_Thread_t thread) {
    osThreadTerminate(thread);
}

/**
 * @brief Suspend the specified thread.
 * 
 * @param thread The thread to be suspended.
 */
void QxOS_Thread_Suspend(QxOS_Thread_t thread) {
    osThreadSuspend(thread);
}

/**
 * @brief Resume the specified thread.
 * 
 * @param thread The thread to be resumed.
 */
void QxOS_Thread_Resume(QxOS_Thread_t thread) {
    osThreadResume(thread);
}

/**
 * @brief Create a new mutex.
 * 
 * @return osMutexId_t The created mutex.
 */
osMutexId_t QxOS_Mutex_Create(void) {
    return osMutexNew(NULL);
}

/**
 * @brief Terminate the specified mutex.
 * 
 * @param mutex The mutex to be terminated.
 */
void QxOS_Mutex_Terminate(osMutexId_t mutex) {
    osMutexDelete(mutex);
}

/**
 * @brief Lock the specified mutex.
 * 
 * @param mutex The mutex to be locked.
 */
void QxOS_Mutex_Lock(osMutexId_t mutex) {
    osMutexAcquire(mutex, osWaitForever);
}

/**
 * @brief Unlock the specified mutex.
 * 
 * @param mutex The mutex to be unlocked.
 */
void QxOS_Mutex_Unlock(osMutexId_t mutex) {
    osMutexRelease(mutex);
}

/**
 * @brief Create a new mailbox.
 * 
 * @param msg_count The number of messages the mailbox can hold.
 * @param msg_size The size of each message.
 * @return osMessageQueueId_t The created mailbox.
 */
osMessageQueueId_t QxOS_Mailbox_Create(uint32_t msg_count, uint32_t msg_size) {
    return osMessageQueueNew(msg_count, msg_size, NULL);
}

/**
 * @brief Delete the specified mailbox.
 * 
 * @param mq The mailbox to be deleted.
 */
void QxOS_Mailbox_Delete(osMessageQueueId_t mq) {
    osMessageQueueDelete(mq);
}

/**
 * @brief Send a message to the specified mailbox.
 * 
 * @param mq The mailbox to send the message to.
 * @param msg The message to be sent.
 */
void QxOS_Mailbox_Send(osMessageQueueId_t mq, void *msg) {
    osMessageQueuePut(mq, msg, 0, osWaitForever);
}

/**
 * @brief Receive a message from the specified mailbox.
 * 
 * @param mq The mailbox to receive the message from.
 * @param msg The buffer to store the received message.
 */
void QxOS_Mailbox_Receive(osMessageQueueId_t mq, void *msg) {
    osMessageQueueGet(mq, msg, NULL, osWaitForever);
}

/**
 * @brief Create a new timer.
 * 
 * @param callback The callback function to be called when the timer expires.
 * @param type The type of the timer (one-shot or periodic).
 * @param argument The argument to be passed to the callback function.
 * @return osTimerId_t The created timer.
 */
osTimerId_t QxOS_Timer_Create(void (*callback)(void *), osTimerType_t type, void *argument) {
    return osTimerNew((osTimerFunc_t)callback, type, argument, NULL);
}

/**
 * @brief Delete the specified timer.
 * 
 * @param timer The timer to be deleted.
 */
void QxOS_Timer_Delete(osTimerId_t timer) {
    osTimerDelete(timer);
}

/**
 * @brief Start the specified timer.
 * 
 * @param timer The timer to be started.
 * @param ticks The number of ticks after which the timer expires.
 */
void QxOS_Timer_Start(osTimerId_t timer, uint32_t ticks) {
    osTimerStart(timer, ticks);
}

/**
 * @brief Stop the specified timer.
 * 
 * @param timer The timer to be stopped.
 */
void QxOS_Timer_Stop(osTimerId_t timer) {
    osTimerStop(timer);
}