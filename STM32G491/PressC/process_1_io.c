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

#include "command_parser.h"
#include "nevol_system.h"

NevolSystem_TypeDef	NevolSystem;
extern	TIM_HandleTypeDef htim2;
extern	TIM_HandleTypeDef htim3;

uint16_t	adc_data = 0;

extern	void buzzer_timer_callback(void);

void process_1_io(uint32_t process_id)
{
uint32_t	wakeup,flags;
uint8_t		led_counter=0;
	create_timer(TIMER_ID_0,100,TIMERFLAGS_FOREVER | TIMERFLAGS_ENABLED);
	allocate_hw(HW_USB_DEVICE,0);
	hw_set_usb_rx_buffer(NevolSystem.usb_rx_buf_rxed);
	allocate_hw(HW_ADC2,0);
	InternalAdc_Start();
	allocate_hw(HW_UART2,0);
	hw_receive_uart_sentinel(HW_UART2,NevolSystem.rs485_rx_buf,RS485_BUF_LEN,'<','>',RS485_TIMEOUT);
	set_after_check_timers_callback(buzzer_timer_callback);

	TIM2->CCR1 = TIM3->CCR4 = TIM3->CCR3 = TIM3->CCR2 = TIM3->CCR1 = 0;
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	while(1)
	{
		wait_event(EVENT_TIMER|EVENT_USB_DEVICE_IRQ|EVENT_UART2_IRQ|EVENT_ADC2_IRQ);
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
			{
				if ( parse_packet(NevolSystem.usb_rx_buf) )
				{
					System_Process_host_Commands();
					hw_send_usb(NevolSystem.system_tx_buf, NevolSystem.system_tx_buf_len);
				}
			}
		}

		if (( wakeup & WAKEUP_FROM_UART2_IRQ) == WAKEUP_FROM_UART2_IRQ)
		{
			if (( flags & WAKEUP_FLAGS_UART_RX) == WAKEUP_FLAGS_UART_RX)
			{
				if ( parse_packet(NevolSystem.rs485_rx_buf) )
				{
					System_Process_host_Commands();
					hw_send_uart(HW_UART2,NevolSystem.system_tx_buf, NevolSystem.system_tx_buf_len);
				}
			}
		}

		if (( wakeup & WAKEUP_FROM_ADC2_IRQ) == WAKEUP_FROM_ADC2_IRQ)
		{
			NevolSystem.adc_data = (uint16_t )flags;
		}
	}
}

#endif // #ifdef	NEVOL_2416176
