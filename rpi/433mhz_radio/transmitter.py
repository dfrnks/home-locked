import piVirtualWire.piVirtualWire as piVirtualWire
import time
import pigpio

pi = pigpio.pi()

tx = piVirtualWire.tx(pi, 18, 2000) # Set pigpio instance, TX module GPIO pin and baud rate

msg = "42"
n = 0
while True:
    n+=1
    #msg = raw_input('Digite uma mensagem: ')
    print("%s%d" % (msg, n))
    tx.put("%s%d" % (msg, n))
    tx.waitForReady()
    time.sleep(4)

tx.cancel()
pi.stop()
