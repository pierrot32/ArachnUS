import serial
import struct
import glob
import struct
import time
import numpy as np


# Variables globales
moteur = [80,0,80,0,0,0,80,0,0]    #Commande moteur
buf_moteur = moteur.copy()              #Buffer de la commande moteur
etat = 0                                #Etat du robot
hauteur = 0                             #Hauteur du robot
angle = [100, 250]                      #Angle du robot


# Fonction pour changer l'état du robot
def Change_etat(numero):
    global etat
    etat = numero

# Fonction pour augmenter la hauteur du robot lorsque celui-ci est en mode stabilisation
def btnHauteurUp():
    global hauteur
    hauteur += 1

# Fonction pour diminuer la hauteur du robot lorsque celui-ci est en mode stabilisation
def btnHauteurDown():
    global hauteur
    hauteur -= 1

# Fonction pour fermer l'application
def btnQuit():
    exit()

# Fonction pour update les moteurs en mode manuel
def btnUpdate():
    global moteur
    moteur = buf_moteur.copy()
    Arduino.envoieVersArduino(moteur)

# Classe pour la communication Serial avec la carte openCR
class communicationOpenCr(object):
    # Definition de la fonction d'initialisation de la carte openCr
    def __init__(self, port, SIZE_STRUCT=48, verbose=0): #SIZE_STRUCT =  12(int) * 4 bit (pour la grosseur de la structure reçu
        self.port = port
        self.SIZE_STRUCT = SIZE_STRUCT
        self.verbose = verbose
        self.latest_values = -1
        self.t = 0
        self.port.flushInput()

    # Fefinition de la fonction pour lire la structure reçu de la carte openCR
    def read_one_value(self):
            data = self.port.read(self.SIZE_STRUCT)
            new_values = struct.unpack('iiiiiiiiiiii', data)
            print(new_values)

    def envoieVersArduino(self, moteur):
        # Création de la structure pour l'envois des données vers la carte openCR
        value = struct.pack('iiiiiiiiii',etat, moteur[0], moteur[1],moteur[2],moteur[3],moteur[4],moteur[5],moteur[6],moteur[7],hauteur)
        self.port.write(value)




# Création du port sérial pour la communication avec la carte openCr
portArduino = serial.Serial('COM3', 115200)

# Création de l'objet pour la communication serial avec la carte openCR
Arduino = communicationOpenCr(portArduino)





