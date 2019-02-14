from tkinter import *

import Comm.Communication as com

fenetre = Tk() # Créé la fenêtre
fenetre.wm_title("Interface ArachnUS") # Titre de la fenêtre
fenetre.config(background = "#FFFFFF") # Background color = blanc
fenetre.geometry("450x300+0+0")


def ModeManuel():
    # Ouvre une nouvelle fenêtre pour contrôle des moteurs
    fenetreMoteur = Toplevel(fenetre)
    fenetreMoteur.wm_title("Mode Manuel")

    framePatte1 = Frame(fenetreMoteur, width=400, height=400)
    framePatte1.grid(row=0, column=0, padx=10, pady=2)
    Label(framePatte1, text = "Patte 1").grid(row=1, column=0, padx=10, pady=2)
    Label(framePatte1, text="Moteur 1").grid(row=1, column=1, padx=10, pady=2)
    Label(framePatte1, text="Moteur 2").grid(row=2, column=1, padx=10, pady=2)
    Label(framePatte1, text="Moteur 3").grid(row=3, column=1, padx=10, pady=2)

    AngleMoteur1 = Entry(framePatte1, width=6, textvariable=StringVar(framePatte1, value="0"))
    AngleMoteur1.grid(row=1, column=2, padx=10, pady=2)
    AngleMoteur2 = Entry(framePatte1, width=6, textvariable=StringVar(framePatte1, value="0"))
    AngleMoteur2.grid(row=2, column=2, padx=10, pady=2)
    AngleMoteur3 = Entry(framePatte1, width=6, textvariable=StringVar(framePatte1, value="0"))
    AngleMoteur3.grid(row=3, column=2, padx=10, pady=2)


    framePatte2 = Frame(fenetreMoteur, width=400, height=400)
    framePatte2.grid(row=1, column=0, padx=10, pady=2)
    Label(framePatte2, text="Patte 2").grid(row=1, column=0, padx=10, pady=2)
    Label(framePatte2, text="Moteur 4").grid(row=1, column=1, padx=10, pady=2)
    Label(framePatte2, text="Moteur 5").grid(row=2, column=1, padx=10, pady=2)
    Label(framePatte2, text="Moteur 6").grid(row=3, column=1, padx=10, pady=2)

    AngleMoteur4 = Entry(framePatte2, width=6, textvariable=StringVar(framePatte2, value="0"))
    AngleMoteur4.grid(row=1, column=2, padx=10, pady=2)
    AngleMoteur5 = Entry(framePatte2, width=6, textvariable=StringVar(framePatte2, value="0"))
    AngleMoteur5.grid(row=2, column=2, padx=10, pady=2)
    AngleMoteur6 = Entry(framePatte2, width=6, textvariable=StringVar(framePatte2, value="0"))
    AngleMoteur6.grid(row=3, column=2, padx=10, pady=2)


    framePatte3 = Frame(fenetreMoteur, width=400, height=400)
    framePatte3.grid(row=2, column=0, padx=10, pady=2)
    Label(framePatte3, text="Patte 3").grid(row=1, column=0, padx=10, pady=2)
    Label(framePatte3, text="Moteur 7").grid(row=1, column=1, padx=10, pady=2)
    Label(framePatte3, text="Moteur 8").grid(row=2, column=1, padx=10, pady=2)
    Label(framePatte3, text="Moteur 9").grid(row=3, column=1, padx=10, pady=2)

    AngleMoteur7 = Entry(framePatte3, width=6, textvariable=StringVar(framePatte3, value="0"))
    AngleMoteur7.grid(row=1, column=2, padx=10, pady=2)
    AngleMoteur8 = Entry(framePatte3, width=6, textvariable=StringVar(framePatte3, value="0"))
    AngleMoteur8.grid(row=2, column=2, padx=10, pady=2)
    AngleMoteur9 = Entry(framePatte3, width=6, textvariable=StringVar(framePatte3, value="0"))
    AngleMoteur9.grid(row=3, column=2, padx=10, pady=2)


    BoutonDismiss = Button(fenetreMoteur, text="Fermer la fenêtre", command=fenetreMoteur.destroy)
    BoutonDismiss.grid(row=0, column=1, padx=10, pady=2)

def btnUpdate():
    # Update les commandes lorsque bouton clické
    com.manuel(90,90)
    print("Update des commandes...")

def btnQuit():
    # Pour quitter l'application
    exit()

def btnMoteur():
   # Pour entrer des commandes moteurs
    print("...")


 # Frame Moteur
frameMoteur = Frame(fenetre, width=600, height =600)
frameMoteur.grid(row=0, column=0, padx=10, pady=2)
Label(frameMoteur, text = "Moteurs:").grid(row=0, column=0, padx=10, pady=2)
BoutonMoteur = Button(frameMoteur, text="Mode Manuel", command=ModeManuel)
BoutonMoteur.grid(row=1, column=0, padx=10, pady=2)



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