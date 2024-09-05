J=0.00497; %[kgm^2]  from conclusion of lab 2
f=0.00760; %[kgm^2/s]  from conclusion of lab 2
Km=0.0242; %[Nm/A]  given in lab 2
Kb=Km; %[Vs/rad]  given in lab 2
Ra=2.21; %[Omega]  given in lab 2
Nr=4.5; %[No unit]  from conclusion of lab 1
Ku=12; %[V]  given in lab 2

r=0.2675;
L=0.3866;
M=0.051;
g=9.81;
c=4.6143e-4;


A = [0  1                                                           0                                 0;
     0  -(4*f)/(M*r^2+4*J)-4/(M*r^2+4*J)*Nr*Km/Ra*Kb*Nr             (3*M*g*r)/(M*r^2+4*J)             6*c*r/(L*(M*r^2+4*J));
     0  0                                                           0                                 1;
     0  (6*f*r)/(L*(M*r^2+4*J))+6*r/(L*(M*r^2+4*J))*Nr*Km/Ra*Kb*Nr  -(6*g*(M*r^2+J))/(L*(M*r^2+4*J))  -(12*c*(M*r^2+J))/(M*L^2*(M*r^2+4*J))];

  
B = [0;
     4/(M*r^2+4*J);
     0;
     -6*r/(L*(M*r^2+4*J))]*Nr*Km/Ra*Ku; 

C1 = [1 0 0 0];
C2 = [0 0 1 0];
C = [C1; C2];

D = [0];

k1 = 0.02;
K = [k1 0 0 0]*180/pi;
poles=real(eig(A-B*K))+[0 0.01 0 0.01]';

s=tf('s');
q=2*M*L^2*s^2+6*c*s+3*M*L*g;
% Py=180/pi*(Ku*Km*Nr)*q/Ra/(s*((J+M*r^2)*s+f)*q-1.5*(M*L*r)^2*s^4+s*Kb*Km*Nr^2*q/Ra);
Ptheta=-3*M*L*r*s^2/q;
Py=180/pi*((Ku*Km*Nr*q/Ra)/(s*((J+M*r^2)*s+f)*q-1.5*(M*L*r)^2*s^4+s*(Kb*Km*Nr^2*q/Ra)));

Cy = [1 0 0 0];
Cy_theta = [1 0 0 0; 0 0 1 0];
x0=[20*pi/180;0;0;0];

% poles = 6*[-1.1096 -1.5 -2 -2.5];

Oy = obsv(A,Cy);
Ly_slow = (place(A',180/pi*Cy',3*poles))';
eig_val1 = eig(A-Ly_slow*180/pi*Cy)
Ly_fast = (place(A',180/pi*Cy',6*poles))';
eig_val2 = eig(A-Ly_fast*180/pi*Cy)

Oy_theta = obsv(A,Cy_theta);
Ly_theta_slow = (place(A',180/pi*Cy_theta',3*poles))';
eig_val3 = eig(A-Ly_theta_slow*180/pi*Cy_theta)
Ly_theta_fast = (place(A',180/pi*Cy_theta',6*poles))';
eig_val4 = eig(A-Ly_theta_fast*180/pi*Cy_theta)
