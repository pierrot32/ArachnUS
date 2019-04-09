% TestAutomatise - Main exécutant le programme de cinématique de la patte
% ArachnUS - Projet S4 - GRO
% Création : 20 Mars 2019 - 10h
% Dernière Modification : 20 Mars 2019 - 10h
clear all; close all;
lv = 72.5;      % mm
lbx = 116.1;    % mm
%% bonAngle
% Test 1 : résultat qv = -35, qbx = -76.67
qv = -25; qb = 100;
q1 = bonAngle(qv, qb)*2*pi/360;

% % Test 2 : résultat qv = -35, qbx = -126.3
qv = 30; qb = 120;
q2 = bonAngle(qv,qb)*2*pi/360;

%% bonAngleInv
% Test 1 : résultat qv = -25, qbx = 100
qv = -25; qbx = -78;
q11 = bonAngleInv(qv, qb);

% % Test 2 : résultat qv = -35, qbx = -126.3
qv = 30; qb = -104;
q22 = bonAngleInv(qv,qb);

%% pointFinal
t1 = pointfinal([0;0;0],-1);
t2 = pointfinal([155;23;0],1);

%% transMat_w2f
Tw0 =   [1    0   0   0;
        0   1   0   0;
        0   0   1   0;
        0   0   0   1];

% Test 1 : qv et qbx sont 0;
q = [-25*2*pi/360,-78*2*pi/360,0];
T1 = transMat_w2f(q,Tw0);
T1 = T1(1:4, 9:12);
% Test 2: qv = -pi/4 et qbx = -pi/8
q = [30*2*pi/360,-104*2*pi/360,0];
T2 = transMat_w2f(q,Tw0);
T2 = T2(1:4, 9:12);

%% findpoint
fp1 = findpoint(T1);
fp2 = findpoint(T2);

%% CartesienPatte.m
% Test 1: qv = 0, qb = 90
P1 = CartesienPatte(-25, 100);

% Test 2: qv = -45, qb = 0
P2 = CartesienPatte(30, 120);

%% MatRotationToEuler.m
R1 = T1(1:3,1:3);
E1 = MatRotationToEuler(R1);
R2 = T2(1:3,1:3);
E2 = MatRotationToEuler(R2);

%% EulerXYZtoRot.m
Rv1 = EulerXYZtoRot(E1);
Rv2 = EulerXYZtoRot(E2);

%% fk_4_ik.m
fk1 = fk_4_ik([-25*2*pi/360;-78*2*pi/360;0], Tw0);
fk2 = fk_4_ik([30*2*pi/360;-104*2*pi/360;0], Tw0);

%% Jacobien.m
q = [-25*2*pi/360,-78*2*pi/360,0];
Tj1 = transMat_w2f(q,Tw0);
J1 = Jacobien(Tw0, Tj1(1:4,1:4), Tj1(1:4,5:8), Tj1(1:4,9:12));

q = [30*2*pi/360,-104*2*pi/360,0];
Tj2 = transMat_w2f(q,Tw0);
J2 = Jacobien(Tw0, Tj2(1:4,1:4), Tj2(1:4,5:8), Tj2(1:4,9:12));

%% invCinPatte.m
A1 = invCinPatte(fk1, [-35*2*pi/360;-68*2*pi/360;0],Tw0);
A2 = invCinPatte(fk2, [10*2*pi/360;-120*2*pi/360;0],Tw0);

%% AngulairePatte.m

