%Program 0.1 Nested multiplication
%Evaluates polynomial from nested form using Horner's Method
%Input: degree d of polynomial,
% array of d+1 coefficients c (constant term first),
% x-coordinate x at which to evaluate, and
% array of d base points b, if needed
%Output: value y of polynomial at x
function y=nest(d,c,x,b)
if nargin<4, b=zeros(d,1); end
y=c(d+1);
for i=d:-1:1
	y = y.*(x-b(i))+c(i);
end

%>> nest(4,[-1 5 -3 3 2],1/2,[0 0 0 0])
%ans = 1.2500