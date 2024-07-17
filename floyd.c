#include<stdio.h>
int w[10][10];
int min(int a,int b){
	return (a<b)?a:b;
}
int main(){
	int i,j,k,n;
	printf("Enter the order of the matrix:\n");
	scanf("%d",&n);
	printf("Enter the entries of the matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&w[i][j]);
	
	for(k=0;k<n;k++)
		for(j=0;j<n;j++)
			for(i=0;i<n;i++)
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<n;j++){
			printf("%d  ",w[i][j]);
		}
	 }
	 return 0;	
}
