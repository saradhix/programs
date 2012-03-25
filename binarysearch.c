main()
{
	//int arr[5]={10,15,3,25,8};
	int arr[]={1,2,3,4,5,6,7,8,9,10};

	int idx=binary_search(arr,10,9);
	printf("The value of idx=%d\n",idx);
}

int binary_search(int *a,int n, int key)
{
	int lo=0,hi=n-1;
	int mid;

	do
	{
		mid=(lo+hi)/2;
		//printf(" Beginloop lo=%d hi=%d mid=%d a[lo]=%d a[hi]=%d a[mid]=%d\n",lo,hi,mid,a[lo],a[hi],a[mid]);
		if(a[mid]==key) return mid;
		if(a[mid] > key) hi=mid;
		else lo=mid;
		//printf("Endloop lo=%d hi=%d mid=%d a[lo]=%d a[hi]=%d a[mid]=%d\n",lo,hi,mid,a[lo],a[hi],a[mid]);
	}
	while(lo <= hi);
	return -1;
}


