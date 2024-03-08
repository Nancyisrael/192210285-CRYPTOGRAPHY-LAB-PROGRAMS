#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
void encipher();
void decipher();
void exit();
int main()
{
	int choice;
	while(1)
	{
	printf("\n1. Encrypt text");
	printf("\t2. Decrypted text");
	printf("t3. Exit");
	printf("\n Enetr your choice");
	scanf("%d",&choice);
	if(choice==3)
	exit();
	else if(choice==1)
	encipher();
	else if(choice==2)
	decipher();
	else
	printf("please enter the valid option.");
}
}
void encipher()
{
	unsigned int i,j;
	char input[50],key[10];
	printf("enter the plane text");
	scanf("%s",input);
	printf("enter the key");
	scanf("%s",key);
	for(i=0,j=0;i<strlen(input);i++,j++)
	{
		if(j>=strlen(key))
		j=0;
		printf("%c",65+(((toupper(input[i]-64))+toupper(key[j]-65))%26));
	}
}
void decipher()
{
	unsigned int i,j;
	char input[50],key[10];
	int value;
	printf("Enter the cipher text:");
	scanf("%s",input);
	printf("Enetr the key value:");
	scanf("%s",key);
	for(i=0,j=0;i<strlen(input);i++,j++)
	{
		if(j>=strlen(key))
		j=0;
		value=(toupper(input[i]-64))+(toupper(key[j])-64);
		if(value<0)
		value=value*-1;
		printf("%c",65+(value%26));
	}
}
