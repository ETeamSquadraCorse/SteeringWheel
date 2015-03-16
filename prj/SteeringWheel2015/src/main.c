/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "errors.h"

#define STATUS_TEST_HARDWARE  0x0u
#define STATUS_CHECK_COM      0x1u
#define STATUS_CHECK_CTRL     0x2u
#define STATUS_ERROR		  0x3u

int main (void)
{
	/* 
	 * The finite state machine status. Init status is set in the
	 * application configuration area.
	 */
	
	uint8_t fsm_status = INIT_STATUS;
	
	/* Initialize the board */

	board_init();

	/* Loop forever within the finite state machine */
	
	while(1){
		switch(fsm_status){
			
			case STATUS_TEST_HARDWARE:
				/* 
				 * This status is reserved to special cases
				 * in which a full hardware test has to be 
				 * performed during the execution of the 
				 * software.
				 */
				break;
			
			case STATUS_CHECK_COM:
				/*
				 * Incoming messages are checked by the software
				 * and, when needed, messages are dispatched
				 * as requested.
				 */
				break;
				
		    case STATUS_CHECK_CTRL:
				/*
				 * Steering wheel controls are checked
				 * and processed by the software which performs
				 * the needed operations 
				 */
				break;
			
			case STATUS_ERROR:
				/* 
				 * Special error cases and/or exceptions
				 * are handled here. An error handler logs
				 * the error and chooses how to handle it.
				 */
				break;
						
			default:
			    /* This has to be considered as an error */
				fsm_status = STATUS_ERROR;
		}
	}
}
