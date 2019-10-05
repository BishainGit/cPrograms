#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int key;
	struct BST *l, *r;
};

typedef struct BST tree;

void insert(tree **, int);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
tree *toBT(int [], int [], int, int);

int main()
{
	int n, i;
	scanf("%d", &n);

	if(n <= 0)
	{
		printf("INVALID INPUT\n");
		return 0;
	}

	int pre[n], in[n];

	for(i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
		if(pre[i] >= 2147483648 || pre[i] <= -2147483648)
		{
			printf("INVALID INPUT\n");
			return 0;
		}
	}

	scanf("%d", &in[0]);
	int max = in[0];
	for(i = 1; i < n; i++)
	{
		scanf("%d", &in[i]);
		if(in[i] < in[i - 1])
		{
			printf("INVALID INORDER TRAVERSAL\n");
			return 0;
		}
	}

	tree *root = toBT(pre, in, 0, n - 1);
	preorder(root);

	return 0;
}

tree *toBT(int pre[], int in[], int start, int end)
{
	static int index = 0;
	if(start > end)
	{
		return NULL;
	}

	tree *new_node = (tree *)malloc(sizeof(tree));
	new_node->key = pre[index];
	new_node->l = NULL;
	new_node->r = NULL;
	
	index++;

	if(start == end)
	{
		return new_node;
	}

	int i, pos;
	for(i = start; i <= end; i++)
	{
		if(in[i] == new_node->key)
		{
			pos = i;
		}
	}

	new_node->l = toBT(pre, in, start, pos - 1);
	new_node->r = toBT(pre, in, pos + 1, end);
	
	return new_node;
}

void insert(tree **node, int element)
{
	tree *t, *pre, *current;
	t = (tree *)malloc(sizeof(tree));
	t->key = element;
	t->l = t->r = NULL;
	if(*node == NULL)
	{		
		*node = t;
	}

	else
	{
		current = *node;
		while(current != NULL)
		{
			pre = current;
			if(t->key > current->key)
			{
				current = current->r;
			}
			else
			{
				current = current->l;
			}
		}

		if(t->key > pre->key)
		{
			pre->r = t;
		}
		else
		{
			pre->l = t;
		}
	}	
}

void preorder(tree *node)
{
	if(node != NULL)
	{
		printf("( ");
		printf("%d ", node->key);
		preorder(node->l);
		preorder(node->r);
		printf(") ");
	}
	else
	{
		printf("() ");
		return;
	}
}
