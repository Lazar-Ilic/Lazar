%Program 5.2 Adaptive Quadrature
% Computes approximation to definite integral
% Inputs: Matlab function f, interval [a0,b0],
% error tolerance tol0
% Output: approximate definite integral
function int=adapquad(f,a0,b0,tol0)
int=0; n=1; a(1)=a0; b(1)=b0; tol(1)=tol0; app(1)=trap(f,a,b);
while n>0 % n is current position at end of the list
	c=(a(n)+b(n))/2; oldapp=app(n);
	app(n)=trap(f,a(n),c);app(n+1)=trap(f,c,b(n));
	if abs(oldapp-(app(n)+app(n+1)))<3*tol(n)
		int=int+app(n)+app(n+1); % success
		n=n-1; % done with interval
	else % divide into two intervals
		b(n+1)=b(n); b(n)=c; % set up new intervals
		a(n+1)=c;
	tol(n)=tol(n)/2; tol(n+1)=tol(n);
	n=n+1; % go to end of list, repeat
	end
end
function s=trap(f,a,b)
s=(f(a)+f(b))*(b-a)/2;