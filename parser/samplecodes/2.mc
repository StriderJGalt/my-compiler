B prime(I n)
{
	B flag = 1;
	FOR(I i=2;flag & i<n/2;i=i+1;)
	{
		IF((n%i)==0)
		{
			flag=0;
		}
	}
	RET flag;
}

I main() {
	I n = 0;
	B f = scan("%d",n);
	IF(prime(n))
	{
		f = print("Yes\n");
	}
	ELSE
	{
		f = print("No\n");
	}
	RET 0;
	
}
