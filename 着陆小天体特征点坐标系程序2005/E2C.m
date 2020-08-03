function [r,v]=E2C(a,e,i,omega,w,M,Ux)
%本函数将轨道根数转化为赤道坐标系下的坐标和速度
%输入格式为:
%   a-半长轴长度,e-轨道偏心率,i-轨道倾角,omega-升交点赤经
%   w-近拱点角距,M-平近点角,Ux-星体引力常数

E1=M;
while 1,
    E2=E1-(E1-e*sin(E1)-M)/(1-e*cos(E1));
    if abs(E2-E1)<1e-7,
        break;
    else
        E1=E2;
    end
end
E=E2;
f=2*atan2(sqrt(1+e)*sin(E/2),sqrt(1-e)*cos(E/2));
if f<0,
    f=f+2*pi;
end

nr=a*(1-e^2)/(1+e*cos(f));
u=w+f;
C=cz(w)*cx(i)*cz(omega);
P=C'*[1;0;0];
Q=C'*[0;1;0];
r=nr*(cos(f)*P+sin(f)*Q);
tmp=sqrt(Ux/a/(1-e^2));
v=tmp*(-sin(f)*P+(e+cos(f))*Q);



