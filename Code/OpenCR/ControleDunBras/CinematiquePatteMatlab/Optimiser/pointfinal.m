% pointfinal - ArachnUS - Cinématique de Patte
% Fonction qui trouve la position du bout de la patte à partir de ce qui a
% été calculé par la cinématique directe ou inverse
% Création : 13 Mars 2019 - 10h
% Dernière Modification : 13 Mars 2019 - 10h

function P = pointfinal(A, op);
    
    Add = [0;12;0];

    if op == 1
        P = A - Add;
    elseif op == -1
        P = A + Add;
    else
        message = 'Entre une valeur de op soit de 1 ou de -1 pour ajouter ou enlever la distance du bout de la patte'
        P = A;
    end
end