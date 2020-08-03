
%客户端向服务端传数子程序
function y=landconver(u)
format long
global onesocket
%LANDING SUBSYSTEM
time= 2.453211500000000e+006;
TIME=time+u(24)/3600/24;

javaMethod('setsubsys',onesocket,'LANDING');             %设定子系统的名字

% LANDSTATE  时间序列（儒略日）          
% (TO AUTO)  探测器位置R
%            探测器速度V
javaMethod('setdatatype',onesocket,'LANDSTATE');                 %LANDSTATE
javaMethod('adddoubledata4',onesocket,TIME,u(1),u(2),u(3));
javaMethod('adddoubledata3',onesocket,u(4),u(5),u(6));
javaMethod('senddata',onesocket);
% LANDATT    时间序列（儒略日）
% (TO AUTO)  探测器角速度w
%            姿态四元素q 
javaMethod('setdatatype',onesocket,'LANDATT');                   %LANDATT
javaMethod('adddoubledata4',onesocket,TIME,u(7),u(8),u(9));
javaMethod('adddoubledata4',onesocket,u(10),u(11),u(12),u(13));
javaMethod('senddata',onesocket);
% LANDSTATUS 时间序列（儒略日）
% (TO AUTO)  飞轮控制力矩WHU
%            飞轮转速Ww
%            轨控喷气时间序列F
javaMethod('setdatatype',onesocket,'LANDSTATUS');                %LANDSTATUS
javaMethod('adddoubledata4',onesocket,TIME,u(14),u(15),u(16)); 
javaMethod('adddoubledata3',onesocket,u(17),u(18),u(19)); 
javaMethod('adddoubledata4',onesocket,u(20),u(21),u(22),u(24));
javaMethod('senddata',onesocket);

y=u;





