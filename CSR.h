#ifndef LED_CONTROLLER_CSR__
#define LED_CONTROLLER_CSR__

/** @file   led_controller/CSR.h
 *  @brief  Config and Status register implementation
 *
 *          The CSR structure presents the interface for the config and status 
 *          registers which are accessible through VideoRay communication protocol
 *          read/writes. 
 *          
 *          The CSR register file acts as an abstraction layer for device state.
 *          Registers are modified in-code or through a communication channel, 
 *          The CSR state is then used to modify actual device state through a call
 *          to the CSR_state_propigate() function.
 */

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//BE SURE TO DOULBE CHECK THE API FUNCTIONS THAT USE CSR ADDRESSES ANYTIME THE
//CSR STRUCTURE CHANGES
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <stdint.h>

#include <videoray/applib/protocol_vr_csr.h>


#define CSR_SAVE_SETTINGS_PASSWORD 0x1234
#define CSR_SAVE_SETTINGS_COMPLETE 0x4321
 
#define LED_COMMAND 0xbb

typedef struct CSR_LED_Controller_tag {
    /* Control Section, values sent at high update rates  */
    float LED_bank_1_setpoint_target;           // pwr percentage 0 - 1  (RW)
    float LED_bank_2_setpoint_target;           // pwr percentage 0 - 1  (RW)
    float LED_bank_3_setpoint_target;           // pwr percentage 0 - 1  (RW)
    float bus_v;                // volts        (R)
    float bus_i;                // amps         (R)
    float temp;                 // deg C        (R)
    uint32_t fault;             // fault flags  (R)
    float LED_bank_1_setpoint_actual;           // pwr percentage 0 - 1  (RW)
    float LED_bank_2_setpoint_actual;           // pwr percentage 0 - 1  (RW)
    float LED_bank_3_setpoint_actual;           // pwr percentage 0 - 1  (RW)
    char reserved1[36];
    // application config parameters
    uint16_t led_ID;                // ordinal  (RW)
    char reserved2[2];
    uint8_t system_flags;       // Bitfield     (RW)
    char reserved3[3];
    uint32_t fault_interlock;      // password (RW)

    char reserved4[8];

    // led control parameters
    uint8_t control_flags;            // Bitfield     (RW)
    uint8_t led_bank_count;            // count       (RW)
    char reserved5[2];
    float    LED_bank_1_power_rating;       // Watts        (RW)
    float    LED_bank_2_power_rating;       // Watts        (RW)
    float    LED_bank_3_power_rating;       // Watts        (RW)
    float    LED_bank_1_pwm_freq;           // Hz           (RW)
    float    RESERVED_LED_bank_2_pwm_freq;
    float    RESERVED_LED_bank_3_pwm_freq;
    uint8_t  LED_bank_1_setpoint_limit_min; //percentage 0 - 100 (RW)
    uint8_t  LED_bank_2_setpoint_limit_min; //percentage 0 - 100 (RW)
    uint8_t  LED_bank_3_setpoint_limit_min; //percentage 0 - 100 (RW)
    uint8_t  LED_bank_1_setpoint_limit_max; //percentage 0 - 100 (RW)
    uint8_t  LED_bank_2_setpoint_limit_max; //percentage 0 - 100 (RW)
    uint8_t  LED_bank_3_setpoint_limit_max; //percentage 0 - 100 (RW)

    char reserved6[30];

    // fault control parameters
    uint32_t fault_control;              // flag     (RW)
    uint8_t undervoltage_trigger;        // volts    (RW)
    uint8_t overvoltage_trigger;         // volts    (RW)
    uint8_t overcurrent_trigger;         // amps     (RW)
    uint8_t temp_trigger;                // deg C    (RW)
    char reserved7[4];
    uint32_t undervoltage_err_cnt;       // count    (R)
    uint32_t overvoltage_err_cnt;        // count    (R)
    uint32_t overcurrent_err_cnt;        // count    (R)
    uint32_t temp_err_cnt;               // count    (R)
    char reserved8[28];

    uint32_t comms_sync1_err_cnt;          // count (R)
    uint32_t comms_sync2_err_cnt;          // count (R)
    uint32_t comms_headerxsum_err_cnt;     // count (R)
    uint32_t comms_overrun_err_cnt;        // count (R)
    uint32_t comms_payloadxsum_err_cnt;    // count (R)
    uint16_t comms_err_flag;
    uint16_t save_settings;                // code (W)
    /** START OF PROTOCOL STANDARD REGISTERS **/
    /* Address: 0xF0 */
    uint32_t  custom_command;       //  (W)  Special Register
    uint32_t  FACTORY_SERVICE_DATA; //  (R)  Device specific service data
    uint16_t  CONFIG_DATA_SIZE;     //  (R)
    uint8_t   CONFIG_DATA;          //  (R)  Special Register
    uint8_t   FIRMWARE_VERSION;     //  (R)  Special Register
    uint8_t   NODE_ID;              //  (RW) Special Register
    uint8_t   GROUP_ID;             //  (RW) Special Register
    uint16_t  UTILITY;              //  (W)  Special Register
 }  CSR_LED_Controller;
 
#endif
