#include<stdio.h>
#include<conio.h>
long long int power(int a,int b,int mod)
{
	long long int t;
	if(b==1)
	return a;
	t=power(a,b/2,mod);
	if(b%2==0)
	return (t*t)%mod;
	else 
	return (((t*t)%mod)*a)%mod;
}
long int calculatekey(int a,int x,int n)
{
	return power(a,x,n);
}
int main(){
	int n,g,x,a,y,b;
	printf("enter the value of n and g: \n");
	scanf("%d%d",&n,&g);
	printf("enter the value of x for the first person: ");
	scanf("%d",&x);
	a=power(g,x,n);
	printf("enter the value of y for the second person: ");
	scanf("%d",&y);
	b=power(g,y,n);
	printf("key for the first person is:%lld\n",power(b,x,n));
	printf("key for the second person is:%lld\n",power(a,y,n));
	getch();
}