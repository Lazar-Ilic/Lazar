%Program 1.2 Fixed-Point Iteration
%Computes approximate solution of g(x)=x
%Input: function handle g, starting guess x0,
% number of iteration steps k
%Output: Approximate solution xc
function xc=fpi(g, x0, k)
x(1)=x0;
for i=1:k
	x(i+1)=g(x(i));
end
xc=x(k+1);

%>> g=@(x) cos(x)
%>> xc=fpi(g,0,10)
%to run 10 steps of Fixed-Point Iteration with initial guess 0