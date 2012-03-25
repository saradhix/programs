main()
{

	char s[]="saradhi";
	reverse(s);
	printf("String is %s\n",s);
}

void reverse(char *s)
{
	char *start=s;
	char *end=start;
	char temp;

	while(*end)
		end++;

	--end;
	while(start < end)
	{
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
}

