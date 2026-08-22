% Program 10.2 Least squares trigonometric fit
% Least squares fit of n data points on [0,1] with trig function
% where 2 <=m <=n. Plot best fit at p (>=n) points.
% Input: interval [c,d], data points x, even number m,
% even number of data points n, even number p>=n
% Output: filtered points xp
function xp=dftfilter(inter,x,m,n,p)
c=inter(1); d=inter(2);
t=c+(d-c)*(0:n-1)/n; % time points for data (n)
tp=c+(d-c)*(0:p-1)/p % time points for interpolant (p)
y=fft(x); % compute interpolation coefficients
yp=zeros(p,1); % will hold coefficients for ifft
yp(1:m/2)=y(1:m/2); % keep only first m frequencies
yp(m/2+1)=real(y(m/2+1)); % since m is even, keep cos term only
if(m<n) % unless at the maximum frequency,
	yp(p-m/2+1)=yp(m/2+1); % add complex conjugate to
end % corresponding place in upper tier
yp(p-m/2+2:p)=y(n-m/2+2:n); % more conjugates for upper tier
xp=real(ifft(yp))*(p/n); % invert fft to recover data
plot(t,x,'o',tp,xp) % plot data and least square approx