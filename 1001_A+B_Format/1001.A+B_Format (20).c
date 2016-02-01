#include<stdio.h> 
#include<math.h>
int main()
{
	int a,b,c,i,j,r;
	scanf("%d %d",&a,&b);
	c=a+b;
	i=0;
	if(abs(c)<1000) printf("%d",c);
	else if(abs(c)<1000000)
	{
		i=c%1000;
		j=c/1000;
		printf("%d,%03d",j,abs(i));
	}
	else
	{
		i=c%1000;
		c=c/1000;
		j=c%1000;
		r=c/1000;
		printf("%d,%03d,%03d",r,abs(j),abs(i));
	}
	return 0;
}
