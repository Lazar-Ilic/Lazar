function answer=newtmm(f,g,x0,k,m)
x(1)=x0;
for i=1:k
	x(i+1)=x(i)-m*f(x(i))/g(x(i));
end
answer=x(k+1);

%>>syms f(x)
%>>f(x)=2*exp(x-1)-x^2-1
%>>g=diff(f)
%>>answer=newtmm(f,g,0,10,3)