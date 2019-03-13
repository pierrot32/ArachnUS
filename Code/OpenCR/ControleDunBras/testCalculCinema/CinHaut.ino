/* CinPatteR - Main exécutant le programme de cinématique de la patte
   ArachnUS - Projet S4 - GRO
   Création : 13 Mars 2019 - 10h
   Dernière Modification : 13 Mars 2019 - 11h
*/

// Constantes et paramètres
float qb = 0.0;
float qbx = 3.1416/2.0;
float qv = 3.1416/10.0;

matrix_obj *q;
q = matrix_construct_zero(3, 1);
q->array[0] = qv;
q->array[1] = qbx;

matrix_obj *Tw0;
Tw0 = matrix_construct_zero(4, 4);
Tw0->array[0] = cos(20);
Tw0->array[1] = sin(20);
Tw0->array[4] = -sin(20);
Tw0->array[5] = cos(20);
Tw0->array[10] = 1;
Tw0->array[15] = 1;     

// Recherce de la cinématique directe
matrix_obj *TwF;
TwF = matrix_construct_zero(4, 12);
TwF = transMat_w2f(q, Tw0);

matrix_obj *Tw1;
Tw1 = matrix_construct_zero(4, 4);

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






