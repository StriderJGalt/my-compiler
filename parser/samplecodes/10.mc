I main()
{
	I x[100][100];
	I y[100][100];
	I z[100][100];
	I n = 0;
	I m = 0;	

	B f = scan("%d %d",m,n);
	FOR (I i=0;i<n;i=i+1;)
	{
		FOR(I j=0;j<n;j=j+1;) 
		{
			f = scan("%d",x[i][j]);
		}
	}
	FOR (I ii=0;ii<n;ii=ii+1;) 
	{
		FOR(I jj=0;jj<n;j=jj+1;) 
		{
			f = scan("%d",y[ii][jj]);
		}
	}

	FOR (I iii=0;iii<n;iii=iii+1;) 
	{
		FOR (I jjj=0;jjj<n;jjj=jjj+1;) 
		{
			z[iii][jjj] = 0; 
			FOR (I k = 0; k < m; k=k+1;) 
			{
                		z[iii][jjj] = z[iii][jjj] + x[iii][k] *  y[k][jjj];
			}
		}
	}

	FOR(I iiii=0;iiii<n;i=iiii+1;) 
	{
		FOR(I jjjj=0;jjjj<n;jjjj=jjjj+1;) 
		{
			f = print("%d ",z[iiii][jjjj]);
		}
	}

	RET 0;
}
