% transMat_w2f - ArachnUS - Cinématique de Patte
% Fonction qui retourne la matrice de transformation du world frame au
% référentiel F avec les paramètres DH de la patte, les angles des moteurs
% Création : 13 Mars 2019 - 10h
% Dernière Modification : 20 Mars 2019 - 9h

function TwFi = transMat_w2f(q, Tw0)
    % ======== Constantes =========
    lv = 72.5;      % mm
    lbx = 116.1;    % mm
    F = 3;
    
    qv = q(1);
    qbx = q(2);
    % ======== Matrice de transformation ========
    % Matrice de transformation entres 0 et frame i
    T0Fi(:,:,1) = [cos(qv)  -sin(qv)    0   0;
                    sin(qv) cos(qv)     0   0;
                    0       0           1   0;
                    0       0           0   1];
    T0Fi(:,:,2) = [cos(qbx)  -sin(qbx)  0   lv*cos(qv);
                    sin(qbx) cos(qbx)   0   lv*sin(qv);
                    0       0           1   0;
                    0       0           0   1];
                
    T0Fi(:,:,3) = [cos(qbx)  -sin(qbx)  0   lv*cos(qv)+lbx*cos(qbx);
                    sin(qbx) cos(qbx)   0   lv*sin(qv)+lbx*sin(qbx);
                    0       0           1   0;
                    0       0           0   1];

    % Matrices de transformations entre joint et world frame
    for ind = 1:3
        T0(:,:,ind) = Tw0*T0Fi(:,:,ind);
    end 
    
    TwFi = [T0(:,:,1) T0(:,:,2) T0(:,:,3)];

end