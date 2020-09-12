I MAIN()
{
	I n;
	scan("%d",n);
	I sum = 0;
	B prime[1000];
	FOR(I i=0; i<n; i=i+1;)
	{
		prime[i] = 1;
	}
	FOR (I i=2; i*i <= n; i=i+1;) 
	{ 
		IF (prime[i]) 
		{ 
			FOR(I j=i+i; j<=n; j=j+i;)
			{
				prime[j] = 0; 
			}
		} 
	}
	FOR(I i=2; i<n; i=i+1;)
	{
		IF(prime[i])
		{
			sum = sum + i;
		}	
	}
	print("%d\n",sum);
	RET 0;
}
