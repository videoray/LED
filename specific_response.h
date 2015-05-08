#ifndef  LED_CONTROLLER_SPECIFIC_RESPONSE_H__
#define  LED_CONTROLLER_SPECIFIC_RESPONSE_H__

#include <stdint.h>

/** @file   LED_controller_specific_response.h
 *  @brief  Defines structures for the response packets, and a helper API
 *
 *          Device specific responses are sent in reply to a request where the 
 *          FLAG byte is < 0x80.  
 *      
 *          These responses allow for the tailoring of the protocol to minimize
 *          bandwidth, as sequential reads are not required.  Also, data not 
 *          available in the CSR can be transmitted as well. 
 */

/** Define Devices specific response packets */
typedef enum {
               /** A one byte reply, just the device type in the payload */ 
               RESPONSE_ACK_FLAG = 1,
               /** Standard motor operating parameters */
               RESPONSE_LED_STANDARD
             } LED_CONTROLLER_RESPONSES;

/** @name Response Structures
 *  
 *  Structures defining the response packets.
 */
//@{


/** LED operating parameter response */
typedef struct Response_LED_Standard_tag {
    /** Bus voltage (Volts) */
    float bus_v;
    /** Bus current (Amps) */
    float bus_i;
    /** Temperature (Degree C) */
    float temp;
    /** fault flags */
    uint8_t fault;
} Response_LED_Standard;

//@}
#endif
