#ifndef QX_OS_H
#define QX_OS_H

#include "cmsis_os2.h"

typedef osThreadId_t QxOS_Thread_t;

void QxOS_BSP_Init(void);

QxOS_Thread_t QxOS_Thread_Create(void (*task)(void *), const char *name, int priority);
void QxOS_Thread_Terminate(QxOS_Thread_t thread);
void QxOS_Thread_Suspend(QxOS_Thread_t thread);
void QxOS_Thread_Resume(QxOS_Thread_t thread);

osMutexId_t QxOS_Mutex_Create(void);
void QxOS_Mutex_Terminate(osMutexId_t mutex);
void QxOS_Mutex_Lock(osMutexId_t mutex);
void QxOS_Mutex_Unlock(osMutexId_t mutex);

osMessageQueueId_t QxOS_Mailbox_Create(uint32_t msg_count, uint32_t msg_size);
void QxOS_Mailbox_Delete(osMessageQueueId_t mq);
void QxOS_Mailbox_Send(osMessageQueueId_t mq, void *msg);
void QxOS_Mailbox_Receive(osMessageQueueId_t mq, void *msg);

osTimerId_t QxOS_Timer_Create(void (*callback)(void *), osTimerType_t type, void *argument);
void QxOS_Timer_Delete(osTimerId_t timer);
void QxOS_Timer_Start(osTimerId_t timer, uint32_t ticks);
void QxOS_Timer_Stop(osTimerId_t timer);

#endif // QX_OS_H