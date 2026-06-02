%Program 3.1 Newton Divided Difference Interpolation Method
%Computes coefficients of interpolating polynomial
%Input: x and y are vectors containing the x and y coordinates
% of the n data points
%Output: coefficients c of interpolating polynomial in nested form
%Use with nest.m to evaluate interpolating polynomial
function c=newtdd(x,y,n)
for j=1:n
	v(j,1)=y(j); % Fill in y column of Newton triangle
end
for i=2:n % For column i,
	for j=1:n+1-i % fill in column from top to bottom
		v(j,i)=(v(j+1,i-1)-v(j,i-1))/(x(j+i-1)-x(j));
	end
end
for i=1:n
	c(i)=v(1,i); % Read along top of triangle
end % for output coefficients

%x0=[0 2 3];
%y0=[1 2 4];
%c=newtdd(x0,y0,3);
%x=0:.01:4;
%y=nest(2,c,x,x0);
%plot(x0,y0,'o',x,y)
%will result in the plot of the polynomial shown in Figure 3.1