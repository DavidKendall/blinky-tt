#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ttSchedConfig.h>

typedef void (*pVoidFunc_t)(void);

/* Task Control Block structure */
typedef struct schTCB {
  pVoidFunc_t task;
  uint32_t delay;
  uint32_t period;
  uint8_t invocations;
} schTCB_t;

void SysTick_Handler(void); // install own handler for SysTick
void schInit(void);         // initialise the scheduler
void schStart(void);        // start ticking
void schUpdate(void);       // update after a tick -- ISR
void schDispatch(void);     // run the next task
void schAddTask(            // add a task to the task set
  pVoidFunc_t,                // the task to add
  uint32_t,                   // the delay in ms
  uint32_t);                  // the period
void schRemoveTask(         // remove a set from the task set
  uint8_t);                   // identifier of the task to remove
void schSleep(void);        // go to sleep to save power

#ifdef __cplusplus
}
#endif

#endif
