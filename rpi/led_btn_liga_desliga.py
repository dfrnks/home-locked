import RPi.GPIO as GPIO
import time

# Valores dos pinos
led = 12 #GPIO18
btn = 16 #GPIO23

status_btn = 0
status_led = 0
       
GPIO.setmode(GPIO.BOARD)# Acho que seta pra user o GPIO da placa
 
#Define o pino LED da placa como saida
GPIO.setup(led, GPIO.OUT)
GPIO.setup(btn, GPIO.IN)
 
#rotina para acender o led
def acender_led(pino_led):
    GPIO.output(pino_led, 1)
    return
 
#rotina para apagar o led
def apagar_led(pino_led):
    GPIO.output(pino_led, 0)
    return

#Inicia loop
while(1):      
    status_btn = GPIO.input(btn)
    #print("BTN: %s" % status_btn)
    if status_btn == 1:
        status_led = GPIO.input(led)

        #print("LED: %s" % status_led)
        if status_led == 1:
            apagar_led(led)
        else:
            acender_led(led)
        time.sleep(0.3)
    
