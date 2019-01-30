import serial

arduino = serial.Serial('COM3', 9600)

count = 0
while count < 5:
    line = arduino.readline()
    print(line)
    count += 1

arduino.write(b'stop')