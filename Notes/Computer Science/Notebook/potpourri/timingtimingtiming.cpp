struct timeval start1,end1,start2,end2;
gettimeofday(&start1,NULL);

	cvl=convolutionp(avl,bvl);

gettimeofday(&end1,NULL);
cout<<setprecision(6)<<((end1.tv_sec-start1.tv_sec)*1e6+(end1.tv_usec-start1.tv_usec))*1e-6<<endl;