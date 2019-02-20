from tkinter import *
import threading
import Comm.Communication as com




# -------------------------------------------------------------------------------------------------------------------- #


def Increment(numMoteur):
    # Incrément +5 degrés
    #print(com.moteur[numMoteur])
    com.moteur[numMoteur] = com.moteur[numMoteur] + 5
    print("Moteur #", numMoteur,"\t\t\tValeur:", com.moteur[numMoteur])



def Decrement(numMoteur):
    # Décrément -5 degrés
    #print(com.moteur[numMoteur])
    com.moteur[numMoteur] = com.moteur[numMoteur] - 5
    print("Moteur #", numMoteur, "\t\t\tValeur:", com.moteur[numMoteur])






# -------------------------------------------------------------------------------------------------------------------- #
# -------------------------------------------------------------------------------------------------------------------- #
class interface_test(threading.Thread):
    CurrentValue1 = None

    def __init__(self):
        threading.Thread.__init__(self)
        self.start()

    def run(self):
        self.fenetre = Tk() # Créé la fenêtre
        self.fenetre.wm_title("Interface ArachnUS") # Titre de la fenêtre
        self.fenetre.config(background = "#FFFFFF") # Background color = blanc

        # Frame Moteur
        frameMoteur = Frame(self.fenetre, width=600, height =600)
        frameMoteur.grid(row=0, column=0, padx=10, pady=2)
        Label(frameMoteur, text = "Mode manuel moteurs:").grid(row=0, column=0, padx=10, pady=2)
        # BoutonMoteur = Button(frameMoteur, text="Mode Manuel", command=ModeManuel)
        # BoutonMoteur.grid(row=1, column=0, padx=10, pady=2)

        # Frame Patte 1
        framePatte1 = Frame(frameMoteur, width=400, height=400)
        framePatte1.grid(row=1, column=0, padx=10, pady=2)
        Label(framePatte1, text = "Patte 1").grid(row=1, column=0, padx=10, pady=2)
        Label(framePatte1, text="Moteur 1").grid(row=1, column=1, padx=10, pady=2)
        Label(framePatte1, text="Moteur 2").grid(row=2, column=1, padx=10, pady=2)
        Label(framePatte1, text="Moteur 3").grid(row=3, column=1, padx=10, pady=2)

        AngleMoteur1u = Button(framePatte1, text="+5", command=lambda: Increment(0))  # moteur[0]
        AngleMoteur1u.grid(row=1, column=2, padx=10, pady=2)
        AngleMoteur1d = Button(framePatte1, text="-5", command=lambda: Decrement(0)) # moteur[0]
        AngleMoteur1d.grid(row=1, column=3, padx=10, pady=2)


        self.CurrentValue1 = Label(framePatte1, text=com.moteur[0])  # Il faut refresh cette valeur tout le temps
        self.CurrentValue1.grid(row=1, column=4, padx=10, pady=2)


        AngleMoteur2u = Button(framePatte1, text="+5", command=lambda: Increment(1))  # moteur[1]
        AngleMoteur2u.grid(row=2, column=2, padx=10, pady=2)
        AngleMoteur2d = Button(framePatte1, text="-5", command=lambda: Decrement(1)) # moteur[1]
        AngleMoteur2d.grid(row=2, column=3, padx=10, pady=2)

        AngleMoteur3u = Button(framePatte1, text="+5", command=lambda: Increment(2))  # moteur[2]
        AngleMoteur3u.grid(row=3, column=2, padx=10, pady=2)
        AngleMoteur3d = Button(framePatte1, text="-5", command=lambda: Decrement(2)) # moteur[2]
        AngleMoteur3d.grid(row=3, column=3, padx=10, pady=2)
        # -------------------------------------------------------------------------------------------------------------------- #

        # Frame Patte 2
        framePatte2 = Frame(frameMoteur, width=400, height=400)
        framePatte2.grid(row=2, column=0, padx=10, pady=2)
        Label(framePatte2, text="Patte 2").grid(row=1, column=0, padx=10, pady=2)
        Label(framePatte2, text="Moteur 4").grid(row=1, column=1, padx=10, pady=2)
        Label(framePatte2, text="Moteur 5").grid(row=2, column=1, padx=10, pady=2)
        Label(framePatte2, text="Moteur 6").grid(row=3, column=1, padx=10, pady=2)

        AngleMoteur4u = Button(framePatte2, text="+5", command=lambda: Increment(3))  # moteur[3]
        AngleMoteur4u.grid(row=1, column=2, padx=10, pady=2)
        AngleMoteur4d = Button(framePatte2, text="-5", command=lambda: Decrement(3)) # moteur[3]
        AngleMoteur4d.grid(row=1, column=3, padx=10, pady=2)

        AngleMoteur5u = Button(framePatte2, text="+5", command=lambda: Increment(4))  # moteur[4]
        AngleMoteur5u.grid(row=2, column=2, padx=10, pady=2)
        AngleMoteur5d = Button(framePatte2, text="-5", command=lambda: Decrement(4)) # moteur[4]
        AngleMoteur5d.grid(row=2, column=3, padx=10, pady=2)

        AngleMoteur6u = Button(framePatte2, text="+5", command=lambda: Increment(5))  # moteur[5]
        AngleMoteur6u.grid(row=3, column=2, padx=10, pady=2)
        AngleMoteur6d = Button(framePatte2, text="-5", command=lambda: Decrement(5)) # moteur[5]
        AngleMoteur6d.grid(row=3, column=3, padx=10, pady=2)
        # -------------------------------------------------------------------------------------------------------------------- #

        # Frame Patte 3
        framePatte3 = Frame(frameMoteur, width=400, height=400)
        framePatte3.grid(row=3, column=0, padx=10, pady=2)
        Label(framePatte3, text="Patte 3").grid(row=1, column=0, padx=10, pady=2)
        Label(framePatte3, text="Moteur 7").grid(row=1, column=1, padx=10, pady=2)
        Label(framePatte3, text="Moteur 8").grid(row=2, column=1, padx=10, pady=2)
        Label(framePatte3, text="Moteur 9").grid(row=3, column=1, padx=10, pady=2)

        AngleMoteur7u = Button(framePatte3, text="+5", command=lambda: Increment(6))  # moteur[6]
        AngleMoteur7u.grid(row=1, column=2, padx=10, pady=2)
        AngleMoteur7d = Button(framePatte3, text="-5", command=lambda: Decrement(6)) # moteur[6]
        AngleMoteur7d.grid(row=1, column=3, padx=10, pady=2)

        AngleMoteur8u = Button(framePatte3, text="+5", command=lambda: Increment(7))  # moteur[7]
        AngleMoteur8u.grid(row=2, column=2, padx=10, pady=2)
        AngleMoteur8d = Button(framePatte3, text="-5", command=lambda: Decrement(7)) # moteur[7]
        AngleMoteur8d.grid(row=2, column=3, padx=10, pady=2)

        AngleMoteur9u = Button(framePatte3, text="+5", command=lambda: Increment(8))  # moteur[8]
        AngleMoteur9u.grid(row=3, column=2, padx=10, pady=2)
        AngleMoteur9d = Button(framePatte3, text="-5", command=lambda: Decrement(8)) # moteur[8]
        AngleMoteur9d.grid(row=3, column=3, padx=10, pady=2)


        BoutonUpdate = Button(frameMoteur, text="Update", command=com.btnUpdate)
        BoutonUpdate.grid(row=1, column=2, padx=10, pady=2)
        # -------------------------------------------------------------------------------------------------------------------- #
        # -------------------------------------------------------------------------------------------------------------------- #


         # Frame Mode Stabilisation
        frameStable = Frame(self.fenetre, width=100, height=150)
        frameStable.grid(row=0, column=1, padx=10, pady=2)
        Label(frameStable, text = "Stabilisation:").grid(row=0, column=0, padx=10, pady=2)
        BoutonHauteurUp = Button(frameStable, text="Hauteur +", command=com.btnHauteurUp)
        BoutonHauteurUp.grid(row=1, column=0, padx=10, pady=2)
        BoutonHauteurDown = Button(frameStable, text="Hauteur -", command=com.btnHauteurDown)
        BoutonHauteurDown.grid(row=2, column=0, padx=10, pady=2)
        # -------------------------------------------------------------------------------------------------------------------- #

         # Frame Quit
        frameQuit = Frame(self.fenetre, width=50, height=50)
        frameQuit.grid(row=0, column=2, padx=10, pady=2)
        BoutonQuit = Button(frameQuit, text="Quitter l'application", command=com.btnQuit)
        BoutonQuit.grid(row=0, column=0, padx=10, pady=2)
        self.fenetre.mainloop() # Start monitoring and updating the GUI
# -------------------------------------------------------------------------------------------------------------------- #

        def Refresher():
            self.CurrentValue1.configure(text=com.moteur[0])
            print("test")
            self.fenetre.after(1000, Refresher)

appTest = interface_test()

i=0
while(True):
    i = i+1




