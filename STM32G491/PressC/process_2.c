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
 * process_2.c
 *
 *  Created on: May 20, 2024
 *      Author: fil
 */

#include "main.h"
#include "A_os_includes.h"

#ifdef	NEVOL_2416176_00
#define	BUF_SIZE_FLASH	1024

uint8_t	buf_w1[BUF_SIZE_FLASH] ,buf_w2[BUF_SIZE_FLASH] , buf_r[BUF_SIZE_FLASH];

#define	DO_WRITE	1

uint16_t check_flash(uint8_t * write_buf , uint16_t len)
{
uint16_t	i;
	for(i=0;i<len;i++)
	{
		if ( write_buf[i] != buf_r[i])
			return i;
	}
	return 0;
}

void process_2(uint32_t process_id)
{
uint32_t	wakeup,flags;
uint32_t	toggle=0,i;

	i2c_24aaxxx_init(HW_I2C1,I2CFLASH_DEVICE0);
	for(i=0;i<BUF_SIZE_FLASH;i++)
	{
		buf_w1[i] = i+0x60;
		buf_w2[i] = i+0x80;
	}
	create_timer(TIMER_ID_0,200,TIMERFLAGS_FOREVER | TIMERFLAGS_ENABLED);
	while(1)
	{
		wait_event(EVENT_TIMER);
		get_wakeup_flags(&wakeup,&flags);
		if (( wakeup & WAKEUP_FROM_TIMER) == WAKEUP_FROM_TIMER)
		{
			switch(toggle)
			{
			case 0 :
#ifdef DO_WRITE
				i2c_24aaxxx_write(HW_I2C1,0,buf_w1,BUF_SIZE_FLASH);
#endif
				toggle++;
				break;
			case 1 :
				i2c_24aaxxx_read(HW_I2C1,0,buf_r,BUF_SIZE_FLASH);
				toggle++;
				break;
			case 2 :
				check_flash(buf_w1,BUF_SIZE_FLASH);
				toggle++;
				break;
			case 3 :
#ifdef DO_WRITE
				i2c_24aaxxx_write(HW_I2C1,0,buf_w2,BUF_SIZE_FLASH);
#endif
				toggle++;
				break;
			case 4 :
				i2c_24aaxxx_read(HW_I2C1,0,buf_r,BUF_SIZE_FLASH);
				toggle++;
				break;
			case 5 :
				check_flash(buf_w2,BUF_SIZE_FLASH);
				toggle++;
				break;
			default:
				toggle = 0;
				break;
			}
		}
	}
}

#endif // #ifdef	NEVOL_2416176
