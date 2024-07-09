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
 * usb_parser.h
 *
 *  Created on: Jul 8, 2024
 *      Author: fil
 */


#ifndef STM32G491_PRESSC_USB_PARSER_H_
#define STM32G491_PRESSC_USB_PARSER_H_

#define		USB_BUF_LEN			48
#define		MAILBOX_ID			0
#define		MAILBOX_LEN			32

typedef struct
{
	uint8_t 		sensors_status;
	uint8_t 		get_interval;
	uint8_t 		get_interval_reload;
	uint8_t 		sensor_selector;
	uint8_t 		line_selector;
	uint8_t 		board_selector;
	uint8_t			number_of_sensors;
	uint8_t			number_of_lines;
	uint32_t 		number_of_samples;
	uint32_t 		valid_samples;
	uint32_t 		invalid_samples;
	/* USB section */
	uint8_t			command_from_usb;
	uint8_t			board_from_usb;
	uint8_t			param1_from_usb;
	uint8_t			param2_from_usb;
	uint8_t			usb_rx_buf_rxed[USB_BUF_LEN];
	uint8_t			usb_rx_buf[USB_BUF_LEN];
	uint8_t			usb_rx_buf_len;
	uint8_t			usb_rx_buf_index;
	uint8_t			usb_tx_buf[USB_BUF_LEN];
	uint8_t			usb_tx_buf_len;
	uint8_t 		usb_flags;
	uint32_t		xtract_line_selector;
	uint32_t		xtract_sensor_selector;
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


extern	uint8_t Host_decode_USB_packet(void);
extern	uint8_t Host_pack_USB_packet(uint8_t len);
extern	uint8_t System_Process_USB_Commands(void);

#endif /* STM32G491_PRESSC_USB_PARSER_H_ */
