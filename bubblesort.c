main()
{
		int arr[5]={10,15,3,25,8};
		//int arr[5]={1,2,3,4,5};

		bubble_sort(arr,5);
		printf("Printing sorted array\n");
		print_array(arr,5);
}

int bubble_sort(int *a,int n)
{
		int i,j,swapped=0;
		for(i=0;i<n-1;i++)
		{
				for(j=0;j<n-i-1;j++)
				{
						//	printf("i=%d j=%d a[i]=%d a[j]=%d\n",i,j,a[i],a[j]);
						if(a[j] > a[j+1])
						{
								swap(&a[j],&a[j+1]);
								swapped=1;
						}
						printf("After pass %d\n",i+1);
						print_array(a,5);
				}
				if(!swapped) break;
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
