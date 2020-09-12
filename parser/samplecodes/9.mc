I MAIN()
{
	I x[100][100];
	I y[100][100];
	I z[100][100];
	I n,m;	

	scan("%d %d",m,n);
	FOR (I i=0;i<n;i=i+1;)
	{
		FOR(I j=0;j<n;j=j+1;) 
		{
			scan("%d",x[i][j]);
		}
	}
	FOR (I i=0;i<n;i=i+1;) 
	{
		FOR(I j=0;j<n;j=j+1;) 
		{
			scan("%d",y[i][j]);
		}
	}

	FOR(I i=0;i<n;i=i+1;) 
	{
		FOR(I j=0;j<n;j=j+1;)
		{
			z[i][j] = x[i][j] +  y[i][j];
		}
	}

	FOR(I i=0;i<n;i=i+1;) 
	{
		FOR(I j=0;j<n;j=j+1;) 
		{
			print("%d ",z[i][j]);
		}
	}
	
	RET 0;
}
