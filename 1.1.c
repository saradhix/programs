#define MAX_CHARS 26
main()
{
printf("saradhi->%d\n",has_uniq_chars("saradhi"));
printf("saketh->%d\n",has_uniq_chars("saketh"));
printf("ramya->%d\n",has_uniq_chars("ramya"));
printf("sruthi->%d\n",has_uniq_chars("sruthi"));
}

int has_uniq_chars(char *s)
{
	int counts[MAX_CHARS]={0};
	int i;
	for(i=0;s[i];i++)
	{
		if(counts[s[i]-'a']) return 0;
		counts[s[i]-'a']=1;
	}
	return 1;
}
