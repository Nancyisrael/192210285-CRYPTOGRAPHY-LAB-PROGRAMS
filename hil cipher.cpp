#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int mod(int a,int m){
	int result=a%m;
	if(result<0)
	result+=m;
	return result;
}
void hillcipherencrypt(int keymatrix[3][3],char*input,int len){
	int encrypted[len];
	int i,j,k;
	printf("plaintext:%s\n",input);
	for( i=0;i<len;i+=3){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
			encrypted[i+j]+=keymatrix[j][k]*(input[i+k]-'A');
		}
		encrypted[i+j]=mod(encrypted[i+j],26);
	}
	}
printf("ciphertext: ");
for(i=0;i<len;i++){
	printf("%c",encrypted[i]+'A');
}
printf("\n");
}
int main()
{
	int i,j;
	int keymatrix[3][3];
	char input[100];
	int len;
	printf("enetr the 3x3 matrix:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&keymatrix[i][j]);
		}
	}
	printf("enetr the plain text:");
	scanf("%s",input);
	len=strlen(input);
	while(len%3!=0){
	input[len]='X';
	len++;
	}
	hillcipherencrypt(keymatrix,input,len);
	return 0;
}
