% Program 13.1 Golden Section Search for minimum of f(x)
% Start with unimodal f(x) and minimum in [a,b]
% Input: function f, interval [a,b], number of steps k
% Output: approximate minimum y
function y=gss(f,a,b,k)
g=(sqrt(5)-1)/2;
x1 = a+(1-g)*(b-a);
x2 = a+g*(b-a);
f1=f(x1);f2=f(x2);
for i=1:k
	if f1 < f2 % if f(x1) < f(x2), replace b with x2
		b=x2; x2=x1; x1=a+(1-g)*(b-a);
		f2=f1; f1=f(x1); % single function evaluation
	else % otherwise, replace a with x1
		a=x1; x1=x2; x2=a+g*(b-a);
		f1=f2; f2=f(x2); % single function evaluation
	end
end
y=(a+b)/2;