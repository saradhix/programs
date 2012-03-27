/*Let a be a sorted aray of integers and S a target integer. Design an efficient algoritm for determining if there exists a pair of indices i,j(not necessarily distinct) such that A[i]+A[j]=S;
*/

main()
{
int arr[]={2,3,4,5,6,7,8,7};
int result[2];
pairsum(arr,8,4,result);
print_result(result);
pairsum(arr,8,5,result);
print_result(result);
pairsum(arr,8,10,result);
print_result(result);
pairsum(arr,8,13,result);
print_result(result);
pairsum(arr,8,15,result);
print_result(result);
pairsum(arr,8,17,result);
print_result(result);

}

int pairsum(int a[],int howmany, int sum, int result[])
{
	int i,val;
	int hash[500]={0};
	for(i=0;i<500;i++) hash[i]=-1;

	int complement;
	result[0]=result[1]=-1;
	for(i=0;i<howmany;i++)
	{
		complement=sum-a[i];
		//printf("i=%d a[i]=%d comple=%d\n",i,a[i],complement);
		set_hash(hash,a[i],i);
		if(complement > 0 && ((val=get_hash(hash,complement))!=-1))
		{
			result[0]=val;
			result[1]=i;
			return;
		}
	}

}
int set_hash(char *hash,int key, int value)
{
if(key<0) key=500+key;
//printf("Setting hash[%d]=%d\n",key,value);
hash[key]=value;
}

int get_hash(char *hash, int key)
{
int value=0;
if(key<0) key+=500;
value=hash[key];
//printf("Getting hash[%d]=%d\n",key,value);
return value;
}

int print_result(int result[])
{
	printf("Result=%d %d\n",result[0],result[1]);
}
