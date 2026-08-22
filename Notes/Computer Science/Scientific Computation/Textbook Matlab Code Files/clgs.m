% Program 4.1 Classical Gram-Schmidt orthogonalization
% Input: mxn matrix A with linearly independent columns
% Output: orthogonal matrix Q, upper triangular R
% Example usage: [Q,R]=clgs(A)
function [Q,R]=clgs(A)
[m,n]=size(A);
for j=1:n
	y=A(:,j);
	for i=1:j-1
		R(i,j)=Q(:,i)'*A(:,j);
		y=y-R(i,j)*Q(:,i);
	end
	R(j,j)=norm(y);
	Q(:,j)=y/R(j,j);
end