I MAIN() {
	I lim = 100000000;
	I count = 0;
	I m=2;
	WHILE(m<10000)
	{
		I n=m;
		WHILE(m*m+n*n>=lim)
		{
			n=n-1;
		}
		count = count + n;
		m = m+1;
	}
	print("%d",count);
	RET 0;
}
