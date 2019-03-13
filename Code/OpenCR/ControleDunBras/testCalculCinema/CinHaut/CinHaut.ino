/* CinPatteR - Main exécutant le programme de cinématique de la patte
   ArachnUS - Projet S4 - GRO
   Création : 13 Mars 2019 - 10h
   Dernière Modification : 13 Mars 2019 - 11h
*/

// Constantes et paramètres
float qb = 0.0;
float qbx = 3.1416/2.0;
float qv = 3.1416/10.0;

float q[3] = {qv, qbx, 0};

float Tw0[4][4] =  {{cos(20)       sin(20)       0       0},
                    {-sin(20)      cos(20)       0       0},
                    {   0           0            1       0},
                    {   0           0            0       1}
                   };
        

// Recherce de la cinématique directe
float TwF[16][4]; //À valider...
TwF = transMat_w2f(q, Tw0);
float Tw1[4][4] = TwF(1:4,1:4);

float Tw2[4][4] = TwF(1:4, 5:8);
float Tw3[4][4] = TwF(1:4, 9:12);
A = findpoint(Tw3);
P = pointfinal(A, 1);

// Calcul du Jacobien
J = Jacobien(q, Tw0, Tw1, Tw2, Tw3);

// Recherche de la cinématique inverse
Pgoal = [A;MatRotationToEuler(Tw3(1:3,1:3))];
Ik = invCinPatte(Pgoal,q+0.6,Tw0)

// Affichage graphique de la patte
coord = [   Tw1(1,4), Tw2(1,4), Tw3(1,4); 
            Tw1(2,4), Tw2(2,4), Tw3(2,4);
            Tw1(3,4), Tw2(3,4), Tw3(3,4)];






