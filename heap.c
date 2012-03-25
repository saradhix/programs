main()
{
	int array[]={20,30,4,3,5,1,17,45};
	int howmany=sizeof(array)/sizeof(array[0]);
	print_array(array,howmany);
	create_heap(array,howmany);
	print_array(array,howmany);
}



int create_heap(int *arr,int howmany)
{
	int i;
	for(i=0;i<howmany;i++)
	{
		if(arr[i] < arr[left(i)])
			swap(arr[i],arr[left(i)]);
		create_heap(arr+left(i),howmany);
	}
}

int swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int left(int index)
{
	return 2*index+1;
}

int right(int index)
{
	return 2*index+2;
}

int print_array(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("a[%d]=%d\t",i,a[i]);
	printf("Done\n");
}
