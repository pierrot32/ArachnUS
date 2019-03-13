function  Q  = EulerXYZtoRot(Euler)
    c1 = cos(Euler(1));
    s1 = sin(Euler(1));
    c2 = cos(Euler(2));
    s2 = sin(Euler(2));
    c3 = cos(Euler(3));
    s3 = sin(Euler(3));
    % Q = multiplication of three rotations [X][Y][Z]
    Q = [[c2*c3; c1*s3 + c3*s1*s2; s1*s3 - c1*c3*s2],[-c2*s3; c1*c3 - s1*s2*s3; c3*s1 + c1*s2*s3],[s2; -c2*s1; c1*c2]];
end

