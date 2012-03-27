int *fun2();
main()
{
fun1();
}

int fun1()
{
int y;
int *x;
printf("Address of y is %x\n",&y);
x=fun2();
if(x > &y) printf("Call stack growing up\n");
else printf("Call stack growing down\n");
}

int *fun2()
{
int z;
//static int x=100;
char *heap,*heap1;
printf("Address of z=%x\n",&z);
heap=malloc(1024);
printf("Address of heap=%x\n",heap);
heap1=malloc(1024);
printf("Address of heap1=%x\n",heap1);
//while(x--) return fun2();
return &z;
}


