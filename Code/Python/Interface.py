# GUI de ArachnUS
#
from tkinter import *


fenetre = Tk() #Makes the window
fenetre.wm_title("Interface ArachnUS") #Makes the title that will appear in the top left
fenetre.config(background = "#FFFFFF") #sets background color to white

#put widgets here

# Les frames contenue dans fenetre
frameMoteur = Frame(fenetre, width=400, height = 600)
frameMoteur.grid(row=0, column=0, padx=10, pady=2)

# Label des frames
firstLabel = Label(frameMoteur, text="This is my first label")
firstLabel.grid(row=0, column=0, padx=10, pady=2)




fenetre.mainloop() #start monitoring and updating the GUI. Nothing below here runs.