

import Interface as interface
import Communication as com
import time
import serial




# Ouverture de l'interface de contrôle
app = interface.application()

# Boucle de communication en serial
while(app.isrunning):
    if com.portArduino.readable():
        com.Arduino.read_one_value()
    time.sleep(0.05)
