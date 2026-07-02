import math
w,h=46,46
m=[[0 for x in range(w)]for y in range(h)]
p=[0.25,0.5,0.75]
m[0][0]=float(1)
for a in range(1,15):
	m[a][0]=p[0]*m[a-1][0]
	m[0][a]=(1-p[0])*m[0][a-1]
	for b in range(1,a):
		m[a][b]=p[0]*m[a-1][b]+(1-p[0])*m[a][b-1]
		m[b][a]=p[0]*m[b-1][a]+(1-p[0])*m[b][a-1]
	m[a][a]=p[0]*m[a-1][a]+(1-p[0])*m[a][a-1]
m[15][0]=p[0]*m[14][0]
m[0][15]=(1-p[0])*m[0][14]
for b in range(1,15):
	m[15][b]=p[0]*m[15-1][b]+(1-p[1])*m[15][b-1]
	m[b][15]=p[1]*m[b-1][15]+(1-p[0])*m[b][15-1]
m[15][15]=p[1]*m[15-1][15]+(1-p[1])*m[15][15-1]
for a in range(16,30):
	m[a][0]=p[1]*m[a-1][0]
	m[0][a]=(1-p[1])*m[0][a-1]
	for b in range(1,a):
		m[a][b]=p[1]*m[a-1][b]+(1-p[1])*m[a][b-1]
		m[b][a]=p[1]*m[b-1][a]+(1-p[1])*m[b][a-1]
	m[a][a]=p[1]*m[a-1][a]+(1-p[1])*m[a][a-1]
m[30][0]=p[1]*m[29][0]
m[0][30]=(1-p[1])*m[0][29]
for b in range(1,30):
	m[30][b]=p[1]*m[30-1][b]+(1-p[2])*m[30][b-1]
	m[b][30]=p[2]*m[b-1][30]+(1-p[1])*m[b][30-1]
m[30][30]=p[2]*m[30-1][30]+(1-p[2])*m[30][30-1]
for a in range(31,45):
	m[a][0]=p[2]*m[a-1][0]
	m[0][a]=(1-p[2])*m[0][a-1]
	for b in range(1,a):
		m[a][b]=p[2]*m[a-1][b]+(1-p[2])*m[a][b-1]
		m[b][a]=p[2]*m[b-1][a]+(1-p[2])*m[b][a-1]
	m[a][a]=p[2]*m[a-1][a]+(1-p[2])*m[a][a-1]
m[45][0]=p[2]*m[44][0]
m[0][45]=(1-p[2])*m[0][44]
for b in range(1,45):
	m[45][b]=p[2]*m[45-1][b]
	m[b][45]=(1-p[2])*m[b][45-1]
answer=float(0)
for a in range(0,45):
	answer+=m[45][a]
print(answer)
for a in range(0,45):
	answer+=m[a][45]
print(answer)