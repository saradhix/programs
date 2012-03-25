main()
{
int x[]={20,31,127,0};
int i;
for(i=0;i<4;i++)
printf("Bits in %d=%d\n",x[i],count_bits(x[i]));

printf("Number of perms from 14 to 31=%d\n",count_bits(14^31));
}

int count_bits(int x)
{
int count=0;
while(x)
{
count+=x%2;
x/=2;
}
return count;
}

int count_bits1(int x)
{
int count=0;
while(x)
{
count+=x & 1;
x=x>>1;
}
return count;
}

int count_bits2(int x)
{
return x?count_bits2(x/2)+x%2:0;
}
/*
int count_bits3(int x)
{
for(i=0;i<4;i++)
{
chunk=x & FF;*/
