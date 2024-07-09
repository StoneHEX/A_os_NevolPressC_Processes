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
 * usb_parser.c
 *
 *  Created on: Jul 8, 2024
 *      Author: fil
 */

#include "main.h"
#include "A_os_includes.h"

#ifdef NEVOL_2416176_00

#include "usb_parser.h"
#include <ctype.h>

extern	NevolSystem_TypeDef	NevolSystem;

void line_set(uint8_t line_num , uint8_t line_state)
{
	if ( line_state == 0 )
	{
		switch(line_num)
		{
		case	16	:	HAL_GPIO_WritePin(OUT0_GPIO_Port,  OUT0_Pin,GPIO_PIN_RESET); break;
		case	15	:	HAL_GPIO_WritePin(OUT1_GPIO_Port,  OUT1_Pin,GPIO_PIN_RESET); break;
		case	14	:	HAL_GPIO_WritePin(OUT2_GPIO_Port,  OUT2_Pin,GPIO_PIN_RESET); break;
		case	13	:	HAL_GPIO_WritePin(OUT3_GPIO_Port,  OUT3_Pin,GPIO_PIN_RESET); break;
		case	12	:	HAL_GPIO_WritePin(OUT4_GPIO_Port,  OUT4_Pin,GPIO_PIN_RESET); break;
		case	11	:	HAL_GPIO_WritePin(OUT5_GPIO_Port,  OUT5_Pin,GPIO_PIN_RESET); break;
		case	10 	:	HAL_GPIO_WritePin(OUT6_GPIO_Port,  OUT6_Pin,GPIO_PIN_RESET); break;
		case	9	:	HAL_GPIO_WritePin(OUT7_GPIO_Port,  OUT7_Pin,GPIO_PIN_RESET); break;
		case	8	:	HAL_GPIO_WritePin(OUT8_GPIO_Port,  OUT8_Pin,GPIO_PIN_RESET); break;
		case	7	:	HAL_GPIO_WritePin(OUT9_GPIO_Port,  OUT9_Pin,GPIO_PIN_RESET); break;
		case	6 	:	HAL_GPIO_WritePin(OUT10_GPIO_Port, OUT10_Pin,GPIO_PIN_RESET); break;
		case	5 	:	HAL_GPIO_WritePin(OUT11_GPIO_Port, OUT11_Pin,GPIO_PIN_RESET); break;
		case	4 	:	HAL_GPIO_WritePin(OUT12_GPIO_Port, OUT12_Pin,GPIO_PIN_RESET); break;
		case	3 	:	HAL_GPIO_WritePin(OUT13_GPIO_Port, OUT13_Pin,GPIO_PIN_RESET); break;
		case	2 	:	HAL_GPIO_WritePin(OUT14_GPIO_Port, OUT14_Pin,GPIO_PIN_RESET); break;
		case	1 	:	HAL_GPIO_WritePin(OUT15_GPIO_Port, OUT15_Pin,GPIO_PIN_RESET); break;
		}
	}
	else
	{
		switch(line_num)
		{
		case	16	:	HAL_GPIO_WritePin(OUT0_GPIO_Port,  OUT0_Pin,GPIO_PIN_SET); break;
		case	15	:	HAL_GPIO_WritePin(OUT1_GPIO_Port,  OUT1_Pin,GPIO_PIN_SET); break;
		case	14	:	HAL_GPIO_WritePin(OUT2_GPIO_Port,  OUT2_Pin,GPIO_PIN_SET); break;
		case	13	:	HAL_GPIO_WritePin(OUT3_GPIO_Port,  OUT3_Pin,GPIO_PIN_SET); break;
		case	12	:	HAL_GPIO_WritePin(OUT4_GPIO_Port,  OUT4_Pin,GPIO_PIN_SET); break;
		case	11	:	HAL_GPIO_WritePin(OUT5_GPIO_Port,  OUT5_Pin,GPIO_PIN_SET); break;
		case	10	:	HAL_GPIO_WritePin(OUT6_GPIO_Port,  OUT6_Pin,GPIO_PIN_SET); break;
		case	9	:	HAL_GPIO_WritePin(OUT7_GPIO_Port,  OUT7_Pin,GPIO_PIN_SET); break;
		case	8	:	HAL_GPIO_WritePin(OUT8_GPIO_Port,  OUT8_Pin,GPIO_PIN_SET); break;
		case	7	:	HAL_GPIO_WritePin(OUT9_GPIO_Port,  OUT9_Pin,GPIO_PIN_SET); break;
		case	6 	:	HAL_GPIO_WritePin(OUT10_GPIO_Port, OUT10_Pin,GPIO_PIN_SET); break;
		case	5 	:	HAL_GPIO_WritePin(OUT11_GPIO_Port, OUT11_Pin,GPIO_PIN_SET); break;
		case	4 	:	HAL_GPIO_WritePin(OUT12_GPIO_Port, OUT12_Pin,GPIO_PIN_SET); break;
		case	3 	:	HAL_GPIO_WritePin(OUT13_GPIO_Port, OUT13_Pin,GPIO_PIN_SET); break;
		case	2 	:	HAL_GPIO_WritePin(OUT14_GPIO_Port, OUT14_Pin,GPIO_PIN_SET); break;
		case	1 	:	HAL_GPIO_WritePin(OUT15_GPIO_Port, OUT15_Pin,GPIO_PIN_SET); break;
		}
	}
}
void line_reset(void)
{
	HAL_GPIO_WritePin(OUT0_GPIO_Port,  OUT0_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT1_GPIO_Port,  OUT1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT2_GPIO_Port,  OUT2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT3_GPIO_Port,  OUT3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT4_GPIO_Port,  OUT4_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT5_GPIO_Port,  OUT5_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT6_GPIO_Port,  OUT6_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT7_GPIO_Port,  OUT7_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT8_GPIO_Port,  OUT8_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT9_GPIO_Port,  OUT9_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT10_GPIO_Port, OUT10_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT11_GPIO_Port, OUT11_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT12_GPIO_Port, OUT12_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT13_GPIO_Port, OUT13_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT14_GPIO_Port, OUT14_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(OUT15_GPIO_Port, OUT15_Pin,GPIO_PIN_RESET);
}

#define	CCR_VAL 		10000
#define	CCR_VAL_UNIT	(CCR_VAL / 100 )

void heater_set(uint8_t heater_num,uint8_t duty)
{
	switch(heater_num)
	{
	case 1 : TIM2->CCR1 = CCR_VAL_UNIT * duty;break;
	case 2 : TIM3->CCR4 = CCR_VAL_UNIT * duty;break;
	case 3 : TIM3->CCR3 = CCR_VAL_UNIT * duty;break;
	case 4 : TIM3->CCR2 = CCR_VAL_UNIT * duty;break;
	case 5 : TIM3->CCR1 = CCR_VAL_UNIT * duty;break;
	}
}

void heater_reset(void)
{
	TIM2->CCR1 = TIM3->CCR4 = TIM3->CCR3 = TIM3->CCR2 = TIM3->CCR1 = 0;
}

void motor_set(uint8_t motor_state)
{
	if ( motor_state )
		HAL_GPIO_WritePin(MOTOR_ON_GPIO_Port,  MOTOR_ON_Pin,GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(MOTOR_ON_GPIO_Port,  MOTOR_ON_Pin,GPIO_PIN_SET);
}

/*
 * commands
 * L <line> 1 | 0 : sets line <line> to the corresponding state
 * 	example < L 2 1 > -> sets line 2 out on
 * 	note : line ranges from 1 to 16 as on the pcb
 * H <number> <duty> : sets  <number> duty to duty
 * 	example < H 1 40 > -> sets heater 1 to 40%
 * 	note : heater ranges from 1 to 5 as on the pcb
 * 	note : duty ranges from 0 to 100
 * M 1 | 0 : sets motor to the corresponding state
 * 	example < M 1 > -> sets motor out on
 * P : get pressure
 * 	example < P > -> reply with hex pressure value
 * R : emergency reset
 * 	example < R > -> resets all
 */
uint8_t Host_decode_USB_packet(void)
{
uint16_t	pnum;
char p0;
int	p1,p2,p3;

	pnum = sscanf((char * )NevolSystem.usb_rx_buf,"< %c %d %d %d", &p0, &p1,&p2,&p3);

	switch(pnum)
	{
	case	1:
		NevolSystem.command_from_usb = toupper(p0);
		NevolSystem.param1_from_usb = 0;
		NevolSystem.param2_from_usb = 0;
		return pnum;
		break;
	case	2:
		NevolSystem.command_from_usb = toupper(p0);
		NevolSystem.param1_from_usb = p1;
		NevolSystem.param2_from_usb = 0;
		return pnum;
		break;
	case	3:
		NevolSystem.command_from_usb = toupper(p0);
		NevolSystem.param1_from_usb = p1;
		NevolSystem.param2_from_usb = p2;
		return pnum;
		break;
	default:	return 0;
	}
	return 0;
}

uint8_t Host_pack_USB_packet(uint8_t len)
{
uint32_t	i;

	for(i=0;i<len;i++)
	{
		i &= (USB_BUF_LEN-1);
		if ( NevolSystem.usb_rx_buf_rxed[i] == '<')
		{
			NevolSystem.usb_rx_buf[0] = NevolSystem.usb_rx_buf_rxed[i];
			NevolSystem.usb_rx_buf_index = 1;
			NevolSystem.usb_flags |= USB_FLAGS_HEADEROK;
		}
		else
		{
			if ((NevolSystem.usb_flags & USB_FLAGS_HEADEROK) == USB_FLAGS_HEADEROK )
			{
				NevolSystem.usb_rx_buf[NevolSystem.usb_rx_buf_index ] = NevolSystem.usb_rx_buf_rxed[i];
				if ( NevolSystem.usb_rx_buf[NevolSystem.usb_rx_buf_index] == '>')
				{
					NevolSystem.usb_flags |= USB_FLAGS_PKTCOMPLETE;
					NevolSystem.usb_flags &= ~USB_FLAGS_HEADEROK;
					NevolSystem.usb_rx_buf_index = 0;
					return	0;
				}
				NevolSystem.usb_rx_buf_index++;
			}
		}
	}
	return 1;
}

extern	uint16_t	adc_data;

uint8_t System_Process_USB_Commands(void)
{
uint8_t		ret_param = 1;

	bzero(NevolSystem.usb_tx_buf,USB_BUF_LEN);
	sprintf((char *)NevolSystem.usb_tx_buf,"%c %d %d\n\r",NevolSystem.command_from_usb,NevolSystem.param1_from_usb,NevolSystem.param2_from_usb);
	NevolSystem.usb_tx_buf_len = strlen((char *)NevolSystem.usb_tx_buf);
	switch(NevolSystem.command_from_usb)
	{
	case	'L':	// set line
		ret_param = 2;
		if ((NevolSystem.param1_from_usb < 17) && (NevolSystem.param1_from_usb > 0))
		{
			if ( NevolSystem.param2_from_usb  < 2)
			{
				hw_send_usb(NevolSystem.usb_tx_buf, NevolSystem.usb_tx_buf_len);
				line_set(NevolSystem.param1_from_usb,NevolSystem.param2_from_usb);
				ret_param = 0;
			}
		}
		break;
	case	'H':	// set heater
		ret_param = 2;
		if ((NevolSystem.param1_from_usb < 6) && (NevolSystem.param1_from_usb > 0))
		{
			if ( NevolSystem.param2_from_usb  <= 100)
			{
				hw_send_usb(NevolSystem.usb_tx_buf, NevolSystem.usb_tx_buf_len);
				heater_set(NevolSystem.param1_from_usb,NevolSystem.param2_from_usb);
				ret_param = 0;
			}
		}
		break;
	case	'M':	// set motor
		ret_param = 2;
		if (NevolSystem.param1_from_usb < 2)
		{
			hw_send_usb(NevolSystem.usb_tx_buf, NevolSystem.usb_tx_buf_len);
			motor_set(NevolSystem.param1_from_usb);
			ret_param = 0;
		}
		break;
	case	'P':	// reset all, emergency stop
		sprintf((char *)NevolSystem.usb_tx_buf,"< P 0x%04x >\r\n", adc_data);
		NevolSystem.usb_tx_buf_len = strlen((char *)NevolSystem.usb_tx_buf);
		hw_send_usb(NevolSystem.usb_tx_buf, NevolSystem.usb_tx_buf_len);
		ret_param = NevolSystem.command_from_usb;
		ret_param = 0;
		break;
	case	'R':	// reset all, emergency stop
		sprintf((char *)NevolSystem.usb_tx_buf,"<EMERGENCY RESET>\r\n");
		NevolSystem.usb_tx_buf_len = strlen((char *)NevolSystem.usb_tx_buf);
		hw_send_usb(NevolSystem.usb_tx_buf, NevolSystem.usb_tx_buf_len);
		ret_param = NevolSystem.command_from_usb;
		heater_reset();
		line_reset();
		motor_set(0);
		ret_param = 0;
		break;
	default:
		ret_param = 1;
		break;
	}
	if ( ret_param == 1 )
	{
		sprintf((char *)NevolSystem.usb_tx_buf,"<ERROR : UNKNOWN COMMAND %c (0x%02x)>\r\n",NevolSystem.command_from_usb,NevolSystem.command_from_usb);
		NevolSystem.usb_tx_buf_len = strlen((char *)NevolSystem.usb_tx_buf);
		hw_send_usb(NevolSystem.usb_tx_buf, NevolSystem.usb_tx_buf_len);
	}
	if ( ret_param == 2 )
	{
		sprintf((char *)NevolSystem.usb_tx_buf,"<ERROR : PARAMETER ERROR ON COMMAND %c %d %d>\r\n",NevolSystem.command_from_usb,NevolSystem.param1_from_usb,NevolSystem.param2_from_usb);
		NevolSystem.usb_tx_buf_len = strlen((char *)NevolSystem.usb_tx_buf);
		hw_send_usb(NevolSystem.usb_tx_buf, NevolSystem.usb_tx_buf_len);
	}
	return ret_param;
}

#endif // #ifdef NEVOL_2416176_00


