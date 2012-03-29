#include<stdlib.h>
#include<stdio.h>

struct tree_el
{
	int val;
	struct tree_el * right, * left;
};

typedef struct tree_el node;

void insert(node ** tree, node * item)
{
	if(!(*tree)) {
		*tree = item;
		return;
	}
	if(item->val<(*tree)->val)
		insert(&(*tree)->left, item);
	else if(item->val>(*tree)->val)
		insert(&(*tree)->right, item);
}

void printout(node * tree) 
{
	if(tree->left) printout(tree->left);
	printf("%d\n",tree->val);
	if(tree->right) printout(tree->right);
}

void printout_preorder(node * tree) 
{
	printf("%d\n",tree->val);
	if(tree->left) printout(tree->left);
	if(tree->right) printout(tree->right);
}
int getmax(node *tree)
{
	if(tree->right) return getmax(tree->right);
	return tree->val;
}
int getmin(node *tree)
{
	if(tree->left) return getmin(tree->left);
	return tree->val;
}

int common_ancestor(node *root,int v1, int v2)
{
	int val=root->val;
	printf("Entered with val=%d v1=%d v2=%d\n",val,v1,v2);
	if(v1 > val && v2 > val)
		return common_ancestor(root->right,v1,v2);
	if(v1 < val && v2 < val)
		return common_ancestor(root->left,v1,v2);
	return val;
}
main()
{
	node * curr, * root;
	int i;
	int a[]={10,4,3,7,30,1,8,2,200,17};

	root = NULL;

	for(i=0;i<10;i++) {
		curr = (node *)malloc(sizeof(node));
		curr->left = curr->right = NULL;
		curr->val = a[i];
		insert(&root, curr);
	}

	printout(root);
	printout_preorder(root);
	printf("Max=%d\n",getmax(root));
	printf("Min=%d\n",getmin(root));
	printf("CA=%d\n",common_ancestor(root,3,7));
	printf("CA=%d\n",common_ancestor(root,3,1));
	printf("CA=%d\n",common_ancestor(root,3,9));
	printf("CA=%d\n",common_ancestor(root,2,200));
}
