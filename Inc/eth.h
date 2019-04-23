// ****************************************************************************
/// \file      eth.h
///
/// \brief     bus uart module
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
#ifndef __ETH_H
#define __ETH_H

// Include ********************************************************************

// Exported defines ***********************************************************

// Exported types *************************************************************

// Exported functions *********************************************************
void     eth_init       ( void );
void     eth_output     ( uint8_t* buffer, uint16_t length );
void     eth_link_update( void );
#endif // __ETH_H