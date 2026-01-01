import copy
import math
avv=[[0,0,0]]
sizes=[math.sqrt(5),math.sqrt(3),math.sqrt(2)]
amap={}
amap[tuple(avv[0])]=[]
z=1
for a in range(39):
	aset=set()
	for dude in avv:
		dudetuple=tuple(dude)
		premap=amap[dudetuple]
		#print(a+1,dudetuple,premap)
		for b in range(3):
			lol=copy.deepcopy(dude)
			lolmapped=copy.deepcopy(premap)
			lol[b]=sizes[b]
			for d in range(3):
				lol[d]=round(lol[d],8)
			lol=tuple(lol)
			if lol not in amap:
				aset.add(lol)
				lolmapped.append("T"+str(b+1))
				amap[lol]=lolmapped
			lol=copy.deepcopy(dude)
			lolmapped=copy.deepcopy(premap)
			lol[b]=0
			for d in range(3):
				lol[d]=round(lol[d],8)
			lol=tuple(lol)
			if lol not in amap:
				aset.add(lol)
				lolmapped.append(str(b+1)+"S")
				amap[lol]=lolmapped
			for c in range(3):
				if c!=b:
					lol=copy.deepcopy(dude)
					lolmapped=copy.deepcopy(premap)
					if lol[b]<=sizes[c]-lol[c]:
						lol[c]+=lol[b]
						lol[b]=0
						if lol[c]>=0.9997 and lol[c]<=1.0003 and z==1:
							print(a+1,lol,lolmapped,b+1,c+1)
							z=0
					else:
						lol[b]-=sizes[c]-lol[c]
						lol[c]=sizes[c]
						if lol[b]>=0.9997 and lol[b]<=1.0003 and z==1:
							print(a+1,lol,lolmapped,b+1,c+1)
							z=0
					for d in range(3):
						lol[d]=round(lol[d],8)
					lol=tuple(lol)
					if lol not in amap:
						aset.add(lol)
						lolmapped.append(str(b+1)+str(c+1))
						amap[lol]=lolmapped
	avv=[]
	for dude in aset:
		avv.append(list(dude))
	print(a+1,len(avv))
# 39 TC CA TC CA AS CA TC CA TC CA AS CB TC CA TC CA AS CA TC CA TC CA AS CA BA AC AS CA TC CA AS CA TC CB TC CA TC CB CA

# ['T3', '31', 'T3', '31', '1S', '31', 'T3', '31', 'T3', '31', '1S', '32', 'T3', '31', 'T3', '31', '1S', '31', 'T3', '31', 'T3', '31', '1S', '31', '21', '13', '1S', '31', 'T3', '31', '1S', '31', 'T3', '32', 'T3', '31', 'T3', '32']

# Generate Intervals And Array And Then UpperBound Each Time To See If Fraction Is Relevant
intervals=[]
for a in range(12):
	for b in range(-11,12):
		for c in range(1,12):
			val1=abs(a*math.sqrt(5)+b*math.sqrt(3)+1.00000001)/c
			val2=abs(a*math.sqrt(5)+b*math.sqrt(3)+0.99999999)/c
			interval=[val1,val2]
			interval.sort()
			intervals.append(interval)
			val1=abs(a*math.sqrt(5)+b*math.sqrt(3)-1.00000001)/c
			val2=abs(a*math.sqrt(5)+b*math.sqrt(3)-0.99999999)/c
			interval=[val1,val2]
			interval.sort()
			intervals.append(interval)
intervals.sort()
#print(intervals)
print(len(intervals))
newintervals=[[-1000,-1000]]
a=0
while a<len(intervals):
	left=intervals[a][0]
	right=intervals[a][1]
	while a+1<len(intervals) and intervals[a+1][0]<right:
		right=max(right,intervals[a+1][1])
		a+=1
	newintervals.append([left,right])
	a+=1
print(len(newintervals))
intervals=newintervals
newintervals=[]
ranger=0
for dude in intervals:
	ranger+=dude[1]-dude[0]
print(ranger)
def upper_bound(target):
	low=0
	high=len(intervals)-1
	while low<=high:
		mid=(low+high)//2
		if intervals[mid]<=target:
			low=mid+1
		else:
			high=mid-1
	return low
print(upper_bound([0,-1000]))
print(upper_bound([0,1000]))
print(intervals[upper_bound([0,-1000])])
print(intervals[upper_bound([0,-1000])-1])
for q in range(1,10000):
	#print(q)
	for p in range(1,int(q*math.sqrt(3))+2):
		if math.gcd(p,q)==1 and p/q<math.sqrt(3) and p/q>=intervals[upper_bound([p/q,-1000])-1][0] and p/q<=intervals[upper_bound([p/q,-1000])-1][1]:
			avv=[[0,0,0]]
			sizes=[math.sqrt(5),math.sqrt(3),p/q]
			amap={}
			amap[tuple(avv[0])]=[]
			z=1
			for a in range(11):
				aset=set()
				for dude in avv:
					dudetuple=tuple(dude)
					premap=amap[dudetuple]
					for b in range(3):
						lol=copy.deepcopy(dude)
						lolmapped=copy.deepcopy(premap)
						lol[b]=sizes[b]
						for d in range(3):
							lol[d]=round(lol[d],13)
						lol=tuple(lol)
						if lol not in amap:
							aset.add(lol)
							lolmapped.append("T"+str(b+1))
							amap[lol]=lolmapped
						lol=copy.deepcopy(dude)
						lolmapped=copy.deepcopy(premap)
						lol[b]=0
						for d in range(3):
							lol[d]=round(lol[d],13)
						lol=tuple(lol)
						if lol not in amap:
							aset.add(lol)
							lolmapped.append(str(b+1)+"S")
							amap[lol]=lolmapped
						for c in range(3):
							if c!=b:
								lol=copy.deepcopy(dude)
								lolmapped=copy.deepcopy(premap)
								if lol[b]<=sizes[c]-lol[c]:
									lol[c]+=lol[b]
									lol[b]=0
									if lol[c]>=0.99999999 and lol[c]<=1.00000001 and z==1 and a+1==11:
										print(p,q,a+1,lol,lolmapped,b+1,c+1)
										z=0
									elif lol[c]>=0.99999999 and lol[c]<=1.00000001 and z==1:
										z=0
								else:
									lol[b]-=sizes[c]-lol[c]
									lol[c]=sizes[c]
									if lol[b]>=0.99999999 and lol[b]<=1.00000001 and z==1 and a+1==11:
										print(p,q,a+1,lol,lolmapped,b+1,c+1)
										z=0
									elif lol[b]>=0.99999999 and lol[b]<=1.00000001 and z==1:
										z=0
								for d in range(3):
									lol[d]=round(lol[d],13)
								lol=tuple(lol)
								if lol not in amap:
									aset.add(lol)
									lolmapped.append(str(b+1)+str(c+1))
									amap[lol]=lolmapped
				avv=[]
				for dude in aset:
					avv.append(list(dude))
# 4224/3187 11 TA AC CS AB TA AC CS AC TA CB AC