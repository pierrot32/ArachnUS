% TestAutomatise - Main exécutant le programme de cinématique de la patte
% ArachnUS - Projet S4 - GRO
% Création : 20 Mars 2019 - 10h
% Dernière Modification : 20 Mars 2019 - 10h
clear all; close all;
lv = 72.5;      % mm
lbx = 116.1;    % mm
%% bonAngle
n = 1;
% Test 1 : résultat qv = -35, qbx = -76.67
qv = -35; qb = 100;
q(1,:) = bonAngle(qv, qb);
q_r(1,:) = [-35, -76.67];

% Test 2 : résultat qv = 20, qbx = -82.03
qv = 20; qb  = 100;
q(2,:) = bonAngle(qv, qb);
q_r(2,:) = [20, -82.03];

% Test 3 : résultat qv = 35, qbx = -99.15
qv = 35; qb = 115;
q(3,:) = bonAngle(qv, qb);
q_r(3,:) = [35, -99.15];

% Test 4 : résultat qv = -15, qbx = -95.56
qv = -15; qb = 115;
q(4,:) = bonAngle(qv, qb);
q_r(4,:) = [-15, -95.56];

% Test 5 : résultat qv = 12.5, qbx = -94.35
qv = 12.5; qb = 112.4;
q(5,:) = bonAngle(qv, qb);
q_r(5,:) = [12.5, -94.35];

% Test 6 : résultat qv = -35, qbx = -126.3
qv = -35; qb = 145;
q(6,:) = bonAngle(qv,qb);
q_r(6,:) = [-35, -126.3];

VerifT1 = zeros(1,6);
for indice = 1: length(q)
    if abs(q(indice,1) - q_r(indice,1)) < 0.01 && abs(q(indice,2) - q_r(indice,2)) < 1
        VerifT1(1,indice) = 1;
    end
end

%% transMat_w2f
Tw0 =   [1    0   0   0;
        0   1   0   0;
        0   0   1   0;
        0   0   0   1];
    
VerifT2 = zeros(1,6);

% Test 1 : qv et qbx sont 0;
q = [0,0,0];
T = transMat_w2f(q,Tw0);
T_r = [1 0 0 0 1 0 0 lv 1 0 0 lv+lbx; 0 1 0 0 0 1 0 0 0 1 0 0; 0 0 1 0 0 0 1 0 0 0 1 0; 0 0 0 1 0 0 0 1 0 0 0 1];
if T == T_r
    VerifT2(1) = 1;
end

% Test 2 : qv = pi/2 et qbx = 0;
q = [pi/2,0,0];
T = transMat_w2f(q,Tw0);
T_r = [0 -1 0 0 1 0 0 0 1 0 0 lbx; 1 0 0 0 0 1 0 lv 0 1 0 lv; 0 0 1 0 0 0 1 0 0 0 1 0; 0 0 0 1 0 0 0 1 0 0 0 1];
Err = abs(T - T_r);
VerifT2(2) = 1;
for indice = 1:4*12
    if Err(indice) > 0.1
        VerifT2(2) = 0;
    end
end

% Test 3 : qv = 0 et qbx = -pi/2
q = [0,-pi/2,0];
T = transMat_w2f(q,Tw0);
T_r = [1 0 0 0 0 1 0 lv 0 1 0 lv; 0 1 0 0 -1 0 0 0 -1 0 0 -lbx; 0 0 1 0 0 0 1 0 0 0 1 0; 0 0 0 1 0 0 0 1 0 0 0 1];
Err = abs(T - T_r);
VerifT2(3) = 1;
for indice = 1:4*12
    if Err(indice) > 0.1
        VerifT2(3) = 0;
    end
end

% Test 4 : qv = -pi/4 et qbx = -pi/2
q = [-pi/4,-pi/2,0];
T = transMat_w2f(q,Tw0);
T_r = [0.7071 0.7071 0 0 0 1 0 51.2652 0 1 0 51.2652; -0.7071 0.7071 0 0 -1 0 0 -51.2652 -1 0 0 -167.3652; 0 0 1 0 0 0 1 0 0 0 1 0; 0 0 0 1 0 0 0 1 0 0 0 1];
Err = abs(T - T_r);
VerifT2(4) = 1;
for indice = 1:4*12
    if Err(indice) > 0.1
        VerifT2(4) = 0;
    end
end

% Test 5 : qv = -pi/8 et qbx = -pi/4
q = [-pi/8,-pi/4,0];
T = transMat_w2f(q,Tw0);
T_r = [0.9239 0.3827 0 0 0.7071 0.7071 0 66.9813 0.7071 0.7071 0 149.0764; -0.3827 0.9239 0 0 -0.7071 0.7071 0 -27.7445 -0.7071 0.7071 0 -109.8396; 0 0 1 0 0 0 1 0 0 0 1 0; 0 0 0 1 0 0 0 1 0 0 0 1];
Err = abs(T - T_r);
VerifT2(5) = 1;
for indice = 1:4*12
    if Err(indice) > 0.1
        VerifT2(5) = 0;
    end
end

% Test 5 : qv = -pi/8 et qbx = -pi/4
q = [-pi/8,-pi/4,0];
T = transMat_w2f(q,Tw0);
T_r = [0.9239 0.3827 0 0 0.7071 0.7071 0 66.9813 0.7071 0.7071 0 149.0764; -0.3827 0.9239 0 0 -0.7071 0.7071 0 -27.7445 -0.7071 0.7071 0 -109.8396; 0 0 1 0 0 0 1 0 0 0 1 0; 0 0 0 1 0 0 0 1 0 0 0 1];
Err = abs(T - T_r);
VerifT2(5) = 1;
for indice = 1:4*12
    if Err(indice) > 0.1
        VerifT2(5) = 0;
    end
end

% Test 5 : qv = -pi/4 et qbx = -pi/8
q = [-pi/4,-pi/8,0];
T = transMat_w2f(q,Tw0)
T_r =  [0.7071    0.7071         0         0    0.9239    0.3827         0   51.2652    0.9239    0.3827         0  158.5277;
        -0.7071    0.7071         0         0   -0.3827    0.9239         0  -51.2652   -0.3827    0.9239         0  -95.6948;
         0         0    1.0000         0         0         0    1.0000         0         0         0    1.0000         0;
         0         0         0    1.0000         0         0         0    1.0000         0         0         0    1.0000];
Err = abs(T - T_r);
VerifT2(6) = 1;
for indice = 1:4*12
    if Err(indice) > 0.1
        VerifT2(6) = 0;
    end
end

%%
bb = bonAngle(-25,100);
% qq = trans_mat(bb
test1 = CartesienPatte(-25, 100);

%% Vérification globale
Verif(:,:,1) = [1,1,1,1,1,0];
Test_bonAngle = 'Échoué';
if Verif(:,:,1) == VerifT1
    Test_bonAngle = 'Réussi'
end

Verif(:,:,2) = [1,1,1,1,1,1];
Test_bonAngle = 'Échoué';
if Verif(:,:,2) == VerifT2
    Test_bonAngle = 'Réussi'
end


