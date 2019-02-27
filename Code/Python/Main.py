

import Interface as interface
import Communication as com
import time
import serial


app = interface.application()



while(True):
    if com.portArduino.readable():
        com.Arduino.read_one_value()
    time.sleep(0.05)
