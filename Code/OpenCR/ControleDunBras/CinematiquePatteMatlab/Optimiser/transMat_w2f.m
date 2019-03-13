% transMat_w2f - ArachnUS - Cinématique de Patte
% Fonction qui retourne la matrice de transformation du world frame au
% référentiel F avec les paramètres DH de la patte, les angles des moteurs
% Création : 13 Mars 2019 - 10h
% Dernière Modification : 13 Mars 2019 - 10h

function TwFi = transMat_w2f(q, Tw0)
    % ======== Constantes =========
    lv = 72.5;      % mm
    lbx = 116.1;    % mm
    F = 3;
    
    % ======== Paramètres DH ========
    %       alpha    ri_1   di      theta       
    dh = [  0       0       0;
            0       lv      0;
            0       lbx     0];

    for index=1:F
       alpha(index) = dh(index,1);
       d(index) = dh(index,3);
       r(index) = dh(index,2);
    end
    
    % ======== Matrice de transformation ========
    % Matrice de transformation entres frames
    for index=1:F
        Ti_im1(:,:,index)=[cos(q(index)) -sin(q(index)) 0 r(index);...
                           sin(q(index))*cos(alpha(index)) cos(alpha(index))*cos(q(index)) -sin(alpha(index))  -d(index)*sin(alpha(index)); ...
                           sin(q(index))*sin(alpha(index)) cos(q(index))*sin(alpha(index)) cos(alpha(index))   d(index)*cos(alpha(index));...
                           0 0 0 1];
    end

    % Matrices de transformations entre joint et world frame
    T0(:,:,1) = Tw0*Ti_im1(:,:,1);
    for index = 2: F
        T0(:,:,index) = T0(:,:,index-1)*Ti_im1(:,:,index);
    end
    
    TwFi = [T0(:,:,1) T0(:,:,2) T0(:,:,3)];

end