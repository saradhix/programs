#include<stdio.h>
main()
{
	int a=63,b=5,c;
	c=mult(a,b);
	printf("Value of c=%d\n",c);
}

int mult(int a, int b)
{
	int p=0,i=0;

	printf("Entered mult with a=%d b=%d\n",a,b);
	while(b)
	{
		p+=(a<<i)*(b&1);
		printf("p=%d\n",p);
		b=b>>1;
		i++;
	}
	return p;
}
