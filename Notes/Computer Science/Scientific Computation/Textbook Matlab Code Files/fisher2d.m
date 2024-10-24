% Program 8.8 Backward difference method with Newton iteration
% for Fisher's equation with two-dim domain
% input: space region [xl xr]x[yb yt], time interval [tb te],
% M,N space steps in x and y directions, tsteps time steps
% output: solution mesh [x,y,w]
% Example usage: [x,y,w]=fisher2d(0,1,0,1,0,5,20,20,100);
function [x,y,w]=fisher2d(xl,xr,yb,yt,tb,te,M,N,tsteps)
f=@(x,y) 2+cos(pi*x).*cos(pi*y)
delt=(te-tb)/tsteps;
D=1;
m=M+1;n=N+1;mn=m*n;
h=(xr-xl)/M;k=(yt-yb)/N;
x=linspace(xl,xr,m);y=linspace(yb,yt,n);
for i=1:m %Define initial u
	for j=1:n
		w(i,j)=f(x(i),y(j));
	end
end
for tstep=1:tsteps
	v=[reshape(w,mn,1)];
	wold=w;
	for it=1:3
		b=zeros(mn,1);DF1=zeros(mn,mn);DF2=zeros(mn,mn);
		for i=2:m-1
			for j=2:n-1
				DF1(i+(j-1)*m,i-1+(j-1)*m)=-D/h^2;
				DF1(i+(j-1)*m,i+1+(j-1)*m)=-D/h^2;
				DF1(i+(j-1)*m,i+(j-1)*m)= 2*D/h^2+2*D/k^2-1+1/(1*delt);
				DF1(i+(j-1)*m,i+(j-2)*m)=-D/k^2;DF1(i+(j-1)*m,i+j*m)=-D/k^2;
				b(i+(j-1)*m)=-wold(i,j)/(1*delt);
				DF2(i+(j-1)*m,i+(j-1)*m)=2*w(i,j);
			end
		end
		for i=1:m % bottom and top
			j=1; DF1(i+(j-1)*m,i+(j-1)*m)=3;
			DF1(i+(j-1)*m,i+j*m)=-4;DF1(i+(j-1)*m,i+(j+1)*m)=1;
			j=n; DF1(i+(j-1)*m,i+(j-1)*m)=3;
			DF1(i+(j-1)*m,i+(j-2)*m)=-4;DF1(i+(j-1)*m,i+(j-3)*m)=1;
		end
		for j=2:n-1 % left and right
			i=1; DF1(i+(j-1)*m,i+(j-1)*m)=3;
			DF1(i+(j-1)*m,i+1+(j-1)*m)=-4;DF1(i+(j-1)*m,i+2+(j-1)*m)=1;
			i=m; DF1(i+(j-1)*m,i+(j-1)*m)=3;
			DF1(i+(j-1)*m,i-1+(j-1)*m)=-4;DF1(i+(j-1)*m,i-2+(j-1)*m)=1;
		end
		DF=DF1+DF2;
		F=(DF1+DF2/2)*v+b;
		v=v-DF\F;
		w=reshape(v(1:mn),m,n);
	end
	mesh(x,y,w');axis([xl xr yb yt tb te]);
	xlabel('x');ylabel('y');drawnow
end