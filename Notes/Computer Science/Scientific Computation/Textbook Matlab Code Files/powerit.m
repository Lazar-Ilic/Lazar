% Program 12.1 Power Iteration
% Computes dominant eigenvector of square matrix
% Input: matrix A, initial (nonzero) vector x, number of steps k
% Output: dominant eigenvalue lam, eigenvector u
function [lam,u]=powerit(A,x,k)
for j=1:k
	u=x/norm(x); % normalize vector
	x=A*u; % power step
	lam=u'*x; % Rayleigh quotient
end
u=x/norm(x);