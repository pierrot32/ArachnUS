%Function made to execute the foward kinematics necessary for inverse
%kinematics. It recieves the standard arguments for foward kinematics
%functions but instead of returning T0_6 is returns the position and
%ortientation vector which is a 6x1 vector.

%Simon Michaud
%Creation: 2018-10-05
%Modifications 2018-10-22

%% Function definition
function FK = FKforIK(convention, DOF, DH, TW0, q, angleUnit)
%% Uncomment for not a function
% clear all;
% convention = 'modified';
% DOF = 6;
% theta = [90,270,90,270,270,270];
% theta = [180, 180,180,180,180,180];
% theta = [238,238,100,210,200,0];

%% DH Parameters of the manipulator
%DH = [0, 0, -D1, q(1); pi/2, 0, 0, q(2); pi ,D2, -e2, q(3); pi/2, 0, -(D3+D4), q(4); pi/2, 0, 0, q(5); pi/2, 0, (D5+D6), q(6)];
 
for i=1:DOF
       alpha(i) = DH(i,1);
       d(i) = DH(i,3);
       a(i) = DH(i,2);
%        q(i) = DH(i,4);
end    
   
if strcmp(angleUnit, 'Degrees')
        q = q*pi/180;
end
 

%% Creation of the transformation matrices and the corresponding rotation matrices
for i=1:DOF
    if strcmp(convention, 'Classic')
        T(:,:,i)=[cos(q(i)) -sin(q(i))*cos(alpha(i)) sin(q(i))*sin(alpha(i)) a(i)*cos(q(i));...
                sin(q(i)) cos(alpha(i))*cos(q(i)) -cos(q(i))*sin(alpha(i)) a(i)*sin(q(i)); ...
                0 sin(alpha(i)) cos(alpha(i)) d(i);...
                0 0 0 1];
    elseif strcmp(convention, 'Modified')
        T(:,:,i)=[cos(q(i)) -sin(q(i)) 0 a(i);...
            sin(q(i))*cos(alpha(i)) cos(alpha(i))*cos(q(i)) -sin(alpha(i)) -d(i)*sin(alpha(i)); ...
            sin(q(i))*sin(alpha(i)) cos(q(i))*sin(alpha(i)) cos(alpha(i)) d(i)*cos(alpha(i));...
            0 0 0 1];
    end
    Ri_i1(:,:,i) = [T(1:3,1,i), T(1:3,2,i), T(1:3,3,i)];
    Ri1_i(:,:,i) = transpose(Ri_i1(:,:,i));
           
end
%% Creation of the transformation matrices and rotation matrices with respect to the base
T0=TW0;
T0(:,:,1) = T0 *T(:,:,1);
R0 = [TW0(1:3,1), TW0(1:3,2), TW0(1:3,3)];
R0(:,:,1) = R0*Ri_i1(:,:,1);
ri_0(:,:,1) = [T0(1,4,1), T0(2,4,1), T0(3,4,1)];
for i = 2:DOF
    T0(:,:,i) = T0(:,:,i-1)*T(:,:,i);
    R0(:,:,i) = R0(:,:,i-1)*Ri_i1(:,:,i);
    ri_0(:,:,i) = [T0(1,4,i), T0(2,4,i), T0(3,4,i)];
end
%%Unit vectors of the different vector basis
for i = 1:DOF
   ux(:,:,i) = transpose([T0(1,4,i), T0(2,4,i), T0(3,4,i)]) + R0(:,:,i)*[0.1;0;0]; 
   uy(:,:,i) = transpose([T0(1,4,i), T0(2,4,i), T0(3,4,i)]) + R0(:,:,i)*[0;0.1;0]; 
   uz(:,:,i) = transpose([T0(1,4,i), T0(2,4,i), T0(3,4,i)]) + R0(:,:,i)*[0;0;0.1]; 
end
EulerXYZ = MatRotationToEuler(R0(:,:,DOF));
FK = [ri_0(1,1,DOF);ri_0(1,2,DOF);ri_0(1,3,DOF);EulerXYZ(1);EulerXYZ(2);EulerXYZ(3)];
end
%% plot 
% figure(1)
% plot3([ 0 T0(1,4,1) T0(1,4,2) T0(1,4,3) T0(1,4,4) T0(1,4,5) T0(1,4,6)],[0  T0(2,4,1) T0(2,4,2) T0(2,4,3) T0(2,4,4) T0(2,4,5) T0(2,4,6)],[0 T0(3,4,1) T0(3,4,2) T0(3,4,3) T0(3,4,4) T0(3,4,5) T0(3,4,6)], 'g')
%   
% xlabel('X')
%    ylabel('Y')
% %    xlim([-1 1])
% %    ylim([-1 1])
% %    zlim([-0.1 1.3])
%    view(210,40)
% grid on
% hold on 

% plot3([0],[0],[0], '-r*')
% for i=1:6
%    plot3([Pi_i1(1,1,i)], [Pi_i1(1,2,i)], [Pi_i1(1,3,i)], '-o') 
%    plot3([Pi_i1(1,1,i) ux(1,1,i)], [Pi_i1(1,2,i) ux(2,1,i)], [Pi_i1(1,3,i) ux(3,1,i)], 'r')
%    plot3([Pi_i1(1,1,i) uy(1,1,i)], [Pi_i1(1,2,i) uy(2,1,i)], [Pi_i1(1,3,i) uy(3,1,i)], 'm')
%    plot3([Pi_i1(1,1,i) uz(1,1,i)], [Pi_i1(1,2,i) uz(2,1,i)], [Pi_i1(1,3,i) uz(3,1,i)], 'b')
% end
% title('Representation of Jaco 6 DOF S')
% legend('link', 'origin', 'joint', 'ux', 'uy', 'uz')
