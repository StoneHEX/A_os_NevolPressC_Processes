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
 * process_4.c
 *
 *  Created on: May 20, 2024
 *      Author: fil
 */

#include "main.h"
#include "A_os_includes.h"

#ifdef	NEVOL_2416176_00

void process_4(uint32_t process_id)
{
uint32_t	wakeup,flags;

	allocate_hw(HW_DAC,0);
	IntDac_Start();
	buzzer_off();


	create_timer(TIMER_ID_0,100,TIMERFLAGS_FOREVER | TIMERFLAGS_ENABLED);
	while(1)
	{
		wait_event(EVENT_TIMER|EVENT_ADC2_IRQ);
		get_wakeup_flags(&wakeup,&flags);
		if (( wakeup & WAKEUP_FROM_TIMER) == WAKEUP_FROM_TIMER)
		{

		}

	}
}
#endif // #ifdef	NEVOL_2416176_00
