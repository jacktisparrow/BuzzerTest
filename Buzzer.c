//=== INCLUDES =============================================================================
#include "FreeRTOSConfig.h"             // ARM.FreeRTOS::RTOS:Config
#include "FreeRTOS.h"   
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "timer.h"
#include "event_groups.h"               // ARM.FreeRTOS::RTOS:Event Groups
#include <stdio.h>
#include "Led.h"
#include "Arduino.h"
#include "Buzzer.h"
#include "Puls.h"

EventGroupHandle_t xServo;

void BuzzerInit(void){
	pinMode(PIN_BUZZER,OUTPUT);								//inizzialozzo il buzzer
}

	
void BuzzerTest(void){ 
	xTaskCreate(vTaskPuls, /* Pointer to the function that implements the task.              */
	"Task 1 Test Buzzer",    /* Text name for the task.  This is to facilitate debugging only. */
	50,   /* Stack depth in words.                */
	NULL,  /* We are not using the task parameter. */
	1,     /* This task will run at priority 1.    */
	NULL); /* We are not using the task handle.    */
	xTaskCreate(vTaskBuzzerTest, /* Pointer to the function that implements the task.              */
	"Task 1 Test Buzzer",    /* Text name for the task.  This is to facilitate debugging only. */
	50,   /* Stack depth in words.                */
	NULL,  /* We are not using the task parameter. */
	1,     /* This task will run at priority 1.    */
	NULL); /* We are not using the task handle.    */
	
	xServo=xEventGroupCreate();								//creazione eventGroup
}

void vTaskPuls(void * pvParameters){
	while(1){
		if(SwLeftClick()) 																									//verifico click pulsante sinistro
			xEventGroupSetBits(xServo,EVENT_RILEVA_OGGETTO);									//setto bit event group
	}
}
void vTaskBuzzerTest(void * pvParameters){
	const EventBits_t xBitsToWaitFor = EVENT_RILEVA_OGGETTO; 
	while(1){
		xEventGroupWaitBits(xServo,xBitsToWaitFor,pdTRUE,pdTRUE,portMAX_DELAY); 		//aspetto bit event group
		digitalWrite(PIN_BUZZER, HIGH);																							//buzzer on 
		vTaskDelay(300);
		digitalWrite(PIN_BUZZER, LOW);																							//buzzer off
	
	}
}