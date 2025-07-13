function answer=newtm(f,g,x0,k)
x(1)=x0;
for i=1:k
	x(i+1)=x(i)-f(x(i))/g(x(i));
end
answer=x(k+1);

%>>syms f(x)
%>>f(x)=2*exp(x-1)-x^2-1
%>>g=diff(f)
%>>answer=newtm(f,g,0,10)