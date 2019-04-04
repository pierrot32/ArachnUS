% CinPatteR - Main exécutant le programme de cinématique de la patte
% ArachnUS - Projet S4 - GRO
% Création : 13 Mars 2019 - 10h
% Dernière Modification : 20 Mars 2019 - 11h30
clear all; close all;
%% Constantes et paramètres
lv = 72.5;      % mm
lbx = 116.1;    % mm

qb = 100;                 % Angle entre le support et bleu1
qv = -25;


q = bonAngle(qv,qb)*2*pi/360;
% q = [pi/10, pi/2]

% Matrice de rotation entre le world frame et le frame 0
Tw0 = [1    0   0   0;
        0   1   0   0;
        0   0   1   0;
        0   0   0   1];
% Tw0 =  [cosd(20)       sind(20)       0       0;
%         -sind(20)      cosd(20)       0       0;
%         0       0       1       0;
%         0       0       0       1];
        

%% Recherce de la cinématique directe
% Définition des matrices de transformation entre le world frame et le
% frame i. 
TwF = transMat_w2f(q, Tw0);
Tw1 = TwF(1:4,1:4);
Tw2 = TwF(1:4, 5:8);
Tw3 = TwF(1:4, 9:12);
A = findpoint(Tw3);

% Ajustement du point du bout de la patte au lieu du point du bout du corps
% bleu3
P = pointfinal(A, 1);

P2 = CartesienPatte(qv,qb);

%% Calcul du Jacobien
J = Jacobien(Tw0, Tw1, Tw2, Tw3);

%% Recherche de la cinématique inverse
% Définition de la position à atteindre et recherche des angles pour
% atteindre cette position cartésienne
Pgoal = [A;MatRotationToEuler(Tw3(1:3,1:3))];
IK = invCinPatte(Pgoal,q+0.5,Tw0)

%% Appel des fonctions et vérification
Q1 = IK*360/(2*pi);
Q2 = AngulairePatte(0.5, 0.5, qv, qb);
q = [Q2(1), Q2(2)];
% TwF = transMat_w2f(q, Tw0);
% Tw1 = TwF(1:4,1:4);
% Tw2 = TwF(1:4, 5:8);
% Tw3 = TwF(1:4, 9:12);
% A = findpoint(Tw3)

% Q2 = Q2*360/(2*pi);
% P2 = CartesienPatte(Q2(1), Q2(2))

% g = fk_4_ik(q, Tw0)
% fkr = MatRotationToEuler(Tw3(1:3,1:3))
%% Affichage graphique de la patte
coord = [   Tw1(1,4), Tw2(1,4), Tw3(1,4); 
            Tw1(2,4), Tw2(2,4), Tw3(2,4);
            Tw1(3,4), Tw2(3,4), Tw3(3,4)];
        
graphlim = lv+lbx;

figure(1)
plot(coord(1,:), coord(2,:))
xlim([-graphlim graphlim])
ylim([-graphlim graphlim])
hold on
grid on

plot(0, 0, '-r*')





