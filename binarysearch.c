main()
{
	//int arr[5]={10,15,3,25,8};
	int arr[]={1,2,3,4,5,6,7,8,9,10};

	printf("Begin program\n");
	int idx=binary_search(arr,0,9,19);
	printf("The value of idx=%d\n",idx);
	idx=binary_search2(arr,10,9);
	printf("The value of idx=%d\n",idx);
}

int binary_search2(int *a,int n, int key)
{
	int lo=0,hi=n-1;
	int mid;

	do
	{
		mid=(lo+hi)/2;
		printf(" Beginloop lo=%d hi=%d mid=%d a[lo]=%d a[hi]=%d a[mid]=%d\n",lo,hi,mid,a[lo],a[hi],a[mid]);
		if(a[mid]==key) return mid;
		if(a[mid] > key) hi=mid-1;
		else lo=mid+1;
		//printf("Endloop lo=%d hi=%d mid=%d a[lo]=%d a[hi]=%d a[mid]=%d\n",lo,hi,mid,a[lo],a[hi],a[mid]);
	}
	while(lo < hi);
	return -1;
}

int binary_search(int a[], int low, int high, int target) {
    if (high < low)
        return -1;
    int middle = (low + high)/2;
    if (target < a[middle])
        return binary_search(a, low, middle-1, target);
    else if (target > a[middle])
        return binary_search(a, middle+1, high, target);
    else if (target == a[middle])
        return middle;
}
