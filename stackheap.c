main()
{
	char *heap;
	int count=0;
/*	do
	{
		heap=malloc(1024*1024*10);
		//if(heap) memset(heap,0,1024*1024*10);
		count++;
		printf("Allocated %d MB\n",count);
	}
	while(heap);*/
	stack();
}

	int stack()
	{
		static int x;
		char y[1024]={1};
		x++;
		printf("Stack data size %d KB\n",x);
		stack();
	}
