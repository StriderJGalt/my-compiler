I g(I n,I k)
{
	I sum = 0;
	FOR(I i=1;i<=n;i=i+1;)
	{
		I x = 1;
		FOR(I j=0;j<k;j=j+1;)
		{
			x=x*i;
		}
		sum = sum + x;
	}
	RET sum;
}

I main()
{
	I n = 0;
	I k = 0;
	B f = scan("%d %d",n,k);
	f = print("%d\n",g(n,k));
	RET 0;
}
