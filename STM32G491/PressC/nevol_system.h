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
 * nevol_system.h
 *
 *  Created on: Jul 9, 2024
 *      Author: fil
 */

#ifndef STM32G491_PRESSC_NEVOL_SYSTEM_H_
#define STM32G491_PRESSC_NEVOL_SYSTEM_H_

#define		USB_BUF_LEN			60
#define		RS485_BUF_LEN		USB_BUF_LEN
#define		RS485_TIMEOUT		1000
#define		MAILBOX_ID			0
#define		MAILBOX_LEN			32

typedef struct
{
	uint16_t 		buzzer_timer;
	/* USB from Host section */
	uint8_t			usb_rx_buf_rxed[USB_BUF_LEN];
	uint8_t			usb_rx_buf[USB_BUF_LEN];
	uint8_t			usb_rx_buf_len;
	uint8_t			usb_rx_buf_index;
	uint8_t			usb_tx_buf[USB_BUF_LEN];
	uint8_t			usb_tx_buf_len;
	uint8_t 		usb_flags;
	/* RS485 from Host section */
	uint8_t			rs485_rx_buf_rxed[RS485_BUF_LEN];
	uint8_t			rs485_rx_buf[RS485_BUF_LEN];
	uint8_t			rs485_rx_buf_len;
	uint8_t			rs485_rx_buf_index;
	uint8_t			rs485_tx_buf[RS485_BUF_LEN];
	uint8_t			rs485_tx_buf_len;
	uint8_t 		rs485_flags;
	/* system command and parameters */
	uint8_t			system_tx_buf[USB_BUF_LEN];
	uint8_t			system_tx_buf_len;
	uint8_t			system_rx_buf[USB_BUF_LEN];
	uint16_t		command_from_host;
	uint16_t		param1_from_host;
	uint16_t		param2_from_host;
	/* mailbox */
	uint8_t			mailbox_out[MAILBOX_LEN];
}NevolSystem_TypeDef;

/* usb_flags */
#define	USB_FLAGS_USB_CONNECTED	0x01
#define	USB_FLAGS_LOGOSENT		0x02
#define	USB_FLAGS_SENDINFO		0x04
#define	USB_FLAGS_SENDDATA		0x08
#define	USB_FLAGS_SENDREPLY		0x10
// not used						0x20
#define	USB_FLAGS_HEADEROK		0x40
#define	USB_FLAGS_PKTCOMPLETE	0x80

typedef struct
{
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
}NevolSystemGPIO_TypeDef;

#endif /* STM32G491_PRESSC_NEVOL_SYSTEM_H_ */
