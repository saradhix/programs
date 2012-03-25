main()
{
	int arr[13]={10,15,3,25,8,44,4,1,7,17,2,33,99};
	//	int arr[5]={1,2,3,4,5};
	int a[5]={1,2,3,4,5};
	int b[5]={2,4};
	int c[10];

//	merge(a,5,b,2,c,10);
//	printf("Printing sorted array\n");
//	print_array(c,7);
	merge_sort(arr,13);
	printf("Printing sorted array\n");
	print_array(arr,13);
}

int merge_sort(int *a,int n)
{
	printf("Merge sorting %d elements of array\n",n);
	print_array(a,n);
	int final[100]={0};
	if(n==1) return;
	if(n==2)
	{
		if(a[0] > a[1]) swap(&a[0],&a[1]);
		return;
	}

	merge_sort(a,n/2);
	merge_sort(a+n/2,n/2+n%2);
	merge(a,n/2,a+n/2,n/2+n%2,final);
	copy_array(a,final,n);

}
int merge(int *a,int m, int *b, int n, int *final)
{
	int cx=0,cy=0,cz=0;
	printf("Merging two arrays of sizes %d and %d \n",m,n);
	print_array(a,m);
	print_array(b,n);


	while((cx < m ) &&(cy < n))
	{
		if(a[cx]< b[cy])
		{
			final[cz++]=a[cx];
			cx++;
		}
		else
		{
			final[cz++]=b[cy];
			cy++;
		}
	}
//	printf("cx=%d cy=%d cz=%d\n",cx,cy,cz);
	if(cx==m)
	{
		//copy remaining from b to final
		while(cy<n)
		{
			final[cz++]=b[cy++];
		}
	}
	else
	{
		//copy remaining from a to final
		while(cx<m)
		{
			//printf("Copying %d of a at idx=%d to idx of final=%d\n",a[cx],cx,cz);
			final[cz++]=a[cx++];
		}
	}
	print_array(final,m+n);
} 



int print_array(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
int copy_array(int *t,int *s,int n)
{
	int i;
	for(i=0;i<n;i++)
		*(t+i)=*(s+i);
}

int swap(int *x,int *y)
{
	int temp=*x;*x=*y;*y=temp;
}
