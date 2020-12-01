I main()
{
	I n = 0;
	B f = scan("%d",n);
	I sum = 0;
	B prime[1000];
	FOR(I i=0; i<n; i=i+1;)
	{
		prime[i] = 1;
	}
	FOR (I j=2; j*j <= n; j=j+1;) 
	{ 
		IF (prime[j]) 
		{ 
			FOR(I k=j+j; k<=n; k=k+j;)
			{
				prime[k] = 0; 
			}
		} 
	}
	FOR(I l=2; l<n; l=l+1;)
	{
		IF(prime[l])
		{
			sum = sum + l;
		}	
	}
	f = print("%d\n",sum);
	RET 0;
}
