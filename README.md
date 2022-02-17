# TaskBuzzer 
![immagine buzzer](https://img.directindustry.it/images_di/photo-m2/79967-16366410.jpg)

### Un buzzer o beeper è un dispositivo di segnalazione audio, che può essere meccanico, elettromeccanico, o piezoelettrico. I tipici utilizzi del buzzer includono dispositivi di allarme, timer, e PC speaker per i feedback sugli input dell'utente, come pressione dei tasti o click del mouse, nei vecchi personal computer.

### Il buzzer viene alimentato con un tensione di 5v ed riceve il sengnale dal pin PE15.
## Schema elettrico:
![immagine schema elettrico](https://github.com/jacktisparrow/BuzzerTest/blob/main/schema%20buzz.png)
## Schema montaggio:
![immagine schema elettrico](https://github.com/jacktisparrow/BuzzerTest/blob/main/immagine%20schema%20montaggio.jpg)
### Per gestire gli eventi utilizzo gli eventgroupintegrati nel sistema di RTOS , in questo caso l'evento è il pulsante premuto.
### il task vTaskBuzzerTest è in attesa di un evento (vTaskPuls) , quando questo evento si verifica viene messo a 1 il bit dell'eventgroup cosi facendo eseguire il task vTaskBuzzerTest.

### L'eventgroup è stato chiamato  xServo e (EVENT_RILEVA_OGGETTO) il bit 1 da modificare.
### La pressione del pulsante(vTaskPuls) è l'evento che attende vTaskBuzzerTest, che quindi vede il flag attivo che fa a sua volta eseguire il task vTaskBuzzerTest e quindi sonare il buzzer.

### vTaskBuzzerTest utilizza la digitalWrite per mandare un segnale di alto livello sul pin PE15 collegato al buzzer che farà il beep per 300 milli secondi e sucessivamente digitalWrite che manda una segnale basso e quindi interrompe il beep.

### Per l’integrazione con il progetto Rullo Trasportatore bisogna rimuovere la pressione del pulsante quindi il vTaskPuls e mantenere la costante EVENT_RILEVA_OGGETTO che farà attivare il flag quando il sensore a ultrasuoni rileva un oggetto e quindi successivamente eseguire il vTaskBuzzerTest per ciò il beep del buzzer.




