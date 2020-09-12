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

	FOR (I i=0;i<n;i=i+1;) 
	{
		FOR (I j=0;j<n;j=j+1;) 
		{
			z[i][j] = 0; 
			FOR (I k = 0; k < m; k=k+1;) 
			{
                z[i][j] = z[i][j] + x[i][k] *  y[k][j];
			}
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
