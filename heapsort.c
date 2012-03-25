#define MAX 500
struct heap
{
	int a[MAX];
	int size;
};

main()
{
	int a[]={8,4,11,7,1,3,9,2,13,5,10,12,6};
	int i;
	int size=sizeof(a)/sizeof(int);
	int element;
	struct heap myheap;
	heap_init(&myheap);
	heap_print(&myheap);
	for(i=0;i<size;i++)
	{
		printf("Inserting element %d\n",a[i]);
		heap_insert_element(&myheap,a[i]);
		heap_print(&myheap);
	}
//	print_tree(a,size);
	while(!heap_is_empty(&myheap))
	{
		element=heap_remove_element(&myheap);
		printf("Removed element is %d\n",element);
		//heap_print(&myheap);
	}

}

int left(int idx)
{
	return 2*idx+1;
}

int right(int idx)
{
	return 2*idx+2;
}

int parent(int idx)
{
	return (idx-1)/2;
}

int heap_print(struct heap *h)
{
	int *a=h->a;
	int howmany=h->size;
	int i,nl=0;
	printf("Printing %d elements of heap\n",howmany);
	for(i=0;i<howmany;i++)
	{
		printf("%d\t", a[i]);
		//printf("DEBUG:i=%d nl=%d eval=%d\n",i,nl,(power(2,nl+1)-2));
		if(i==(power(2,nl+1)-2)){ printf("\n");nl++;}
	}
	printf("\n");
	for(i=0;i<howmany/2;i++)
	{
//		printf("Node=%d left=%d right=%d\n",a[i],a[left(i)],a[right(i)]);
	}

}

int power(int base,int exp)
{
	int result=1,i;
	for(i=0;i<exp;i++)
		result*=base;
	return result;
}

int heap_init(struct heap *h)
{
	h->size=0;
}

int heap_is_empty(struct heap *h)
{
	return h->size==0;
}

int heap_insert_element(struct heap *h, int element)
{
	int index=0;
	if(h->size==MAX)
	{
		printf("Can not insert into heap. No space\n");
		return;
	}
	index=h->size;

	h->a[index]=element;
	h->size++;

	heap_balance_node_up(h,index);
	return 0;
}

int heap_balance_node_up(struct heap *h, int index)
{
	if(index==0) return 0;
	//if this node is larger than its parent swap it.

	if(h->a[index] > h->a[parent(index)])
	{
		swap(&(h->a[index]),&(h->a[parent(index)]));
		heap_balance_node_up(h,parent(index));
	}
	return 0;
}

int heap_balance_node_down(struct heap *h,int index)
{
	int l, r, max_index;
	l=left(index);
	r=right(index);
	//printf("Entered heap_balance_node_down with index=%d l=%d r=%d size=%d\n",index,h->size);
	if(l > h->size-1) return;

	max_index=l;
	if(h->a[max_index] < h->a[r])
	{
		max_index=r;
	}
	swap(&(h->a[index]),&(h->a[max_index]));
	heap_balance_node_down(h,max_index);

}

int swap(int *x, int *y)
{
	int temp=*x;*x=*y;*y=temp;
	printf("swapping %d with %d\n",*y,*x);
}



int heap_remove_element(struct heap *h)
{
	int max;
	max=h->a[0];
	h->a[0]=h->a[--h->size];

	//now balance this heap at root and trickle down
	heap_balance_node_down(h,0);

	return max;
}
