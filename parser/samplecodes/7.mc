I x[10000];

B rs(I x[], I n)
{
	I b[10][10],count[10];
	I digits = 0;
	I div = 1;
	I max = x[0];

	FOR (I i = 1; i < n; i=i+1;)
	{
		IF (x[i] > max)
		{
			max = x[i];
		}
	}
		
	WHILE (max > 0)
	{
		digits=digits+1;
		max = max/10;
	}

	FOR (I i = 0; i < digits; i=i+1;)
	{
		FOR (I j = 0; j < 10; j=j+1;)
		{
			count[j] = 0;
		}
		FOR (I j = 0; j < n; j=j+1;)
		{
			I r = (x[j] / div);
			I tmp = r/10;
			r = r - tmp*10;
			b[r][count[r]] = x[j];
			count[r] = count[r] + 1;
		}
		FOR (I k = 0; k < 10; k=k+1;)
		{
			FOR (I j = 0; j < count[k]; j=j+1;)
			{
				x[i] = b[k][j];
				i=i+1;
			}
		}
		div = div*10;
	}
	RET 1;
}
I MAIN() 
{
	I n;	
	scan("%d",n);
	FOR(I i=0;i<n;i=i+1;)
	{
		scan("%d",x[i]);
	}
	FOR (I i= 1; i < n; i=i+1;) 
	{  
		I k = x[i];  
		I j = i-1;  
		WHILE (j >= 0 & x[j] > k) 
		{  
			arr[j + 1] = x[j];  
			j = j - 1;  
		}  
		x[j+1] = k;  
	}
	FOR (I i=0;i<n;i=i+1;)
	{
		print("%d ",x[i]);
	}
	print("\n");
	RET 0;
}
