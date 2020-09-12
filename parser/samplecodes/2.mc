B prime(I n)
{
	I flag = 1;
	FOR(I i=2;flag & i<n/2;i=i+1;)
	{
		IF((n%i)==0)
		{
			flag=0;
		}
	}
	RET flag;
}

I MAIN() {
	I n;
	scan("%d",n);
	IF(prime(n))
	{
		print("Yes\n");
	}
	ELSE
	{
		print("No\n");
	}
	RET 0;
	
}
