I main() {
	I n = 0;
	B f = scan("%d",n);
	IF(n>20)
	{
		f = print("n must be less than 20");
		RET 1;
	}
	I pow=2;
	FOR(I i=1;i<n;i=i+1;)
	{
		pow = pow*2;
	}
	FOR(I j=1;j<pow;j=j+1;)
	{
		f = print("{");
		I x = j;
		FOR(I k=0;x>0 & k<n;k=k+1;)
		{
			IF(x%2)
			{
				f = print("%d",k);
				x = x/2;
				IF(x)
				{
					f = print(", ");
				}
			}
			ELSE
			{
				x = x/2;
			}
		}
		f = print("}\n");
	}
	RET 0;
}
