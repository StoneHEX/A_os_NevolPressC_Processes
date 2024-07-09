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
 * process_1_io.c
 *
 *  Created on: May 20, 2024
 *      Author: fil
 */

#include "main.h"
#include "A_os_includes.h"

#ifdef NEVOL_2416176_00
#include "usb_parser.h"

NevolSystem_TypeDef	NevolSystem;
extern	TIM_HandleTypeDef htim2;
extern	TIM_HandleTypeDef htim3;

uint16_t	adc_data = 0;

void process_1_io(uint32_t process_id)
{
uint32_t	wakeup,flags;
uint8_t		led_counter=0;
	create_timer(TIMER_ID_0,100,TIMERFLAGS_FOREVER | TIMERFLAGS_ENABLED);
	allocate_hw(HW_USB_DEVICE,0);
	hw_set_usb_rx_buffer(NevolSystem.usb_rx_buf_rxed);
	allocate_hw(HW_ADC2,0);
	InternalAdc_Start();

	TIM2->CCR1 = TIM3->CCR4 = TIM3->CCR3 = TIM3->CCR2 = TIM3->CCR1 = 0;
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	while(1)
	{
		wait_event(EVENT_TIMER|EVENT_USB_DEVICE_IRQ|EVENT_ADC2_IRQ);
		get_wakeup_flags(&wakeup,&flags);
		if (( wakeup & WAKEUP_FROM_TIMER) == WAKEUP_FROM_TIMER)
		{
			led_counter++;
			if ( led_counter == 8 )
			{
				HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_RESET);
			}
			if ( led_counter == 9 )
			{
				led_counter = 0;
				HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_SET);
			}
		}
		if (( wakeup & WAKEUP_FROM_USB_DEVICE_IRQ) == WAKEUP_FROM_USB_DEVICE_IRQ)
		{
			if ( Host_pack_USB_packet(hw_UsbGetRXLen()) == 0 )
				if ( Host_decode_USB_packet() )
					System_Process_USB_Commands();
		}
		if (( wakeup & WAKEUP_FROM_ADC2_IRQ) == WAKEUP_FROM_ADC2_IRQ)
		{
			adc_data = (uint16_t )flags;
		}
	}
}

#endif // #ifdef	NEVOL_2416176
