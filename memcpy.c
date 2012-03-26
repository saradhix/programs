main()
{
char str[]="India is Great";
char tar[30]={0};

memcopy(str,tar,strlen(str)+1);
printf("Tar=%s\n",tar);
}

int memcopy(void *s, void *d, int count)
{
while(count--)
*(char *)d++=*(char *)s++;
}
