main()
{
	char bit_vector[5000]={0};
	int i;
	set_bit(2,bit_vector);
	set_bit(3,bit_vector);
	set_bit(4,bit_vector);
	set_bit(227,bit_vector);
	set_bit(500,bit_vector);
	for(i=0;i<5000;i++)
	{
		if(get_bit(i,bit_vector))printf("%d is present\n",i);
	}
}


int set_bit(int x, char *bit_vector)
{
	bit_vector[x/8] |=1<<(x%8);
	return 0;
}

int get_bit(int x,char *bit_vector)
{
	return bit_vector[x/8]&(1<<(x%8));
}


