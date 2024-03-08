#include<stdio.h>
#include<math.h>
int main()
{
	int p,q,m,n,dn,e,c,de,x,y,i;
	printf("enter the value of p: ");
	scanf("%d",&p);
	printf("enter the value of q: ");
	scanf("%d",&q);
	printf("enter the value of m: ");
	scanf("%d",&m);
	printf("enter the value of e: ");
	scanf("%d",&e);
	n=p*q;
	dn=(p-1)*(q-1);
	int d;
	for(i=1;i<dn;i++)
	{
		if(((e%dn)*(i%dn))%dn==1)
		{
			d=i;
			break;
		}
	}
	x=power(m,e);
	c=x%n;
	y=power(c,d);
	de=y%n;
	printf("encrypted text: %d",c);
	printf("decrypted text: %d",m);
}
