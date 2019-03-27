import serial
import struct
import glob
import struct
import time
import numpy as np





moteur = [80,45,80,45,45,45,80,45,0]
buf_moteur = moteur.copy()

etat = 0

hauteur = 0
debutStructure = 0
angle = [100, 250]

def Change_etat(numero):
    global etat
    etat = numero


def manuel(moteur1, moteur2):
    print("manuel")
    print(moteur1,moteur2)
    #arduino.write(b'manuel')
    #arduino.write(moteur1)
    #arduino.write(moteur2)

def stop():
    print("stop")
    #arduino.write(b'stop')

def initalisation():
    print("init")
    #arduino.write(b'init')

def lectureArduino():
    print("lA")
    #entete = arduino.readline()
    #if entete==

    #confirmationEtat = arduino.readline()
    #commandeMoteur0 = arduino.readline()


#-----------------------------------------------------------------------------------------


def btnHauteurUp():
    # Update les commandes lorsque bouton clické
    global hauteur
    #com.manuel(90,90)
    hauteur += 1
    print("Hauteur augmente...\t", hauteur)



def btnHauteurDown():
    ## Update les commandes lorsque bouton clické
    global hauteur
    ##com.manuel(90,90)
    hauteur -= 1
    print("Hauteur descent...\t", hauteur)


def btnQuit():
    ## Pour quitter l'application
    exit()

def btnMoteur():
   ## Pour entrer des commandes moteurs
    print("...")

def btnUpdate():
    ## Update les commandes lorsque bouton clické
    ##com.manuel(90,90)
    global moteur
    print("Update des commandes...")

    moteur = buf_moteur.copy()
    Arduino.envoieVersArduino(portArduino, moteur)
    print(moteur)



class communicationOpenCr(object):
    """A class to read the serial messages from Arduino. The code running on Arduino
    can for example be the ArduinoSide_LSM9DS0 sketch."""

    def __init__(self, port, SIZE_STRUCT=48, verbose=0):
        self.port = port
        self.SIZE_STRUCT = SIZE_STRUCT
        self.verbose = verbose
        self.latest_values = -1
        self.t = 0
        self.port.flushInput()

    def read_one_value(self):
            data = self.port.read(self.SIZE_STRUCT)
            #print(data)
            new_values = struct.unpack('iiiiiiiiiiii', data)
            print(new_values)

    def envoieVersArduino(self, port, moteur):
        #print("Envoie des donnees")
        print("etat=", etat)
        value = struct.pack('iiiiiiiiii',3, moteur[0], moteur[1],moteur[2],moteur[3],moteur[4],moteur[5],moteur[6],moteur[7],hauteur)
        print(value)
        self.port.write(value)





portArduino = serial.Serial('COM3', 115200)
Arduino = communicationOpenCr(portArduino)


