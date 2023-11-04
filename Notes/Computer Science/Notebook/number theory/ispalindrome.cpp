L reverse(L al){
	L reverse=0;
	do{
		reverse=al%10+reverse*10;
		al/=10;
	}while(al!=0);
	return reverse;
}

B ispalindrome(L al){
	return al==reverse(al);
}