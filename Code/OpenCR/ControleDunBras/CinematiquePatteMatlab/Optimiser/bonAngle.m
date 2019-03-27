% bonAngle - ArachnUS - Cinématique de Patte
% Fonction qui retourne les bons anles qv, et qb
% Création : 20 Mars 2019 - 11h
% Dernière Modification : 20 Mars 2019 - 11h30
function q = bonAngle(qv, qb)

qbx = -1.0914*qb + 27.979;       % Angle de bleu1 à partir de vert1

if qb <= 137.25 && qb > 122.5
    qbx = qbx - ( 4e-07*qv^4 + 3e-05*qv^3 + 0.0003*qv^2 + 0.0665*qv - 0.7918);
elseif qb <= 122.5 && qb > 107.5
    qbx = qbx - (-7e-09*qv^5 - 3E-07*qv^4 + 2E-05*qv^3 + 0.0001*qv^2 + 0.07*qv - 0.5725);
elseif qb <= 107.5 && qb > 90
    qbx = qbx - ( 1e-05*qv^3 - 0.0005*qv^2 + 0.0783*qv - 0.7722);
elseif qb <= 90 && qb > 70
    qbx = qbx - ( 2e-05*qv^3 - 0.0015*qv^2 + 0.1111*qv - 0.8019 );
elseif qb <= 152.5 && qb > 137.5 
    qbx = qbx - ( 6e-08*qv^5 + 5e-06*qv^4 + 0.0001*qv^3 + 0.0005*qv^2 + 0.0793*qv - 0.7672);
end
    

q = [qv; qbx;0];


end 