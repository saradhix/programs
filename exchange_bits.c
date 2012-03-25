main()
{

int x=10;

x=exchange_bits(x);
printf("Value of x=%d\n",x);
}


int exchange_bits(int x)
{
return ((x & 0xAAAAAAAA)>>1)|((x & 0x55555555)<<1);
}
