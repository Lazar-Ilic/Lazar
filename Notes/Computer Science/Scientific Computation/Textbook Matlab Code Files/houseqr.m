% Program 4.2 Orthogonalization by Householder reflectors
% Input: mxn matrix A with linearly independent columns
% Output: orthogonal matrix Q, upper triangular R
% Example usage: [Q,R]=houseqr(A)
function [Q,R]=houseqr(A)
[m,n]=size(A);
Q=eye(m,m);
for i=1:min(n,m-1)
	x=A(i:m,i);
	w=[-sign(x(1))*norm(x);zeros(m-i,1)];
	v=w-x;
	H=eye(m,m);
	H(i:m,i:m)=eye(m-i+1,m-i+1)-2*v*v'/(v'*v);
	Q=Q*H;
	A=H*A;
end
R=A;