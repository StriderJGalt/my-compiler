I g(I k,I k)
{
	I sum = 0;
	FOR(I i=1;i<=n;i=i+1;)
	{
		I x = i;
		FOR(I j=0;j<i;j=j+1;)
		{
			x=x*i;
		}
		sum = sum + x;
	}
	RET sum;
}

I MAIN() {
	I n,k;
	scan("%d %d",n,k);
	print("%d\n",g(n,k));
	RET 0;
}
