main()
{
		int arr[8]={10,15,3,25,8,2,19,30};
		//int arr[5]={1,2,3,4,5};

		insertion_sort(arr,8);
		printf("Printing sorted array\n");
		print_array(arr,8);
}

int insertion_sort(int *a,int n)
{
	int selected=0,i,j,k;
	for(i=1;i<n;i++)
	{
		selected=a[i];
		j=i-1;
//		printf("selected=%d i=%d j=%d\n",selected,i,j);
		//move this selecte number into the sorted list till it finds its place
		while(selected < a[j] && j >= 0)
		{
			a[j+1]=a[j];
			j--;
		}
//		printf("Value of j is %d\n",j);
		a[j+1]=selected;
		printf("After iteration %d\n",i);
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
