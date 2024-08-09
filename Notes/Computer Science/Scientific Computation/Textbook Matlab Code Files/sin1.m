%Program 3.3 Building a sin calculator key, attempt #1
%Approximates sin curve with degree 3 polynomial
% (Caution: do not use to build bridges,
% at least until we have discussed accuracy.)
%Input: x
%Output: approximation for sin(x)
function y=sin1(x)
%First calculate the interpolating polynomial and
% store coefficients
b=pi*(0:3)/6;yb=sin(b); % b holds base points
c=newtdd(b,yb,4);
%For each input x, move x to the fundamental domain and evaluate
% the interpolating polynomial
s=1; % Correct the sign of sin
x1=mod(x,2*pi);
if x1>pi
	x1 = 2*pi-x1;
	s = -1;
end
if x1 > pi/2
	x1 = pi-x1;
end
y=s*nest(3,c,x1,b);