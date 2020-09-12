I x[100000];
I larr[100000];
I rarr[100000];

B merge(I larr[],I l,I rarr[],I r)
{
	I i,j,k;
	i = 0; j = 0; k =0;

	WHILE (i<l & j< r)
	{
		IF(larr[i]  < rarr[j])
		{
			x[k] = larr[i];
			k=k+1;
			i=i+1;
		}
		ELSE
		{
			x[k] = rarr[j];
			k=k+1;
			j=j+1;
		}
	}
	WHILE (j < r) 
	{
		x[k] = rarr[j];
		k=k+1;
		j=j+1;
	}
	WHILE (i < l)
	{
		x[k] = larr[i];
		k=k+1;
		i=i+1;
	}
	RET 1;
}

I msort(I n) 
{
	I mid;
	IF(n < 2)
	{
		RET 0;  
	}

	mid = n/2;  
	
	FOR(I i = 0;i<mid;i=i+1;)
	{
		larr[i] = x[i];
	}
	FOR(I i = mid;i<n;i=i+1;){
		rarr[i-mid] = x[i];
	}

	ms(larr,mid);  
	ms(rarr,n-mid);
	merge(larr,mid,rarr,n-mid);
	RET 0;
}
I MAIN() {
	I n;	
	scan("%d",n);
	FOR (I i=0;i<n;i=i+1;) 
	{
		scan("%d",x[i]);
	}

	ms(n);

	FOR (I i=0;i<n;i=i+1;)
	{
		print("%d ",x[i]);
	}

	RET 0;
}
