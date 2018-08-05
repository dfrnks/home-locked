import piVirtualWire.piVirtualWire as piVirtualWire
import time
import pigpio

pi = pigpio.pi()
rx = piVirtualWire.rx(pi, 18, 2000) # Set pigpio instance, TX module GPIO pin and baud rate

while True:
    while rx.ready():
        msg = ''.join(chr(i) for i in rx.get())
        print(msg)
    print("Aguardando...")
    time.sleep(0.5)

rx.cancel()
pi.stop()
