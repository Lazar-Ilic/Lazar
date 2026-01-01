% Program 8.3 Backward difference method for heat equation
% with Neumann boundary conditions
% input: space interval [xl,xr], time interval [yb,yt],
% number of space steps M, number of time steps N
% output: solution w
% Example usage: w=heatbdn(0,1,0,1,20,20)
function w=heatbdn(xl,xr,yb,yt,M,N)
f=@(x) sin(2*pi*x).^2;
D=1; % diffusion coefficient
h=(xr-xl)/M; k=(yt-yb)/N; m=M+1; n=N;
sigma=D*k/(h*h);
a=diag(1+2*sigma*ones(m,1))+diag(-sigma*ones(m-1,1),1);
a=a+diag(-sigma*ones(m-1,1),-1); % define matrix a
a(1,:)=[-3 4 -1 zeros(1,m-3)]; % Neumann conditions
a(m,:)=[zeros(1,m-3) -1 4 -3];
w(:,1)=f(xl+(0:M)*h)'; % initial conditions
for j=1:n
	b=w(:,j);b(1)=0;b(m)=0;
	w(:,j+1)=a\b;
end
x=(0:M)*h;t=(0:n)*k;
mesh(x,t,w') % 3-D plot of solution w
view(60,30);axis([xl xr yb yt -1 1])