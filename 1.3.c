#define MAX_CHARS 26
main()
{
	char s[]="ramya";
	char t[]="sruthi";
	remove_dups(s);
	remove_dups(t);

	printf("s=%s\nt=%s\n",s,t);
}


void remove_dups(char *s)
{
	int i;
	int pos=0;
	int counts[MAX_CHARS]={0};
	for(i=0;s[i];i++)
	{
		counts[s[i]-'a']=1;
	}

	for(i=0;s[i];i++)
	{
		if(counts[s[i]-'a']==1)
		{
			s[pos]=s[i];
			counts[s[i]-'a']=2;
			pos++;
		}
	}
	s[pos]=0;
}

