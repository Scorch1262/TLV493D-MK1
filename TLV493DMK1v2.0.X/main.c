/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F46K20
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "tlv493.h"

float XDataAnz;                                     // definiert "XDataAnz"        
float YDataAnz;                                     // definiert "YDataAnz"        
float ZDataAnz;                                     // definiert "ZDataAnz" 
float TempDataAnz;                                  // definiert "TempDataAnz" 

/*
                         Main application
 */
void main(void){
    // Initialize the device
    SYSTEM_Initialize();
    TLV493_Init();                                  // ruft "TLV493_Init" auf
    __delay_ms(500);                                // warte 500ms

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    while (1){                                          // Endloschleife
        XDataAnz = TLV493_X_GetValue();                 // schreibt ergebnis von "TLV493_X_GetValue" in "XDataAnz"        
        YDataAnz = TLV493_Y_GetValue();                 // schreibt ergebnis von "TLV493_Y_GetValue" in "YDataAnz"        
        ZDataAnz = TLV493_Z_GetValue();                 // schreibt ergebnis von "TLV493_Z_GetValue" in "ZDataAnz"
        TempDataAnz = TLV493_Temp_GetValue();           // schreibt ergebnis von "TLV493_Temp_GetValue" in "TempDataAnz"
        printf("X = %0.4fmT   ", XDataAnz);             // schreibt "X = %0.4fmT   " an UART 
        printf("Y = %0.4fmT   ", YDataAnz);             // schreibt "Y = %0.4fmT   " an UART 
        printf("Z = %0.4fmT   ",ZDataAnz);              // schreibt "Z = %0.4fmT   " an UART 
        printf("Temp = %0.2fC\r\n",TempDataAnz);        // schreibt "Z = %0.2fmT\r\n" an UART 
        __delay_ms(500);                                // warte 500ms
    }                                                   // 
}                                                       // 
/**
 End of File
*/