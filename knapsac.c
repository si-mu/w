#include<stdio.h>
int knapsack(int v[10][10]);
int v[10][10],value[10],w[10],i,j,m,n;
int max(int a,int b){
	return (a>b)?a:b;
}
int knapsack(int v[10][10]){
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i==0 || j==0){
				v[i][j]=0;
			}else if(j<w[i]){
				v[i][j]=v[i-1][j];
			}else{
				v[i][j]=max(v[i-1][j],value[i]+v[i-1][j-w[i]]);
			}

		}
	}
	printf("The table for the knapsack problem is:\n");
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			printf("%d\t",v[i][j]);
		}
		printf("\n");
	}
	return v[n][m];
}

int main(){
	printf("Enter the no. of items:\n");
	scanf("%d",&n);
	printf("Enter the max capacity of knapsack\n");
	scanf("%d",&m);
	printf("Enter the value of items:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&value[i]);
	printf("Enter the weights of items:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			v[i][j]=0;
	int res = knapsack(v);
	printf("The optimum value for the knapsack problem is: %d",res);
	return 0;	
}

