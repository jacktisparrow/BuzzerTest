#define PIN_BUZZER PE15
#define EVENT_RILEVA_OGGETTO  		 				 1 << 1 // zero shift for bit0

void BuzzerInit(void);
void vTaskPuls(void * pvParameters);
void BuzzerTest(void);
void vTaskBuzzerTest(void * pvParameters);
