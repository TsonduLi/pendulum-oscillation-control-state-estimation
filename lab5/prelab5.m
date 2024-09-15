G=tf([1 3],[1 2 5]);
[A,B,C,D] = tf2ss([1 3],[1 2 5]);
B_new=[0;0]
G_new=ss(A,B_new,C,D);
t = (0:0.001:10)';
u =t>=0;
a=-1000000;
u=u.*exp(a*t)
u(isnan(u))=0;
plot(t,u);
y0=[0 ;0];
figure(1);lsim(G,u,t,y0);grid on;
figure(2);impulse(G_new,t);grid on;
% y=lsim(G,u,t,y0);
% plot(t,y);
