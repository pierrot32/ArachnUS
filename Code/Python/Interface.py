# GUI de ArachnUS
#
from tkinter import *


fenetre = Tk() #Makes the window
fenetre.wm_title("Interface ArachnUS") #Makes the title that will appear in the top left
fenetre.config(background = "#FFFFFF") #sets background color to white

#put widgets here

# Frame moteur
frameMoteur = Frame(fenetre, width=400, height = 600)
frameMoteur.grid(row=0, column=0, padx=10, pady=2)

# Label du frame moteur
firstLabel = Label(frameMoteur, text="Moteur 0")
firstLabel.grid(row=0, column=0, padx=10, pady=2)




fenetre.mainloop() #start monitoring and updating the GUI. Nothing below here runs.