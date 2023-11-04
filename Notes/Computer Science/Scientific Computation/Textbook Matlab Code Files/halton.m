% Program 9.1 Quasi-random number generator
% Halton sequence in base p
% Input: prime number p, random numbers required n
% Output: array u of quasi-random numbers in [0,1]
% Example usage: halton(2,100)
function u=halton(p,n)
b=zeros(ceil(log(n+1)/log(p)),1); % largest number of digits
for j=1:n
	i=1;
	b(1)=b(1)+1; % add one to current integer
	while b(i)>p-1+eps % this loop does carrying
		b(i)=0; % in base p
		i=i+1;
		b(i)=b(i)+1;
	end
	u(j)=0;
	for k=1:length(b(:)) % add up reversed digits
		u(j)=u(j)+b(k)*p^(-k);
	end
end