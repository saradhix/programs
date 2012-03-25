/*To determine if two strings are anagrams or not*/
#define MAX_CHARS 26
main()
{

	printf("%d\n",is_anagram("cat","act"));
	printf("%d\n",is_anagram("bat","rat"));
	printf("%d\n",is_anagram("dictionary","indicatory"));
}

int is_anagram(char *s,char *t)
{
	int counts[MAX_CHARS]={0};
	int i;
	for(i=0;s[i];i++)
	{
		counts[s[i]-'a']++;
	}

	for(i=0;t[i];i++)
	{
		counts[t[i]-'a']--;
	}

	for(i=0;i<MAX_CHARS;i++)
		if(counts[i]) return 0;
	return 1;
}
