char *my_itoa(int x, char *s);
main()
{
	int x;
	char str[]="saradhi";
	char y[30];
	x=my_atoi("1023");
	printf("X=%d\n",x);
	reverse(str);
	printf("str=%s\n",str);
	my_itoa(4567,y);
	printf("y=%s\n",y);
	mystrcpy(str,y);
	printf("y=%s\n",y);
	printf("strcmp=%d\n",mystrcmp("sara","sara"));
	printf("strcmp=%d\n",mystrcmp("sara","Sara"));
	printf("strcmp=%d\n",recursive_mystrcmp("sara","sara"));
	printf("strcmp=%d\n",recursive_mystrcmp("sara","Sara"));
	printf("palindrome=%d\n",is_palindrome("madam"));
	printf("palindrome=%d\n",is_palindrome("hello"));

	
}

int my_atoi(char *s)
{
	int result=0;
	while(*s)
	{
		result=result*10+*s-'0';
		s++;
	}
	return result;
}

char *my_itoa(int x, char *s)
{
	int i=0;
	while(x)
	{
		s[i]=x%10+'0';
		x/=10;
		i++;
	}
	s[i]=0;
	reverse(s);
}

int reverse(char *s)
{
	char *start=s;
	char *end=s+strlen(s)-1;
	char temp;
	while(end > start)
	{
		temp=*end;
		*end=*start;
		*start=temp;
		end--;
		start++;
	}
}

int mystrcpy(char *src, char *dest)
{
	while(*dest++=*src++);
}

int mystrcmp(char *a, char *b)
{
	while(*a==*b)
	{
		if(*a==0) return 0;
		a++;
		b++;
	}
	return *a-*b;
}

int recursive_mystrcmp(char *a, char *b)
{
	//printf("a=%s b=%s\n",a,b);
	
	if(*a==0||*b==0) return *a - *b;
	if(*a==*b)return recursive_mystrcmp(a+1,b+1);
	return *a-*b;
}

int is_palindrome(char *s)
{
	int len=strlen(s);
	char *start=s,*end=s+strlen(s)-1;
	while(end > start)
	{
		if(*end !=*start) return 0;
		end--;
		start++;
	}
	return 1;
}
