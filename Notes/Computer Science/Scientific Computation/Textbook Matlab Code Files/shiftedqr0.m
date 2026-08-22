% Program 12.6 Shifted QR Algorithm, preliminary version
% Computes eigenvalues of matrices without equal size eigenvalues
% Input: matrix a
% Output: eigenvalues lam
function lam=shiftedqr0(a)
tol=1e-14;
m=size(a,1);lam=zeros(m,1);
n=m;
while n>1
	while max(abs(a(n,1:n-1)))>tol
		mu=a(n,n); % define shift mu
		[q,r]=qr(a-mu*eye(n));
		a=r*q+mu*eye(n);
	end
	lam(n)=a(n,n); % declare eigenvalue
	n=n-1; % decrement n
	a=a(1:n,1:n); % deflate
end
lam(1)=a(1,1); % 1x1 matrix remains