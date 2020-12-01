I x[10000];

B rs(I n)
{
	I b[10][10];
	I count[10];
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

	FOR (I ii = 0; ii < digits; ii=ii+1;)
	{
		FOR (I j = 0; j < 10; j=j+1;)
		{
			count[j] = 0;
		}
		FOR (I jj = 0; jj < n; jj=jj+1;)
		{
			I r = (x[jj] / div);
			I tmp = r/10;
			r = r - tmp*10;
			b[r][count[r]] = x[jj];
			count[r] = count[r] + 1;
		}
		FOR (I jjj = 0; jjj < 10; jjj=jjj+1;)
		{
			FOR (I k = 0; k < count[jjj]; k=k+1;)
			{
				x[i] = b[jjj][k];
				i=i+1;
			}
		}
		div = div*10;
	}
	RET 1;
}
I main() 
{
	I n = 0;	
	B f = scan("%d",n);
	FOR(I i=0;i<n;i=i+1;)
	{
		f = scan("%d",x[i]);
	}
	FOR (I ii= 1; ii < n; ii=ii+1;) 
	{  
		I k = x[ii];  
		I j = ii-1;  
		WHILE (j >= 0 & x[j] > k) 
		{  
			x[j + 1] = x[j];  
			j = j - 1;  
		}  
		x[j+1] = k;  
	}
	FOR (I iii=0;iii<n;iii=iii+1;)
	{
		f = print("%d ",x[iii]);
	}
	f = print("\n");
	RET 0;
}
