main()
{
int x=0x12345678;
char *p=&x;
printf("%x %x\n",*p,x);
}
/*On bigendian machines the output is 78 12345678*/
/*On little endian machines the output is 12 12345678*/
//Guess why ?
