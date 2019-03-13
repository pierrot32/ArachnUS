# Python Interface v.0.11


from tkinter import *
import threading
import Communication as com

# -------------------------------------------------------------------------------------------------------------------- #


# -------------------------------------------------------------------------------------------------------------------- #
# -------------------------------------------------------------------------------------------------------------------- #
class application(threading.Thread):
    CurrentValue1 = None
    CurrentValue2 = None
    CurrentValue3 = None
    CurrentValue4 = None
    CurrentValue5 = None
    CurrentValue6 = None
    CurrentValue7 = None
    CurrentValue8 = None
    CurrentValue9 = None
    eM1 = None
    eM2 = None
    eM3 = None
    eM4 = None
    eM5 = None
    eM6 = None
    eM7 = None
    eM8 = None
    eM9 = None
    CurrentAngleX = None
    CurrentAngleY = None
    CurrentEtat = None
    CurrentHauteur = None


    def __init__(self):
        threading.Thread.__init__(self)
        self.start()


    def run(self):
        self.fenetre = Tk() # Créé la fenêtre
        self.fenetre.wm_title("Interface ArachnUS") # Titre de la fenêtre
        self.fenetre.config(bg = "gray35")

        # Frame Moteur
        frameMoteur = Frame(self.fenetre, width=600, height =600)
        frameMoteur.grid(row=0, column=0, padx=15, pady=15)
        Label(frameMoteur, text = "Mode manuel moteurs:", fg="lawn green", bg="gray55", font=("Helvetica", 12, "bold")).grid(row=0, column=0, padx=10, pady=2)
        frameMoteur.config(bg="gray55")

        # Patte 1
        framePatte = Frame(frameMoteur, width=400, height=400)
        framePatte.grid(row=1, column=0, padx=10, pady=2)
        framePatte.config(bg="gray75")
        Label(framePatte, text = "Patte 1").grid(row=1, column=0, padx=10, pady=2)
        Label(framePatte, text="Moteur 1").grid(row=1, column=1, padx=10, pady=2)
        Label(framePatte, text="Moteur 2").grid(row=2, column=1, padx=10, pady=2)
        Label(framePatte, text="Moteur 3").grid(row=3, column=1, padx=10, pady=2)

        self.CurrentValue1 = Label(framePatte, text=com.buf_moteur[0], font=("Helvetica", 10, "bold"))
        self.CurrentValue1.grid(row=1, column=5, padx=10, pady=2)

        self.CurrentValue2 = Label(framePatte, text=com.buf_moteur[1], font=("Helvetica", 10, "bold"))
        self.CurrentValue2.grid(row=2, column=5, padx=10, pady=2)

        self.CurrentValue3 = Label(framePatte, text=com.buf_moteur[2], font=("Helvetica", 10, "bold"))
        self.CurrentValue3.grid(row=3, column=5, padx=10, pady=2)

        #AngleMoteur1u = Button(framePatte1, text="+5", command=lambda: Increment(0))  # moteur[0]
        #AngleMoteur1u.grid(row=1, column=3, padx=10, pady=2)
        #AngleMoteur1d = Button(framePatte1, text="-5", command=lambda: Decrement(0)) # moteur[0]
        #AngleMoteur1d.grid(row=1, column=2, padx=10, pady=2)
        self.eM1 = Entry(framePatte, width=4)
        self.eM1.grid(row=1, column=4)
        self.eM1.insert(3, com.buf_moteur[0])



        #AngleMoteur2u = Button(framePatte1, text="+5", command=lambda: Increment(1))  # moteur[1]
        #AngleMoteur2u.grid(row=2, column=3, padx=10, pady=2)
        #AngleMoteur2d = Button(framePatte1, text="-5", command=lambda: Decrement(1)) # moteur[1]
        #AngleMoteur2d.grid(row=2, column=2, padx=10, pady=2)
        self.eM2 = Entry(framePatte, width=4)
        self.eM2.grid(row=2, column=4)
        self.eM2.insert(3, com.buf_moteur[1])

        #AngleMoteur3u = Button(framePatte1, text="+5", command=lambda: Increment(2))  # moteur[2]
        #AngleMoteur3u.grid(row=3, column=3, padx=10, pady=2)
        #AngleMoteur3d = Button(framePatte1, text="-5", command=lambda: Decrement(2)) # moteur[2]
        #AngleMoteur3d.grid(row=3, column=2, padx=10, pady=2)
        self.eM3 = Entry(framePatte, width=4)
        self.eM3.grid(row=3, column=4)
        self.eM3.insert(3, com.buf_moteur[2])
        # -------------------------------------------------------------------------------------------------------------------- #

        # Patte 2

        Label(framePatte, text="Patte 2").grid(row=4, column=0, padx=10, pady=2)
        Label(framePatte, text="Moteur 4").grid(row=4, column=1, padx=10, pady=2)
        Label(framePatte, text="Moteur 5").grid(row=5, column=1, padx=10, pady=2)
        Label(framePatte, text="Moteur 6").grid(row=6, column=1, padx=10, pady=2)

        #AngleMoteur4u = Button(framePatte2, text="+5", command=lambda: Increment(3))  # moteur[3]
        #AngleMoteur4u.grid(row=1, column=3, padx=10, pady=2)
        #AngleMoteur4d = Button(framePatte2, text="-5", command=lambda: Decrement(3)) # moteur[3]
        #AngleMoteur4d.grid(row=1, column=2, padx=10, pady=2)
        self.eM4 = Entry(framePatte, width=4)
        self.eM4.grid(row=4, column=4)
        self.eM4.insert(3, com.buf_moteur[3])

        #AngleMoteur5u = Button(framePatte2, text="+5", command=lambda: Increment(4))  # moteur[4]
        #AngleMoteur5u.grid(row=2, column=3, padx=10, pady=2)
        #AngleMoteur5d = Button(framePatte2, text="-5", command=lambda: Decrement(4)) # moteur[4]
        #AngleMoteur5d.grid(row=2, column=2, padx=10, pady=2)
        self.eM5 = Entry(framePatte, width=4)
        self.eM5.grid(row=5, column=4)
        self.eM5.insert(3, com.buf_moteur[4])

        #AngleMoteur6u = Button(framePatte2, text="+5", command=lambda: Increment(5))  # moteur[5]
        #AngleMoteur6u.grid(row=3, column=3, padx=10, pady=2)
        #AngleMoteur6d = Button(framePatte2, text="-5", command=lambda: Decrement(5)) # moteur[5]
        #AngleMoteur6d.grid(row=3, column=2, padx=10, pady=2)
        self.eM6 = Entry(framePatte, width=4)
        self.eM6.grid(row=6, column=4)
        self.eM6.insert(3, com.buf_moteur[5])

        self.CurrentValue4 = Label(framePatte, text=com.buf_moteur[3], font=("Helvetica", 10, "bold"))
        self.CurrentValue4.grid(row=4, column=5, padx=10, pady=2)

        self.CurrentValue5 = Label(framePatte, text=com.buf_moteur[4], font=("Helvetica", 10, "bold"))
        self.CurrentValue5.grid(row=5, column=5, padx=10, pady=2)

        self.CurrentValue6 = Label(framePatte, text=com.buf_moteur[5], font=("Helvetica", 10, "bold"))
        self.CurrentValue6.grid(row=6, column=5, padx=10, pady=2)

        # -------------------------------------------------------------------------------------------------------------------- #

        # Patte 3

        Label(framePatte, text="Patte 3").grid(row=7, column=0, padx=10, pady=2)
        Label(framePatte, text="Moteur 7").grid(row=7, column=1, padx=10, pady=2)
        Label(framePatte, text="Moteur 8").grid(row=8, column=1, padx=10, pady=2)
        Label(framePatte, text="Moteur 9").grid(row=9, column=1, padx=10, pady=2)

        #AngleMoteur7u = Button(framePatte3, text="+5", command=lambda: Increment(6))  # moteur[6]
        #AngleMoteur7u.grid(row=1, column=3, padx=10, pady=2)
        #AngleMoteur7d = Button(framePatte3, text="-5", command=lambda: Decrement(6)) # moteur[6]
        #AngleMoteur7d.grid(row=1, column=2, padx=10, pady=2)
        self.eM7 = Entry(framePatte, width=4)
        self.eM7.grid(row=7, column=4)
        self.eM7.insert(3, com.buf_moteur[6])

        #AngleMoteur8u = Button(framePatte3, text="+5", command=lambda: Increment(7))  # moteur[7]
        #AngleMoteur8u.grid(row=2, column=3, padx=10, pady=2)
        #AngleMoteur8d = Button(framePatte3, text="-5", command=lambda: Decrement(7)) # moteur[7]
        #AngleMoteur8d.grid(row=2, column=2, padx=10, pady=2)
        self.eM8 = Entry(framePatte, width=4)
        self.eM8.grid(row=8, column=4)
        self.eM8.insert(3, com.buf_moteur[7])

        #AngleMoteur9u = Button(framePatte3, text="+5", command=lambda: Increment(8))  # moteur[8]
        #AngleMoteur9u.grid(row=3, column=3, padx=10, pady=2)
        #AngleMoteur9d = Button(framePatte3, text="-5", command=lambda: Decrement(8)) # moteur[8]
        #AngleMoteur9d.grid(row=3, column=2, padx=10, pady=2)
        self.eM9 = Entry(framePatte, width=4)
        self.eM9.grid(row=9, column=4)
        self.eM9.insert(3, com.buf_moteur[8])

        self.CurrentValue7 = Label(framePatte, text=com.buf_moteur[6], font=("Helvetica", 10, "bold"))
        self.CurrentValue7.grid(row=7, column=5, padx=10, pady=2)

        self.CurrentValue8 = Label(framePatte, text=com.buf_moteur[7], font=("Helvetica", 10, "bold"))
        self.CurrentValue8.grid(row=8, column=5, padx=10, pady=2)

        self.CurrentValue9 = Label(framePatte, text=com.buf_moteur[8], font=("Helvetica", 10, "bold"))
        self.CurrentValue9.grid(row=9, column=5, padx=10, pady=2)


        BoutonUpdate = Button(frameMoteur, text="Update", font=("Helvetica", 12, "bold"), fg="blue", bg="gray75", command=com.btnUpdate)
        BoutonUpdate.grid(row=0, column=2, padx=10, pady=2)
        # -------------------------------------------------------------------------------------------------------------------- #


         # Frame Mode Stabilisation
        frameStable = Frame(self.fenetre, width=100, height=150)
        frameStable.grid(row=0, column=2, padx=10, pady=2)
        frameStable.config(bg="gray55")
        Label(frameStable, text = "Élévation:", fg="lawn green", bg="gray55", font=("Helvetica", 12, "bold")).grid(row=0, column=0, padx=10, pady=2)
        BoutonHauteurUp = Button(frameStable, text="Hauteur +", bg="gray75", command=com.btnHauteurUp)
        BoutonHauteurUp.grid(row=2, column=0, padx=10, pady=2)
        BoutonHauteurDown = Button(frameStable, text="Hauteur -", bg="gray75", command=com.btnHauteurDown)
        BoutonHauteurDown.grid(row=3, column=0, padx=10, pady=2)

        Label(frameStable, text="Hauteur actuelle:", bg="gray75").grid(row=1, column=0,padx=10, pady=2)
        self.CurrentHauteur = Label(frameStable, text=com.hauteur, bg="gray75", font=("Helvetica", 10, "bold"))
        self.CurrentHauteur.grid(row=1, column=1, padx=10, pady=2)

        # -------------------------------------------------------------------------------------------------------------------- #

        # Frame Angle robot
        frameAngleTitre = Frame(self.fenetre, width=100, height=150)
        frameAngleTitre.grid(row=0, column=1, padx=10, pady=2)
        frameAngleTitre.config(bg="gray55")
        Label(frameAngleTitre, text = "Angle du robot:", fg="lawn green", bg="gray55", font=("Helvetica", 12, "bold")).grid(row=0, column=0, padx=10, pady=2)

        frameAngle = Frame(frameAngleTitre, width=100, height=150)
        frameAngle.grid(row=1, column=0, padx=10, pady=2)
        frameAngle.config(bg="gray75")
        Label(frameAngle, text="x:", bg="gray75").grid(row=0, column=0, padx=0, pady=2)
        self.CurrentAngleX = Label(frameAngle, text=com.buf_moteur[0], bg="gray75", font=("Helvetica", 10, "bold"))
        self.CurrentAngleX.grid(row=0, column=1, padx=10, pady=2)
        Label(frameAngle, text="y:", bg="gray75").grid(row=1, column=0, padx=0, pady=2)
        self.CurrentAngleY = Label(frameAngle, text=com.buf_moteur[0], bg="gray75", font=("Helvetica", 10, "bold"))
        self.CurrentAngleY.grid(row=1, column=1, padx=10, pady=2)
        # -------------------------------------------------------------------------------------------------------------------- #

        # Frame OpenCR
        frameOpen = Frame(frameAngleTitre, width=50, height=100)
        frameOpen.grid(row=2, column=0, padx=10, pady=2)
        frameOpen.config(bg="gray55")
        Label(frameOpen, text="État du OpenCR:", fg="lawn green", bg="gray55", font=("Helvetica", 12, "bold")).grid(row=0, column=0, padx=10, pady=2)
        self.CurrentEtat = Label(frameOpen, text=com.etat, bg="gray75", font=("Helvetica", 10, "bold"))
        self.CurrentEtat.grid(row=1, column=0, padx=10, pady=2)

        switch_variable = StringVar(value="off")





        BoutonInit = Radiobutton(frameOpen, text="Init", bg="gray75", font=("Helvetica", 10, "bold"), variable=switch_variable, indicatoron=False, command=com.initalisation(), width=8, value="init")
        BoutonInit.grid(row=2, column=0, padx=10, pady=2)
        BoutonStable = Radiobutton(frameOpen, text="Stable", bg="gray75", font=("Helvetica", 10, "bold"), variable=switch_variable, indicatoron=False, command=com.btnHauteurUp, width=8, value="stable")
        BoutonStable.grid(row=4, column=0, padx=10, pady=2)
        BoutonManuel = Radiobutton(frameOpen, text="Manuel", bg="gray75", font=("Helvetica", 10, "bold"), variable=switch_variable, indicatoron=False, command=com.btnHauteurDown, width=8, value="manuel")
        BoutonManuel.grid(row=3, column=0, padx=10, pady=2)

        # -------------------------------------------------------------------------------------------------------------------- #

         # Frame Quit
        frameQuit = Frame(self.fenetre, width=50, height=50)
        frameQuit.grid(row=0, column=3, padx=10, pady=2)
        frameQuit.config(bg="gray35")
        BoutonQuit = Button(frameQuit, text="Quitter l'application", fg="blue", bg="gray75", font=("Helvetica", 12, "bold"), command=com.btnQuit)
        BoutonQuit.grid(row=0, column=0, padx=10, pady=2)





        # -------------------------------------------------------------------------------------------------------------------- #
        def Refresher():


            try:
                com.buf_moteur[0] = int(self.eM1.get())
            except:
                com.buf_moteur[0] = 0
            try:
                com.buf_moteur[1] = int(self.eM2.get())
            except:
                com.buf_moteur[1] = 0
            try:
                com.buf_moteur[2] = int(self.eM3.get())
            except:
                com.buf_moteur[2] = 0
            try:
                com.buf_moteur[3] = int(self.eM4.get())
            except:
                com.buf_moteur[3] = 0
            try:
                com.buf_moteur[4] = int(self.eM5.get())
            except:
                com.buf_moteur[4] = 0
            try:
                com.buf_moteur[5] = int(self.eM6.get())
            except:
                com.buf_moteur[5] = 0
            try:
                com.buf_moteur[6] = int(self.eM7.get())
            except:
                com.buf_moteur[6] = 0
            try:
                com.buf_moteur[7] = int(self.eM8.get())
            except:
                com.buf_moteur[7] = 0
            try:
                com.buf_moteur[8] = int(self.eM9.get())
            except:
                com.buf_moteur[8] = 0


            self.CurrentValue1.configure(text=com.moteur[0])
            self.CurrentValue2.configure(text=com.moteur[1])
            self.CurrentValue3.configure(text=com.moteur[2])
            self.CurrentValue4.configure(text=com.moteur[3])
            self.CurrentValue5.configure(text=com.moteur[4])
            self.CurrentValue6.configure(text=com.moteur[5])
            self.CurrentValue7.configure(text=com.moteur[6])
            self.CurrentValue8.configure(text=com.moteur[7])
            self.CurrentValue9.configure(text=com.moteur[8])

            self.CurrentAngleX.configure(text=com.angle[0])
            self.CurrentAngleY.configure(text=com.angle[1])

            self.CurrentEtat.configure(text=com.etat)

            self.CurrentHauteur.configure(text=com.hauteur)

            self.fenetre.after(250, Refresher)


        Refresher()

        self.fenetre.mainloop() # Start monitoring and updating the GUI
# -------------------------------------------------------------------------------------------------------------------- #

#def Increment(numMoteur):
    # Incrément +5 degrés
    #print(com.moteur[numMoteur])
    #com.moteur[numMoteur] += 5
    #print("Moteur #", numMoteur,"\t\t\tValeur:", com.moteur[numMoteur])



#def Decrement(numMoteur):
    # Décrément -5 degrés
    #print(com.moteur[numMoteur])
    #com.moteur[numMoteur] -= 5
    #print("Moteur #", numMoteur, "\t\t\tValeur:", com.moteur[numMoteur])





