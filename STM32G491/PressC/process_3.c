/* 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Project : A_os
*/
/*
 * process_3.c
 *
 *  Created on: May 20, 2024
 *      Author: fil
 */

#include "main.h"
#include "A_os_includes.h"

#ifdef	NEVOL_2416176_00

void process_3(uint32_t process_id)
{
uint32_t	wakeup,flags;

	create_timer(TIMER_ID_0,5000,TIMERFLAGS_FOREVER | TIMERFLAGS_ENABLED);
	while(1)
	{
		wait_event(EVENT_TIMER);
		get_wakeup_flags(&wakeup,&flags);
		if (( wakeup & WAKEUP_FROM_TIMER) == WAKEUP_FROM_TIMER)
		{
#ifdef INTERNAL_RTC_ENABLED
			A_RTC_get_time();
			A_RTC_set_alarm(RTC_WEEKDAY_MONDAY, 0,0,2);
#endif
		}
	}
}

#endif // #ifdef	NEVOL_2416176
