#include <stdio.h>
#include <malloc.h>
struct list
{
	int data;
	struct list *next;
};
main()
{
	struct list *head=NULL;
	struct list *loop=NULL;
	int loop_len=0;
	list_append(&head,10);
	list_append(&head,20);
	list_append(&head,30);
	list_append(&head,40);
	list_append(&head,50);
	list_append(&head,60);
	list_append(&head,70);
	list_append(&head,80);
	loop= has_loop(&head);
	printf("Loop at %x\n",loop);

	loop_len=get_loop_length(loop);
	printf("Length of the loop=%d\n",loop_len);
	loop=get_merge_point(&head,loop_len);
	printf("Data at merge=%d\n",loop->data);
	print_list(&head);
}

int get_merge_point(struct list **head, int count)
{
	struct list *start=*head;
	struct list *end=start;
	int i;
	while(1)
	{
		end=start;
		for(i=0;i<count;i++)
			end=end->next;
		printf("start=%d end=%d\n",start->data,end->data);

		if(start==end) return start;
		start=start->next;
	}
}



int get_loop_length(struct list *loop)
{
	struct list *start=loop;
	int count=0;
	while(loop && loop->next)
	{
		if(loop->next==start) return 1+count;
		loop=loop->next;
		count++;
	}
}

int has_loop(struct list **head)
{
	struct list *f=*head;
	struct list *s=*head;

	while(f && s)
	{
		f=f->next;
		s=s->next->next;
		if(f==s) return f;
	}
	return 0;
}


int list_append(struct list **head, int data)
{
	static int i=0;
	static struct list *spl=NULL;
	++i;
	struct list *start=*head;
	struct list *temp;
	if(start==NULL)
	{
		temp=malloc(sizeof(struct list));
		temp->next=NULL;
		*head=temp;
		temp->data=data;
		return;
	}

	while(start&&start->next)
	{
		start=start->next;
	}
	temp=malloc(sizeof(struct list));
	temp->next=NULL;
	start->next=temp;
	temp->data=data;
	if(i==4) spl=temp;
	if(i==8) temp->next=spl;
}

int print_list(struct list **head)
{
	struct list *start=*head;
int count=0;
	while(start)
	{
		printf("Data=%d addr=%xnext=%x\n",start->data,start,start->next);
		start=start->next;
count++;
if(count >=10) break;
	}
}


