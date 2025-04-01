% Program 11.1 Audio codec
% input: column vector x of input signal
% output: column vector out of output signal
% Example usage: out=simplecodec((cos((1:2^(13))*2*pi*440/2^(13)))');
% example signal is 1 sec. pure tone of frequency f=440Hz
function out=simplecodec(x)
len=numel(x); % length of signal
n=2^5; % length of processing window
nw=floor(len/n); % number of length n windows in x
x=x(1:n*nw); % cut x to integer number of n windows
Fs=2^(13); % Fs = sampling rate
b=4; L=1; % b = quantiz. bits, [-L,L] amplitude range
q=2*L/(2^b-1); % q used for b bits on interval [-L, L]
for i=1:n % form the MDCT matrix
	for j=1:2*n
		M(i,j)= cos((i-1+1/2)*(j-1+1/2+n/2)*pi/n);
	end
end
M=sqrt(2/n)*M;
N=M'; % inverse MDCT
sound(0.3*x/max(abs(x)),Fs) % play the input signal (scale to max = 0.3)
out=[];
for k=1:nw-1 % loop over length 2n windows
	x0=x(1+(k-1)*n:2*n+(k-1)*n); % column vector of signal in current window
	y0=M*x0; % apply MDCT
	y1=round(y0/q); % quantize transform components
% Storage/transmission of file occurs here
	y2=y1*q; % dequantize transform components
	w(:,k)=N*y2; % invert the MDCT
	if(k>1)
		w2=w(n+1:2*n,k-1);w3=w(1:n,k);
		out=[out;(w2+w3)/2]; % collect the reconstructed signal
	end % (out has length 2n less than length of x)
end
pause(2)
sound(0.3*out/max(abs(out)),Fs)% play the reconstructed signal