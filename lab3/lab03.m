% PROPORTIONAL 
syms alpha
C=0.02;
P=tf([2550],[0.36 1 0]);
figure(1);margin(C*P);
T=C*P/(1+C*P);
figure;bode(T);hold on;legend ('Bode plot of T','Bode plot of P','interpreter','latex');
bode(P);


%%
%%q2
clc;
C_lag=tf([10 11.7],[10 0]);
alpha_num=double(solve(asind((alpha-1)/(alpha+1))==-7.5833+45));
C_lead=tf([sqrt(alpha_num) 11.7],[1  sqrt(alpha_num)*11.7] );
C1=0.02*C_lag*C_lead;
figure(2);step(C1*P/(1+C1*P));
figure(3);step(P/(1+C1*P));
figure(4);margin(C1*P);
CLTF=feedback(C1*P,1);
info_servo1=stepinfo(CLTF);
T1=C1*P/(1+C1*P);
figure;bode(T1);hold on;legend ('Bode plot of T','Bode plot of P','interpreter','latex');
bode(P);

%% 
N=C1*P
figure;nyquist(N);
G1=C1*P/0.02;
figure;rlocus(G1);

%%

wc=20;
k=1/bode(P,wc);
C2=k;
figure;margin(C2*P);

%%
%%q3

C_lag=tf([10 20],[10 0]);
alpha_num=double(solve(asind((alpha-1)/(alpha+1))==-7.5833+45+5.4));
C_lead=tf([sqrt(alpha_num) 20],[1  sqrt(alpha_num)*20] );
C2=k*C_lag*C_lead;
figure(2);step(C2*P/(1+C2*P));
figure(3);step(P/(1+C2*P));
figure(4);margin(C2*P);
step(C2*P/(1+C2*P));
CLTF=feedback(C2*P,1);
info_servo2=stepinfo(CLTF);
T2=C2*P/(1+C2*P);
figure;bode(T2);hold on;legend ('Bode plot of T','Bode plot of P','interpreter','latex');
bode(P);
%% 
G2=C2*P/k;
rlocus(G2);
bode(C2/(1+C2*P));
N2=C2*P
figure;nyquist(N2);


%%
%%4
% 
% figure;plot(out.simout1.Time,out.simout1.Data);grid on
% figure;plot(out.simout2.Time,out.simout2.Data);grid on

% % % Q4 SERVO1
load('data2_servo1.mat');
figure;plot(out.control_effort1.Time,out.control_effort1.Data);hold on;
plot(u_0.time,u_0.signals.values);
xlabel('Time [sec]','interpreter','latex');ylabel('Control effort [V]','interpreter','latex');grid on;
legend ('Simulation Result in Simulink','Experimental result','interpreter','latex');
xlim([0,50]);

figure;plot(out.simout1.Time,out.simout1.Data);hold on;
plot(y_deg_0.time,y_deg_0.signals.values);
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
legend ('Simulation Result in Simulink','Experimental result','interpreter','latex');
xlim([0,50]);

%%  Q4 servo2
load('data_1_servo2.mat');
figure;plot(out.control_effort2.Time,out.control_effort2.Data);hold on;
plot(u_0.time,u_0.signals.values);
xlabel('Time [sec]','interpreter','latex');ylabel('Control effort [V]','interpreter','latex');grid on;
legend ('Simulation Result in Simulink','Experimental result','interpreter','latex');
xlim([0,50]);

figure;plot(out.simout2.Time,out.simout2.Data);hold on;
plot(y_deg_0.time,y_deg_0.signals.values);
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
legend ('Simulation Result in Simulink','Experimental result','interpreter','latex');
xlim([0,50]);

%% Q5 

load('datasin_servo1_2HZ.mat');
figure;plot(y_deg_0.time,y_deg_0.signals.values);grid on;
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
xlim([0,30]);

load('datasin_servo1_3HZ.mat');
figure;plot(y_deg_0.time,y_deg_0.signals.values);grid on;
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
xlim([0,30]);

load('datasin_servo2_3HZ.mat');
figure;plot(y_deg_0.time,y_deg_0.signals.values);grid on;
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
xlim([0,30]);

load('datasin_servo2_2HZ.mat');
figure;plot(y_deg_0.time,y_deg_0.signals.values);grid on;
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
xlim([0,30]);

%% 
% F=tf([30^2],[1 1.6*30 30^2]);
omega=0.1:0.001:1000
%% servo 1
bode(F*C1*P/(1+C1*P),omega);
[mag, phase]=bode(F*C1*P/(1+C1*P),omega);
figure;
mag=squeeze(mag);
mag=20*log10(mag);
phase=squeeze(phase);
subplot(211);semilogx(omega,mag);grid on;ylabel('Magnitude (dB)',FontSize=11);title('Bode Diagram',FontSize=11);
subplot(212);semilogx(omega,phase);grid on;ylabel('Phase (deg)',FontSize=11);
xlabel('Frequency (rad/s)',FontSize=11);

%% 
syms x;
R_2hzC1=double(solve(20*log10(x)==1.46714)); 
R_3hzC1=double(solve(20*log10(x)==-3.72279))

fplot(@(x) 15*R_2hzC1*sin(2*2*pi*x-112.766*pi/180));hold on
load('datasin_servo1_2HZ.mat');
plot(y_deg_0.time,y_deg_0.signals.values,'--');grid off;
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');
xlim([0,20]);
legend ('Theoretical response','Experimental result')

figure;fplot(@(x) 15*R_3hzC1*sin(3*2*pi*x-170.755*pi/180));hold on
load('datasin_servo1_3HZ.mat');
plot(y_deg_0.time,y_deg_0.signals.values,'--');grid on;
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
xlim([0,20]);ylim([-15,15])
legend ('Theoretical response','Experimental result');

%% servo 2
syms s
bode(F*C2*P/(1+C2*P),omega);
G=F*C2*P/(1+C2*P)
[mag, phase]=bode(F*C2*P/(1+C2*P),omega);
figure;
mag=squeeze(mag);
mag=20*log10(mag);
phase=squeeze(phase);
subplot(211);t=semilogx(omega,mag);grid on;ylabel('Magnitude (dB)',FontSize=11);title('Bode Diagram',FontSize=11);
datatip(t,2*2*pi,1);datatip(t,3*2*pi,1);

% datatip()
subplot(212);tt=semilogx(omega,phase);grid on;ylabel('Phase (deg)',FontSize=11);
% datatip(target,12.566);
xlabel('Frequency (rad/s)',FontSize=11);
datatip(tt,2*2*pi,1);datatip(tt,3*2*pi,1);

%% 
syms x;
R_2hzC2=double(solve(20*log10(x)==2.42426)); 
R_3hzC2=double(solve(20*log10(x)==1.22506))

fplot(@(x) 15*R_2hzC2*sin(2*2*pi*x-70.1722*pi/180));hold on
load('datasin_servo2_2HZ.mat');
plot(y_deg_0.time,y_deg_0.signals.values,'--');grid off;
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');
xlim([0,20]);ylim([-25,25]);
legend ('Theoretical response','Experimental result')

figure;fplot(@(x) 15*R_3hzC2*sin(3*2*pi*x-120.127*pi/180));hold on
load('datasin_servo2_3HZ.mat');
plot(y_deg_0.time,y_deg_0.signals.values,'--');grid on;
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
xlim([0,20]);ylim([-20,20]);
legend ('Theoretical response','Experimental result');

%% Q6

load('data_pendulum_servo2.mat');

figure;plot(u_0.time,u_0.signals.values);
xlabel('Time [sec]','interpreter','latex');ylabel('Control effort [V]','interpreter','latex');grid on;
xlim([0,50]);ylim([-1,1])

figure;plot(y_deg_0.time,y_deg_0.signals.values);
xlabel('Time [sec]','interpreter','latex');ylabel('Arm rotation [degree]','interpreter','latex');grid on;
xlim([0,50]);