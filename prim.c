#include<stdio.h>
void prims(int cost[10][10],int n)
k
{
	int i,j,min,source,u,v;
	int sum,k,t[10][2],p[10],s[10],d[10];
	min=999;
	source=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(cost[i][j]!=0&&cost[i][j]<min)
			{
				min=cost[i][j];
				source=i;
			}
	for(i=1;i<=n;i++)
	{
		d[i]=cost[source][i];
		p[i]=source;
		s[i]=0;
	}
	s[source]=1;
	sum=0;
	k=0;
	for(i=2;i<=n;i++)
	{
		min=999;
		for(j=1;j<=n;j++)
		{
			if(s[j]==0)
				if(d[j]<=min)
				{
					min=d[j];
					u=j;
				}
		}
		t[k][0]=u;
		t[k][1]=p[u];
		k++;
		sum+=cost[u][p[u]];
		s[u]=1;
		for(v=1;v<=n;v++)
		{
			if(s[v]==0&&cost[u][v]<d[v])
			{
				d[v]=cost[u][v];
				p[v]=u;
			}
		}
	}
	if(sum>=999)
		printf("Not possible");
	else
	{
		printf("Minimum cost spanning tree\n");
		for(i=0;i<n-1;i++)
			printf("%d-%d",t[i][0],t[i][1]);
		printf("cost=%d",sum);
	}
}
	void main()
	{
		int n,cost[10][10],i,j;
		printf("Enter the no of nodes: ");
		scanf("%d",&n);
		printf("Enter the cost matrix: ");
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&cost[i][j]);
		prims(cost,n);
	}




