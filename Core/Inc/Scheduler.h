/*
 * Scheduler.h
 *
 *  Created on: Sep 12, 2024
 *      Author: boony
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>

uint32_t getScheduledEvents();
void addSchedulerEvent(uint32_t);
void removeSchedulerEvent(uint32_t);

//#define LED_TOGGLE_EVENT (1<<0)
//#define LED_DELAY_EVENT (1<<1)
//#define BUTTON_POLL_EVENT (1<<2)
//#define DEVICE_ID_AND_TEMP_EVENT (1<<3)

#define GAME_HOMESCREEN_EVENT (1<<0)
#define GAME_START_EVENT (1<<1)
#define GAME_OVER_EVENT (1<<2)


#endif /* SCHEDULER_H_ */
