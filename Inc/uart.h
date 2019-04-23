// ****************************************************************************
/// \file      uart.h
///
/// \brief     uart module
///
/// \details   -
///
/// \author    Nico Korn
///
/// \version   0.1
///
/// \date      20190124
/// 
/// \copyright Copyright (C) 2019  by "Reichle & De-Massari AG", 
///            all rights reserved.
///
/// \pre       
///
/// \bug       
///
/// \warning   
///
/// \todo      
///
// ****************************************************************************

// Define to prevent recursive inclusion **************************************
#ifndef __PCU_BUS_UART_H
#define __PCU_BUS_UART_H

// Include ********************************************************************

// Exported defines ***********************************************************
#define MACDSTFIELD              ( 8 )
#define TOTALLENGTHLSBFIELD      ( 17 )
#define TOTALLENGTHMSBFIELD      ( 16 )
#define MACSRCADRLENGTH          ( 6 )
#define MACDSTADRLENGTH          ( 6 )
#define ETHTYPELENGTH            ( 2 )
#define PREAMBLESFDLENGTH        ( 8 )
#define CRC32LENGTH              ( 4 )
#define ETHSIZE                  ( 1522 )    // The original Ethernet IEEE 802.3 
                                             // standard defined the minimum 
                                             // Ethernet frame size as 64 bytes 
                                             // and the maximum as 1518 bytes. 
                                             // The maximum was later increased 
                                             // to 1522 bytes to allow for VLAN 
                                             // tagging. The minimum size of an 
                                             // Ethernet frame that carries an 
                                             // ICMP packet is 74 bytes.
                                             // +8 bytes for preamble & sfd
#define MINSIZE                  ( PREAMBLESFDLENGTH+CRC32LENGTH )
#define TYPEARP                  ( 0806 )
#define ETHTYPEFIELDMSB          ( 12 )
#define ETHTYPEFIELDLSB          ( 13 )
#define MINPAYLOAD               ( 46 )

#define UART_PIN_BUS_RTS         GPIO_PIN_3
#define UART_PIN_BUS_CTS         GPIO_PIN_4

// Exported types *************************************************************
typedef struct BUS_UART_RX_s
{
   uint8_t        uartState;                       ///< state of the uart communication    0 = idle, 1 = busy           
   uint8_t*       buffer;                          ///< pointer to buffer
   uint16_t       bufferSize;                      ///< size to the pointed buffer
   uint16_t       frameSize;                       ///< size of the complete eth frame
   uint16_t       byteCounter;                     ///< size of the data field in the message                             
} BUS_UART_RX_t;

// Exported functions *********************************************************
uint8_t              bus_uart_init              ( void );
uint8_t              bus_uartInitFloating       ( void );
void                 bus_uart_setRs485          ( uart_cmd_t setter );
UART_HandleTypeDef*  bus_uart_getHandler        ( void );
uint16_t             bus_uart_getSize           ( void );
uint8_t*             bus_uart_getBufferpointer  ( void );
uint16_t             bus_uart_getBuffersize     ( void );
void                 bus_uart_resetRx           ( void );
void                 bus_uart_send              ( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size );
void                 bus_uart_receive           ( UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size );
void                 bus_uart_TxCpltCallback    ( void );
void                 bus_uart_RxCpltCallback    ( void );
void                 bus_uart_IdleLnCallback    ( void );
uint32_t             bus_uart_calcCRC           ( uint32_t* dataPointer, uint32_t dataLength );
uint8_t              bus_uart_frameCheck        ( uint8_t* framePointer, uint16_t frameLength );
void                 uart_output                ( uint8_t* buffer, uint16_t length );
#endif // __PCU_BUS_UART_H