main()
{
int a,b,c;

a=2459;
b=5278;
c=bit_add(a,b);
}

int bit_add(int a, int b)
{

int carry, sum;

printf("Adding a=%d b=%d\n",a,b);

if(b==0) return a;
sum=a ^ b;
carry=(a & b)<<1;
return bit_add(sum,carry);
}

