function Euler=MatRotationToEuler(T)

nx=T(1,1);ny=T(2,1);nz=T(3,1);
ox=T(1,2);oy=T(2,2);oz=T(3,2);
ax=T(1,3);ay=T(2,3);az=T(3,3);

% ay=0;
% az=0;

A1=atan2(-ay, az);
A1tt=atan2(az,-ay);
% A2=atan2(ay,-az);
B1=atan2(ax,(-1 * sin(A1)) * ay + cos(A1) * az);
% B2=atan2(ax,-sin(A2)*ay+sin(A1)*oz+cos(A2)*az);
C1=atan2(cos(A1) * ny + sin(A1) * nz, cos(A1) * oy + sin(A1) * oz);

% [A1;B1;C1;A2;B2;C2]*180/pi
if (abs(ax-1) < 0.000006)
    A1f = atan2(ny, oy) / 2;
    B1f = pi / 2;
    C1f = atan2(ny, oy) / 2;
elseif (abs(ax+1) < 0.000006)
    A1f = atan2(-ny, oy) / 2;
    B1f = -pi / 2;
    C1f = -atan2(-ny, oy) / 2;
else
    A1f=A1;
%     A2f=A2;
    C1f=C1;
%     C2f=C2;
    B1f=B1;
%     B2f=B2;
end

Euler=[A1f;B1f;C1f];




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


  x(1) = T(1,1);
  x(2) =  T(1,2);
  x(3) =  T(1,3);
  x(4) =  T(2,1);
  x(5) =  T(2,2);
  x(6) =  T(2,3);
  x(7) =  T(3,1);
  x(8) =  T(3,2);
  x(9) =  T(3,3);

    t1 = x(6);
    t2 = t1*t1;
    t3 = x(9);
    t4 = t3*t3;
    t6 = sqrt(t2+t4);
    t7 = 1/t6;
    t9 = x(3);
    t10 = t9*t9;
    t12 = sqrt(t10+t2+t4);
    Fv(1) = atan2(-t1*t7*t12,t3*t7*t12);
    Fv(2) = atan2(t9,t6);
    t22 = atan2(-x(1)*t7*t12,x(2)*t7*t12);
    Fv(3) = -t22-0.15707E1;
  
test=1;