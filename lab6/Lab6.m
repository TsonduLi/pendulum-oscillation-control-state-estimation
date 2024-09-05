syms y theta dy d_theta u ddy dd_theta
syms m L r g J f c Km Kb Ra Nr Ku
q = [y dy theta d_theta];
par = [m             L       r    g   J       f     c          Km      Kb Ra Nr Ku];
value = [0.051 0.40909 0.287727 9.807 5.7e-3  8.8e-3  0.00034965 24.2e-3  24.2e-3*60/(2*pi) 2.21 4.5 12];

Tau = Nr*Km/Ra*(Ku*u-Nr*Kb*dy);
M = [J+m*r^2 0.5*m*L*r; 0.5*m*L*r m*L^2/3];
K = [0; 0.5*m*g*L*theta];
Q = [Tau-f*dy; -c*d_theta];

ddq = M\(Q-K);

A = [dy;ddq(1);d_theta;ddq(2)];
A = simplify(jacobian(A,q))
A = double(subs(A,par,value))

B = [0;ddq(1);0;ddq(2)];
B = simplify(jacobian(B,u))
B = double(subs(B,par,value));

C=[1 0 0 0;0 0 1 0];
C_stae_vector=[0 1 0 0;0 0 0 1];
D=zeros(2,1);
% O=[C;C*A;C*A^2;C*A^3];
% Control=[B A*B A^2*B A^3*B]


Km=24.2*0.001;
% Kb=6.46e-3*60/(2*pi);
Kb=24.2e-3*60/(2*pi);
Ra=2.21;
La=260e-6
J=0.0057;
f=0.0088;
Nr=4.5

M=51e-3;
r=0.287727;
L=0.40909;
% c=0.01; not given
g=9.807;
c=0.00034965;
Ku=12;
s=tf('s')
q=2*M*L^2*s^2+6*c*s+3*M*L*g;
Py=180/pi* ((Ku*Km*Nr*q/Ra)/ (s*((J+M*r^2)*s+f)*q-1.5*(M*L*r)^2*s^4+s*(Kb*Km*Nr^2*q/Ra)))
F=30^2/(s^2+48*s+900);
% P_theta=tf([-1.143 0 0],[1 0.1679 35.97])
P_theta=-3*M*L*r*s^2/q;
% step(F*(C1*Py)/(1+C1*Py)*P_theta);
P_theta=zpk(P_theta);
Py=zpk(Py);

%% ob and control
Con=[B A*B A^2*B A^3*B];
O=[C;C*A;C*A^2;C*A^3];
r=rank(O);
rc=rank(Con);

%% 
identity4=eye(4);
k1=0.02;
K_feedback=[k1 0 0 0]*180/pi;
%% 

poles=eig(A-B*K_feedback);
poles_modified=[-1.3863+0.05;
                -1.3863-0.05;
                -0.1960+0.05;
                -0.1960-0.05];



Cy=[1 0 0 0];
Cy_theta=[1 0 0 0;0 0 1 0];

Ly_slow=place(A',180/pi*Cy',poles_modified*3)';
Ly_fast=place(A',180/pi*Cy',poles_modified*6)';
Ly_theta_slow=place(A',180/pi*Cy_theta',poles_modified*3)';                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
Ly_theta_fast=place(A',180/pi*Cy_theta',poles_modified*6)';


% KK=place(A,B,poles);
% LL=place(A',C',poles);
%% 
% A=[0 1 0 0;
%     0 -2.9925 27.5561 0.1272;
%     0 0 0 1;
%     0 1.6958 -37.2818 -0.1721];
% C2=[1 0 0 0;0 0 1 0];
% p=[-6; -6 ;-8 ;-8];
% L=place(A',C2',p)


