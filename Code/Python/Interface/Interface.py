from Comm import *
from tkinter import *

fenetre = Tk() # Créé la fenêtre
fenetre.wm_title("Interface ArachnUS") # Titre de la fenêtre
fenetre.config(background = "#FFFFFF") # Background color = blanc

def btnUpdate():
    # Update les commandes lorsque bouton clické
    print("Update des commandes...")

def btnQuit():
    # Pour quitter l'application
    exit()

def btnMoteur():
    # Pour entrer des commandes moteurs
    print("...")


# Frame Moteur
frameMoteur = Frame(fenetre, width=600, height = 600)
frameMoteur.grid(row=0, column=0, padx=10, pady=2)
Label(frameMoteur, text = "Moteurs:").grid(row=0, column=0, padx=10, pady=2)


# Frame Update
frameUpdate = Frame(fenetre, width=100, height=150)
frameUpdate.grid(row=0, column=1, padx=10, pady=2)
Label(frameUpdate, text = "Update commandes:").grid(row=0, column=0, padx=10, pady=2)
BoutonUpdate = Button(frameUpdate, text="Update", command=btnUpdate)
BoutonUpdate.grid(row=1, column=0, padx=10, pady=2)


# Frame Quit
frameQuit = Frame(fenetre, width=50, height=50)
frameQuit.grid(row=0, column=2, padx=10, pady=2)
BoutonQuit = Button(frameQuit, text="Quitter l'application", command=btnQuit)
BoutonQuit.grid(row=0, column=0, padx=10, pady=2)



fenetre.mainloop() # Start monitoring and updating the GUI