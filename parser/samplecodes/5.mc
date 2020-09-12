I MAIN() {
	I n;
	scan("%d",n);
	IF(n>20)
	{
		print("n must be less than 20");
		RET 1;
	}
	I pow=2;
	FOR(I i=1;i<n;i=i+1;)
	{
		pow = pow*2;
	}
	FOR(I i=1;i<pow;i=i+1;)
	{
		print("{");
		I x = i;
		FOR(I j=0;x>0 & j<n;j=j+1;)
		{
			IF(x%2)
			{
				print("%d",arr[j]);
				x = x/2;
				IF(x)
				{
					print(", ");
				}
			}
			ELSE
			{
				x = x/2;
			}
		}
		print("}\n");
	}
	RET 0;
}
