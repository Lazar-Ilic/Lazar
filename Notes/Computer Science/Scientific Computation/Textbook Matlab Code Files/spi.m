% Program 13.2 Successive Parabolic Interpolation
% Input: inline function f, initial guesses r,s,t, steps k
% Output: approximate minimum x
function x=spi(f,r,s,t,k)
x(1)=r;x(2)=s;x(3)=t;
fr=f(r);fs=f(s);ft=f(t);
for i=4:k+3
	x(i)=(r+s)/2-(fs-fr)*(t-r)*(t-s)/(2*((s-r)*(ft-fs)...
		-(fs-fr)*(t-s)));
	t=s;s=r;r=x(i);
	ft=fs;fs=fr;fr=f(r); % single function evaluation
end