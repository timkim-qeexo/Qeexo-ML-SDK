#ifndef QX_OS_H
#define QX_OS_H

void QxOS_BSP_Init(void);

void QxOS_Thread_Create(void (*task)(void *), const char *name, int priority);
void QxOS_Thread_Terminate(void);
void QxOS_Thread_Suspend(void);
void QxOS_Thread_Resume(void);

void QxOS_Mutex_Create(void);
void QxOS_Mutex_Terminate(void);
void QxOS_Mutex_Lock(void);
void QxOS_Mutex_Unlock(void);

void QxOS_Mailbox_Create(void);
void QxOS_Mailbox_Delete(void);
void QxOS_Mailbox_Send(void *msg);
void QxOS_Mailbox_Receive(void *msg);

void QxOS_Timer_Create(void (*callback)(void *), int period);
void QxOS_Timer_Delete(void);
void QxOS_Timer_Start(void);
void QxOS_Timer_Stop(void);

#endif // QX_OS_H