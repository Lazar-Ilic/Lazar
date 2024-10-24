import sys
from itertools import product as I

yyy="""4.2.3.4...5.5...4
.................
......5...6......
.................
4.4.........6...4
.................
......4...4...4.2
.................
3.4.6...4........
.................
..........4.4.7.3
.................
2...3...2.....4.3"""

zzz="""4.2.3.4...5.5...4
.................
......5...6......
.................
4.4.........6...4
.................
......4...4...4.2
.................
3.4.6...4........
.................
..........4.4.7.3
.................
2...3...2.....4.3"""

xxx=""".................
.................
.................
.................
.................
.................
.................
.................
.................
.................
.................
.................
................."""

a=zzz.split()
V=list
L=len
Z=enumerate
W=range
P=V(I(W(L(a)),W(L(a[0]))))
E={p:[]for p in P}
Q={(i,j):int(a[i][j])for i,j in P if'.'!=a[i][j]}
J=Q.items()
F=[]
for p,c in J:
 for i,j in((0,1),(1,0)):
  q=p[0]+i,p[1]+j;e=[p,0]
  while q in P:
   E[q]+=[e]
   if q in Q:e[1]=q;E[p]+=[e];F+=[e];break
   q=q[0]+i,q[1]+j
E={x:[x for x in y if x[1]!=0]for x,y in E.items()}
C=[E[p] for p in P if p not in Q and L(E[p])>1]
m=[]
T=L(Q)+4*L(F)+L(C)
s=0
l={}
for p,c in J:
 e=E[p];u=L(e)*2
 for t in I(*((0,1,2)for x in e)):
  if sum(t)!=c:continue
  r=[0]*T;r[s+u]=1
  for i,x in Z(t):k=s+i*2;r[k:k+2]=((1,1),(0,1),(0,0))[x]
  m+=[r]
 l[p]=s;s+=u+1
z=L(m)
for e in F:
 p,q=e;r=[0]*T;c,d=l[p]+E[p].index(e)*2,l[q]+E[q].index(e)*2;t=r[:];r[c]=r[d]=1
 for i,u in Z(C):r[T-L(C)+i]=int(e in u)
 t[c+1]=t[d+1]=1;m+=[r,t]

def I(x,d):
 y=d[x]
 while y!=x:yield y;y=d[y]
def A(c):
 L[R[c]],R[L[c]]=L[c],R[c]
 for x in I(c,D):
  for y in I(x,R):U[D[y]],D[U[y]]=U[y],D[y]
def B(c):
 for x in I(c,U):
  for y in I(x,L):U[D[y]],D[U[y]]=y,y
 L[R[c]],R[L[c]]=c,c
def S():
 c=R[h]
 if c==h:yield[]
 A(c)
 for r in I(c,D):
  for x in I(r,R):A(C[x])
  for t in S():yield[r[0]]+t
  for x in I(r,L):B(C[x])
 B(c)
L,R,U,D,C={},{},{},{},{}
h=T
L[h]=R[h]=D[h]=U[h]=h
for c in W(T):
 R[L[h]],R[c],L[h],L[c]=c,h,c,L[h];U[c]=D[c]=c
for i,l in Z(m):
 s=0
 for c in I(h,R):
  if l[c]:
   r=i,c;D[U[c]],D[r],U[c],U[r],C[r]=r,c,r,U[c],c
   if s==0:L[r]=R[r]=s=r
   R[L[s]],R[r],L[s],L[r]=r,s,r,L[s]
for s in S(): 
 b=V(map(V,a))
 for e in s:
  if e<z:continue
  (i,j),(x,y)=F[(e-z)//2]
  if j==y:
   for r in W(i+1,x):b[r][j]='|H'[b[r][j]=='|']
  else:
   for r in W(j+1,y):b[i][r]='-='[b[i][r]=='-']
 print('\n'.join(''.join(l)for l in b).replace('.',' '))