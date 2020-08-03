% SUBPLOT(3,1,1);plot(landRV1(:,1),landRV1(:,2));AXIS([0 380 -1.5 1.5]);grid;hold on;
% SUBPLOT(3,1,2);plot(landRV1(:,1),landRV1(:,3));AXIS([0 380 -1.5 1.5]);grid;hold on;
% SUBPLOT(3,1,3);plot(landRV1(:,1),landRV1(:,4));AXIS([0 380 -1.5 1.5]);grid;hold on;
close all;
% figure;
% SUBPLOT(3,1,1);plot(landRV(:,1),landRV(:,2));grid;hold on;
% SUBPLOT(3,1,2);plot(landRV(:,1),landRV(:,3));grid;hold on;
% SUBPLOT(3,1,3);plot(landRV(:,1),landRV(:,4));grid;hold on;
% figure;
% SUBPLOT(3,1,1);plot(landRV(:,1),landRV(:,5));grid;hold on;
% SUBPLOT(3,1,2);plot(landRV(:,1),landRV(:,6));grid;hold on;
% SUBPLOT(3,1,3);plot(landRV(:,1),landRV(:,7));grid;hold on;
% figure;
% SUBPLOT(3,1,1);plot(landRV(:,1),landRV(:,2)-landRV2(:,1));grid;hold on;
% SUBPLOT(3,1,2);plot(landRV(:,1),landRV(:,3)-landRV2(:,2));grid;hold on;
% SUBPLOT(3,1,3);plot(landRV(:,1),landRV(:,4)-landRV2(:,3));grid;hold on;
% figure;
% SUBPLOT(3,1,1);plot(landRV(:,1),landRV(:,5)-landRV2(:,4));grid;hold on;
% SUBPLOT(3,1,2);plot(landRV(:,1),landRV(:,6)-landRV2(:,5));grid;hold on;
% SUBPLOT(3,1,3);plot(landRV(:,1),landRV(:,7)-landRV2(:,6));grid;hold on;
% figure;
% SUBPLOT(3,1,1);plot(landRV(:,1),simout1(:,8));grid;hold on;
% SUBPLOT(3,1,2);plot(landRV(:,1),simout1(:,9));grid;hold on;
% SUBPLOT(3,1,3);plot(landRV(:,1),simout1(:,10));grid;hold on;
% figure;
% SUBPLOT(3,1,1);plot(landRV(:,1),simout1(:,11));grid;hold on;
% SUBPLOT(3,1,2);plot(landRV(:,1),simout1(:,12));grid;hold on;
% SUBPLOT(3,1,3);plot(landRV(:,1),simout1(:,13));grid;hold on;
% figure;
% plot3(landRV(:,2),landRV(:,3),landRV(:,4));grid;
% figure;
% SUBPLOT(3,1,1);plot(landRV(:,1),landRV1(:,2));grid;hold on;
% SUBPLOT(3,1,2);plot(landRV(:,1),landRV1(:,3));grid;hold on;
% SUBPLOT(3,1,3);plot(landRV(:,1),landRV1(:,4));grid;hold on;

% figure;
% plot(simout(:,1),simout(:,2)-simout1(:,2),'r');hold on;
% plot(simout(:,1),simout(:,3)-simout1(:,3),'b');hold on;
% plot(simout(:,1),simout(:,4)-simout1(:,4),'k');hold on;
% grid;
% Xlabel('Time(s)')
% Ylabel('Position Estimate Error(m)')
% AXIS([0 120 -80 80]);
% 
% 
figure;
plot(simout(:,1),simout(:,5)-simout1(:,5),'r');hold on;
plot(simout(:,1),simout(:,6)-simout1(:,6),'b');hold on;
plot(simout(:,1),simout(:,7)-simout1(:,7),'k');hold on;
grid;
Xlabel('Time(s)')
Ylabel('Velocity Estimate Error(m)')
AXIS([0 120 -8 8]);

% 
figure;
plot(t_sim,Euler_e(:,1),'r');hold on;
plot(t_sim,Euler_e(:,2),'b');hold on;
plot(t_sim,Euler_e(:,3),'k');hold on;
grid;
Xlabel('Time(s)')
Ylabel('Attitude Angle Error(m)')
AXIS([0 120 -6 6]);


% figure;
% SUBPLOT(3,1,1);plot(simout(:,1),simout(:,5)-simout1(:,5));grid;hold on;
% SUBPLOT(3,1,2);plot(simout(:,1),simout(:,6)-simout1(:,6));grid;hold on;
% SUBPLOT(3,1,3);plot(simout(:,1),simout(:,7)-simout1(:,7));grid;hold on;
% 
% 
% 
% 
% 
% 
% figure;
% SUBPLOT(3,1,1);plot(simout(:,1),simout(:,2)-simout1(:,2));grid;hold on;
% SUBPLOT(3,1,2);plot(simout(:,1),simout(:,3)-simout1(:,3));grid;hold on;
% SUBPLOT(3,1,3);plot(simout(:,1),simout(:,4)-simout1(:,4));grid;hold on;
% figure;
% SUBPLOT(3,1,1);plot(simout(:,1),simout(:,5)-simout1(:,5));grid;hold on;
% SUBPLOT(3,1,2);plot(simout(:,1),simout(:,6)-simout1(:,6));grid;hold on;
% SUBPLOT(3,1,3);plot(simout(:,1),simout(:,7)-simout1(:,7));grid;hold on;
% figure;
% SUBPLOT(3,1,1);plot(simout(:,1),simout(:,8)-simout1(:,8));grid;hold on;
% SUBPLOT(3,1,2);plot(simout(:,1),simout(:,9)-simout1(:,9));grid;hold on;
% SUBPLOT(3,1,3);plot(simout(:,1),simout(:,10)-simout1(:,10));grid;hold on;
% figure;
% SUBPLOT(3,1,1);plot(simout(:,1),simout(:,11)-simout1(:,11));grid;hold on;
% SUBPLOT(3,1,2);plot(simout(:,1),simout(:,12)-simout1(:,12));grid;hold on;
% SUBPLOT(3,1,3);plot(simout(:,1),simout(:,13)-simout1(:,13));grid;hold on;
