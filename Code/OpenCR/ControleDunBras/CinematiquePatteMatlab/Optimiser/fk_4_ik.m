% fk_4_ik - ArachnUS - Cinématique de Patte
% Fonction qui fait la cinématique directe pour la cinématique inverse
% Création : 13 Mars 2019 - 11h
% Dernière Modification : 13 Mars 2019 - 11h

function fk = fk_4_ik(q, Tw0)
    TwF = transMat_w2f(q, Tw0);
    Tw3 = TwF(1:4, 9:12);
    fkc = findpoint(Tw3);
    
    Rw3 = TwF(1:3, 9:11);
    fkr = MatRotationToEuler(Rw3);
    
    fk = [fkc; fkr];
end
