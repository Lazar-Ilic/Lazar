%Program 5.1 Romberg integration
% Computes approximation to definite integral
% Inputs: Matlab function specifying integrand f,
% a,b integration interval, n=number of rows
% Output: Romberg tableau r
function r=romberg(f,a,b,n)
h=(b-a)./(2.^(0:n-1));
r(1,1)=(b-a)*(f(a)+f(b))/2;
for j=2:n
	subtotal = 0;
	for i=1:2^(j-2)
		subtotal = subtotal + f(a+(2*i-1)*h(j));
	end
	r(j,1) = r(j-1,1)/2+h(j)*subtotal;
	for k=2:j
		r(j,k)=(4^(k-1)*r(j,k-1)-r(j-1,k-1))/(4^(k-1)-1);
	end
end

%>> romberg(@log,1,2,4)
%ans =
%0.34657359027997 0 0 0
%0.37601934919407 0.38583460216543 0 0
%0.38369950940944 0.38625956281457 0.38628789352451 0
%0.38564390995210 0.38629204346631 0.38629420884310 0.38629430908625