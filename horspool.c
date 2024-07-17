#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
int t[MAX],i,k,m,n;
void shifttable(char p[]){
	for (i = 0; i < MAX; i++)
        	t[i] = m;
	for(i=0;i<m-1;i++)
		t[p[i]]=m-i-1;
}
int horspool(char src[],char p[]){
	i=m-1;
	while(i<n){
		k=0;
		while(k<m && p[m-k-1]== src[i-k])
			k++;
		if(k==m)
			return i+1-m;
		else
			i+=t[src[i]];
	}
	return -1;
}
int main(){
	char src[50],p[50];
	printf("Enter the text:\n");
	scanf("%s",src);
	printf("Enter the pattern to search for:\n");
	scanf("%s",p);
	n = strlen(src);
	m = strlen(p);
	shifttable(p);
	int pos = horspool(src,p);
	if(pos==-1)
		printf("The pattern does not exist in the text\n");
	else
		printf("The pattern exists in the text from the index : %d\n",pos);
	return 0;
}

