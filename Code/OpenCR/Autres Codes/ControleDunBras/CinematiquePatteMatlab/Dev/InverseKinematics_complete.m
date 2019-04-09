%Created 2018-10-25 by Simon Michaud @Kinova
%Modified 2018-11-06

%Inverse kinematics function that returns the angular position of the robot
%from a given cartesian position 

%Arguments: Convention of the DH parameters, number of degrees of freedom,
            %the DH parameters, the transformation matrix from world frame
            %to the 0 DH frame, the goal cartesian position of the end 
            %effector, the guessed angular position and the units of the 
            %angles of the angular position
%Returns:   6x1 vector containing the angular position of the robot

function q = InverseKinematics_complete(convention, DOF,DH, TW0, Pgoal, theta, angleUnit)
%% For not a function, uncomment next lines

%     clear all;
%     convention = 'Classic';
%     DOF = 6;
%     theta = [250,180,100,275,200,0];
%     Pgoal = [0.5;-0.25;0.7;-2;1.5;1.9];
%     TW0 = [1 0 0 0; 0 -1 0 0; 0 0 -1 0; 0 0 0 1];   
%     Lengths of the links of the robots
%     D1 = 0.2755;
%     D2 = 0.4100;
%     D3 = 0.2073;
%     D4 = 0.1038;
%     D5 = 0.1038;
%     D6 = 0.16;
%     e2 = 0.0098;
% 
%     %Angles of the guessed position in the DH algorithm form
%     q = transpose(ThetaAlgo(theta));
% 
%     %DH parameters in the smae format as we have seen before [alpha, d, a]
%     DH = [pi/2, 0, -D1; pi, D2, 0; pi/2, 0, -e2; pi/2, 0, -(D3+D4); pi/2, 0, 0; pi, 0,  -(D5+D6)];

%% Foward Kinematics for initial point
%Obtainning right angles for the different functions
    q = theta;
    if strcmp(angleUnit, 'Degrees')
        q = q*pi/180;
        angleUnit = 'Radians';
    end
    
%Use of the Foward Kinematics to find the cartesian position of the guessed
%position
    Pcurr = FKforIK(convention, DOF, DH, TW0, q, angleUnit);


%% Inverse Kinematics algorithm using Newton-Raphson Iterative Method for multivariable functions

    Rgoal=EulerXYZtoRot(Pgoal(4:6));        %Goal rotation matrix
    ii = 1;
    Err = abs(Pgoal-Pcurr);                 %Error between Pgoal and Pcurr
    
    while max(Err)>0.001                    %Beginning of the iterative method
%     for ii=1:1000                         %Uncomment line if you prefer a number of iterations rather than an error to respect
        Pcurr_old = Pcurr;
        Rcurr=EulerXYZtoRot(Pcurr(4:6));    %Current rotational matrix from Euler angles
        delta_R=Rgoal-Rcurr;                %Difference between matrices
        Omega=delta_R/Rcurr;                %matrix differential rule: delta_R=Omega*Rcurr. So Omega = delta_R*inv(Rcurr)

        dX(4,:)=(Omega(3,2)-Omega(2,3))/2;  %Finding wx from W
        dX(5,:)=(Omega(1,3)-Omega(3,1))/2;  %Finding wy from W
        dX(6,:)=(Omega(2,1)-Omega(1,2))/2;  %Finding wz from W

        dX(1:3,:) = Pgoal(1:3)-Pcurr(1:3);  %positional displacement as seen in the class notes
        J = Jacobian_complete(convention, DOF, DH, TW0,q, angleUnit);   %Determination of the Jacobian at angle q
        dTheta = J\dX;                      %Inverse Kinematics formula
        q = q + dTheta;                     %Finding new angles
        Pcurr = FKforIK(convention, DOF, DH, TW0, q, angleUnit); %Determining new Pcurr from new q
        Err = abs(Pcurr_old-Pcurr);         %Determining Err from new Pcurr
        ii = ii+1;
        
    end
    
end