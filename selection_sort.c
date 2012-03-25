main()
{
		//int arr[8]={10,15,3,25,8,2,19,30};
		int arr[5]={10,15,3,25,8};

		selection_sort(arr,5);
		printf("Printing sorted array\n");
		print_array(arr,5);
}

int selection_sort(int *a,int n)
{
	int min_idx=0,i,j;
	for(i=0;i<n;i++)
	{
		min_idx=i;
		for(j=i;j<n;j++)
		{
			if(a[min_idx] > a[j])
				min_idx=j;
		}
		swap(&a[i],&a[min_idx]);
		printf("After pass %d\n",i);
		print_array(a,n);
	}

}

int print_array(int *a,int n)
{
		int i;
		for(i=0;i<n;i++)
				printf("%d  ",a[i]);
		printf("\n");
}

int swap(int *x,int *y)
{
		int temp=*x;*x=*y;*y=temp;
}
