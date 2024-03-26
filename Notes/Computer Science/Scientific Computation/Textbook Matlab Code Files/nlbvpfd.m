% Program 7.1 Nonlinear Finite Difference Method for BVP
% Uses Multivariate Newton's Method to solve nonlinear equation
% Inputs: interval inter, boundary values bv, number of steps n
% Output: solution w
% Example usage: w=nlbvpfd([0 1],[1 4],40)
function w=nlbvpfd(inter,bv,n);
a=inter(1); b=inter(2); ya=bv(1); yb=bv(2);
h=(b-a)/(n+1); % h is step size
w=zeros(n,1); % initialize solution array w
for i=1:20 % loop of Newton step
	w=w-jac(w,inter,bv,n)\f(w,inter,bv,n);
end
plot([a a+(1:n)*h b],[ya w' yb]); % plot w with boundary data

function y=f(w,inter,bv,n)
y=zeros(n,1);h=(inter(2)-inter(1))/(n+1);
y(1)=bv(1)-(2+h^2)*w(1)+h^2*w(1)^2+w(2);
y(n)=w(n-1)-(2+h^2)*w(n)+h^2*w(n)^2+bv(2);
for i=2:n-1
	y(i)=w(i-1)-(2+h^2)*w(i)+h^2*w(i)^2+w(i+1);
end

function a=jac(w,inter,bv,n)
a=zeros(n,n);h=(inter(2)-inter(1))/(n+1);
for i=1:n
	a(i,i)=2*h^2*w(i)-2-h^2;
end
for i=1:n-1
	a(i,i+1)=1;
	a(i+1,i)=1;
end