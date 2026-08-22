% Program 12.2 Inverse Power Iteration
% Computes eigenvalue of square matrix nearest to input s
% Input: matrix A, (nonzero) vector x, shift s, steps k
% Output: eigenvalue lam, eigenvector of inv(A-sI)
function [lam,u]=invpowerit(A,x,s,k)
As=A-s*eye(size(A));
for j=1:k
	u=x/norm(x); % normalize vector
	x=As\u; % power step
	lam=u'*x; % Rayleigh Quotient
end
lam=1/lam+s; u=x/norm(x);