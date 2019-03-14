% CinPatteR - Main ex�cutant le programme de cin�matique de la patte
% ArachnUS - Projet S4 - GRO
% Cr�ation : 13 Mars 2019 - 10h
% Derni�re Modification : 13 Mars 2019 - 11h
clear all; close all;
%% Constantes et param�tres
qb = 0;
qbx = pi/2;
qv = pi/10;

q = [qv; qbx;0];

Tw0 =  [cosd(20)       sind(20)       0       0;
        -sind(20)      cosd(20)       0       0;
        0       0       1       0;
        0       0       0       1];
        

%% Recherce de la cin�matique directe
TwF = transMat_w2f(q, Tw0);
Tw1 = TwF(1:4,1:4);
Tw2 = TwF(1:4, 5:8);
Tw3 = TwF(1:4, 9:12);
A = findpoint(Tw3);
P = pointfinal(A, 1);

%% Calcul du Jacobien
J = Jacobien(q, Tw0, Tw1, Tw2, Tw3);

%% Recherche de la cin�matique inverse
Pgoal = [A;MatRotationToEuler(Tw3(1:3,1:3))];
Ik = invCinPatte(Pgoal,q+0.6,Tw0)

%% Affichage graphique de la patte
coord = [   Tw1(1,4), Tw2(1,4), Tw3(1,4); 
            Tw1(2,4), Tw2(2,4), Tw3(2,4);
            Tw1(3,4), Tw2(3,4), Tw3(3,4)];




