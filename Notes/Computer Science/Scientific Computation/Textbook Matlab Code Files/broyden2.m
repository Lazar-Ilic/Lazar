% Program 2.3 Broyden's Method II
% Input: initial vector x0, max steps k
% Output: solution x
% Example usage: broyden2(f,[1;1],10)
function x=broyden2(f,x0,k)
[n,m]=size(x0);
b=eye(n,n); % initial b
for i=1:k
	x=x0-b*f(x0);
	del=x-x0;delta=f(x)-f(x0);
	b=b+(del-b*delta)*del'*b/(del'*b*delta);
	x0=x;
end

%>> f=@(x) [x(2)-x(1)^3;x(1)^2+x(2)^2-1];
%>> x=broyden2(f,[1;1],10)