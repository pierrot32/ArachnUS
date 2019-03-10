%Created 2018-09-25 by Simon Michaud @Kinova
%Modified 2018-10-31 @10:11 am

%Foward kinematics function that returns the cartesian position of the end
%effector from the angular position of the robot

%Arguments: Convention of the DH parameters, the DH parameters, the 
            %transformation matrix from world frame to the 0 DH frame, 
            %the goal cartesian position of the end effector, the guessed
            %angular position and the units of the angles of the angular 
            %position
%Returns:   3x7 vector containing the cartesian position of the angles of
            %the robot where each column is a joint and column 1 is the
            %base

function [coordinates] = forwardKinematicsJaco6DOFS_complete(convention, DH, TW0, q, angleUnit)
%% Parameters for the creation of the FK
   for i=1:6
       alpha(i) = DH(i,1);
       d(i) = DH(i,3);
       a(i) = DH(i,2);
   end    
   
   if strcmp(angleUnit, 'Degrees')
        q = q*pi/180;
        angleUnit = 'Radians';
    end
%% Computing of the transformation matrices
    if strcmp(convention,'Modified')
        %Transformation matrix ^{n-1}T^{n}
        for i=1:6
            T(:,:,i)=[cos(q(i)) -sin(q(i)) 0 a(i);...
                sin(q(i))*cos(alpha(i)) cos(alpha(i))*cos(q(i)) -sin(alpha(i)) -d(i)*sin(alpha(i)); ...
                sin(q(i))*sin(alpha(i)) cos(q(i))*sin(alpha(i)) cos(alpha(i)) d(i)*cos(alpha(i));...
                0 0 0 1];
        end

    elseif strcmp(convention, 'Classic')
        
        %Transformation matrix ^{n-1}T^{n}
        for i=1:6
            T(:,:,i)=[cos(q(i)) -sin(q(i))*cos(alpha(i)) sin(q(i))*sin(alpha(i)) a(i)*cos(q(i));...
                sin(q(i)) cos(alpha(i))*cos(q(i)) -cos(q(i))*sin(alpha(i)) a(i)*sin(q(i)); ...
                0 sin(alpha(i)) cos(alpha(i)) d(i);...
                0 0 0 1];
            
        end
    end
    %Transformation matrices from the base to the joint i
    T0(:,:,1) = TW0*T(:,:,1);
    for i = 2:6
        T0(:,:,i) = T0(:,:,i-1)*T(:,:,i);
%          R0(:,:,i) = [T0(1,1,i), T0(1,2,i), T0(1,3,i);T0(2,1,i),T0(2,2,i),T0(2,3,i);T0(3,1,i),T0(3,2,i),T0(3,3,i)];
        R0(:,:,i) = [T0(1:3,1,i), T0(1:3,2,i), T0(1:3,3,i)];

        ri_0(:,:,i) = [T0(1,4,i), T0(2,4,i), T0(3,4,i)];
    end
        
%% Positions and orientation of the joints from transformation matrices
        %Physical positions of the origins of the frames to view the robot
        J6 = [T0(1:3,4,6)];
        J5 = [T0(1:3,4,5)];
        J4 = [T0(1:3,4,4)];
        J3 = [T0(1:3,4,3)];
        J2 = [T0(1:3,4,2)];
        J1 = [T0(1:3,4,1)];
        J0 = [TW0(1:3,4)];
        coordinates = [J0,J1,J2,J3,J4,J5,J6];
    
        
    %Definition of the rotation matrices and the position vectors from the
    %transformation matrix to obtain the position and orientation of the
    %effector
    r6_0 = [T0(1,4,6); T0(2,4,6); T0(3,4,6)];
    EulerXYZ = MatRotationToEuler(R0(:,:,6));
    X = [r6_0;EulerXYZ];
end
