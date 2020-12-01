I x[100000];
I larr[100000];
I rarr[100000];

B merge(I l,I r)
{
	I i = 0;
	I j = 0;
	I k = 0;


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

I ms(I n) 
{
	I mid = 0;
	IF(n < 2)
	{
		RET 0;  
	}

	mid = n/2;  
	
	FOR(I i = 0;i<mid;i=i+1;)
	{
		larr[i] = x[i];
	}
	FOR(I ii = mid;ii<n;ii=ii+1;){
		rarr[ii-mid] = x[ii];
	}

	B f = ms(larr,mid);  
	f = ms(rarr,n-mid);
	f = merge(larr,mid,rarr,n-mid);
	RET 0;
}
I main() {
	I n = 0;	
	B f = scan("%d",n);
	FOR (I i=0;i<n;i=i+1;) 
	{
		f = scan("%d",x[i]);
	}

	f = ms(n);

	FOR (I ii=0;ii<n;ii=ii+1;)
	{
		f = print("%d ",x[ii]);
	}

	RET 0;
}
