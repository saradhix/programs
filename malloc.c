main()
{
	char *ptr;
	int i=0;
	while(1)
	{
		ptr=malloc(1024*1024*10);
		memset(ptr,0,1024*1024*10);
		printf("i=%d\n",i++);
	}
}
