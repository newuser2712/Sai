#include <cstdio>
#include<vector>
#include<cstring>
void addlist(int a[][10][10],int b[][10],int n)
{
	int i,j,l,k,c;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			l=b[i][j];
			for(k=0;k<b[i][j];k++)
			{
				for(c=0;c<b[a[i][j][k]][j];c++)
				{
					a[i][j][l++]=a[k][j][c];
				}
				for(c=0;c<b[i][a[i][j][k]];c++)
				{
					a[i][j][l++]=a[i][k][c];
				}
			}
		}
	}
}
/*void print(int a[][10][10],int b[][10],int i,int j,int n,int para)
{
	int l,m,p,k;
	if(i==j)
	{
		printf("%d ",i);
		return;
	}
	else
	{
		
				for(k=0;k<b[i][j];k++)
				{
					print(a,b,i,a[i][j][k],n,1);
					print(a,b,a[i][j][k],i,n,1);
			
				}
			
		
	return;	
	}
}*/

int main(void) {
	int list[10][10][10],listp[10][10];
	int n,w[10][10],i,j,k;
	long long dist[10][10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	memset(listp[i],0,10*sizeof(int));
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
			dist[i][j]=w[i][j];
		}
		
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(w[i][j]==1)
			{
				list[i][j][0]=j;
				listp[i][j]++;
			}
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
               		list[i][j][0]=k;
               		listp[i][j]=1;
				}
				else if((dist[i][k]+dist[k][j])==dist[i][j])
				{
					list[i][j][listp[i][j]]=k;
               		listp[i][j]++;
				}
			}
		}
	}
	addlist(list,listp,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\npair %d %d\n",i,j);
			for(k=0;k<listp[i][j];k++)
			{
				printf("%d ",list[i][j][k]);
			}
		}
		printf("\n");
	}

	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			print(list,listp,i,j,n,1);
		}
	}*/
	return 0;
}
