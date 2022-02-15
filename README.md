# TaskBuzzer 
![immagine buzzer](https://img.directindustry.it/images_di/photo-m2/79967-16366410.jpg)

## Un buzzer o beeper è un dispositivo di segnalazione audio, che può essere meccanico, elettromeccanico, o piezoelettrico. I tipici utilizzi del buzzer includono dispositivi di allarme, timer, e PC speaker per i feedback sugli input dell'utente, come pressione dei tasti o click del mouse, nei vecchi personal computer.

### Il buzzer viene alimentato con un tensione di 5v ed riceve il sengnale dal pin PE15.
## schema elettrico:
![immagine schema elettrico](https://github.com/jacktisparrow/BuzzerTest/blob/main/schema%20buzz.png)
## schema montaggio:
![immagine schema elettrico](https://github.com/jacktisparrow/BuzzerTest/blob/main/immagine%20schema%20montaggio.jpg)
Utilizzo il sistema di RTOS degli eventgroup per gestire gli eventi , in questo caso l'eventgroup xServo che modifica il bit assegnato EVENT_RILEVA_OGGETTO che quando il pulsanti sarà premuto fara abilitare il flag che farà a sua volta sonare il buzzer grazie al vTaskBuzzerTest che utilizzando la 
Questa task genera un segnale acustico non appena il pulsante viene premuto grazie all’utilizzo del buzzer. 
Il buzzer è collegato al pin PE15 ed emette un semplice “beep” (HIGH, delay e LOW) quando riceve il flag dalla TaskRilevaOggetto.
