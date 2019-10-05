#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int key;
	struct BST *l , *r;
};

typedef struct BST tree;

void insert(tree **, int);
tree *search(tree *, int);
tree *findMin(tree *);
tree *findMax(tree *);
tree *predecessor(tree *, int);
tree *successor(tree *, int);
void in(tree *);
void pre(tree *);
void post(tree *);
tree *delete(tree *, int);

int main()
{
	int ele, val1;
	tree *root = NULL, *val = NULL;
	while(1)
	{
		char ch[5];
		scanf("%s", ch);
		if(strcmp(ch, "stop") == 0)
		{
			exit(0);
		}
		else if(strcmp(ch, "insr") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				insert(&root, ele);
			}
		}
		else if(strcmp(ch, "minm") == 0)
		{
			val = findMin(root);
			if(val == NULL)
			{
				printf("NIL\n");
			}
			else
			{
				printf("%d\n", val->key);
			}
		}
		else if(strcmp(ch, "maxm") == 0)
		{
			val = findMax(root);
			if(val == NULL)
			{
				printf("NIL\n");
			}
			else
			{
				printf("%d\n", val->key);
			}
		}
		else if(strcmp(ch, "srch") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				val = search(root, ele);
				if(val == NULL)
				{
					printf("NOT FOUND\n");
				}
				else
				{
					printf("FOUND\n");
				}
			}
		}
		else if(strcmp(ch, "delt") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				if(root == NULL)
				{
					printf("EMPTY LIST\n");
				}
				else
				{
					root = delete(root, ele);
				}
			}
		}

		else if(strcmp(ch, "pred") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				val = search(root, ele);
				if(val == NULL)
				{
					printf("NOT FOUND\n");
				}
				else
				{
					tree *res = predecessor(root, ele);
					if(res == NULL)
					{
						printf("NIL\n");
					}
					else
					{
						printf("%d\n", res->key);
					}
				}
			}
		}

		else if(strcmp(ch, "succ") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				val = search(root, ele);
				if(val == NULL)
				{
					printf("NOT FOUND\n");
				}
				else
				{
					tree *res = successor(root, ele);
					if(res == NULL)
					{
						printf("NIL\n");
					}
					else
					{
						printf("%d\n", res->key);
					}
				}
			}
		}

		else if(strcmp(ch, "inor") == 0)
		{
			if(root == NULL)
			{
				printf("EMPTY LIST\n");
			}
			else
			{
				in(root);
				printf("\n");
			}
		}
		else if(strcmp(ch, "prer") == 0)
		{
			if(root == NULL)
			{
				printf("EMPTY LIST\n");
			}
			else
			{
				pre(root);
				printf("\n");
			}
		}
		else if(strcmp(ch, "post") == 0)
		{
			if(root == NULL)
			{
				printf("EMPTY LIST\n");
			}
			else
			{
				post(root);
				printf("\n");
			}
		}
	}
	return 0;
}

tree *findMax(tree *node)
{
	if(node == NULL)
	{
		return node;
	}

	tree *current = node;
	while(current->r != NULL)
	{
		current = current->r;
	}
	return current;
}

tree *findMin(tree *node)
{
	if(node == NULL)
	{
		return node;
	}

	tree *current = node;
	while(current->l  != NULL)
	{
		current = current->l ;
	}
	return current;
}

void insert(tree **node, int element)
{
	tree *t , *pre, *current;
	t  = (tree *)malloc(sizeof(tree));
	t ->key = element;
	t ->l  = t ->r = NULL;
	if(*node == NULL)
	{		
		*node = t ;
	}

	else
	{
		current = *node;
		while(current != NULL)
		{
			pre = current;
			if(t ->key > current->key)
			{
				current = current->r;
			}
			else
			{
				current = current->l ;
			}
		}

		if(t ->key > pre->key)
		{
			pre->r = t ;
		}
		else
		{
			pre->l  = t ;
		}
	}	
}

tree *search(tree *node, int element)
{
	if(node == NULL)
	{
		return node;
	}

	else
	{
		if(node->key == element)
		{
			return node;
		}

		else if(node->key > element)
		{
			return search(node->l , element);
		}

		else
		{
			return search(node->r, element);
		}
	}
}

tree *predecessor(tree *root, int element)
{
	tree *node;
	node = search(root, element);

//	printf("pre = %d\n", node->key);
	if(node->l  != NULL)
	{
		return findMax(node->l );
	}

	tree *pred = NULL;

	while(root != NULL)
	{
		if(root->key < element)
		{
			pred = root;
			root = root->r;
		}

		else if(root->key > element)
		{
			root = root->l ;
		}

		else
		{
			break;
		}
	}
	return pred;
}

tree *successor(tree *root, int element)
{
	tree *node;
	node = search(root, element);
//	printf("succ = %d\n", node->key);

	if(node->r != NULL)
	{
		return findMin(node->r);
	}

	tree *succ = NULL;

	while(root != NULL)
	{
		if(root->key > element)
		{
			succ = root;
			root = root->l ;
		}

		else if(root->key < element)
		{
			root = root->r;
		}
		else
		{
			break;
		}
	}
	return succ;
}

void in(tree *node)
{
	if(node != NULL)
	{
		in(node->l );
		printf("%d ", node->key);
		in(node->r);
	}
}

void pre(tree *node)
{
	if(node != NULL)
	{
		printf("%d ", node->key);
		pre(node->l );		
		pre(node->r);
	}
}

void post(tree *node)
{
	if(node != NULL)
	{
		post(node->l );		
		post(node->r);
		printf("%d ", node->key);
	}
}

tree *delete(tree *node, int key)
{
	if(node == NULL)
	{
		return node;
	}

	if(node->key > key)
	{
		node->l  = delete(node->l , key);
	}

	else if(node->key < key)
	{
		node->r = delete(node->r, key);
	}

	else
	{
		tree *t ;
		if(node->l  == NULL)
		{
			t  = node->r;
			free(node);
			return t ;
		}
		else if(node->r == NULL)
		{
			t  = node->l ;
			free(node);
			return t ;
		}

		t  = findMin(node->r);
		node->key = t ->key;
		node->r = delete(node->r, t ->key);
	}
	return node;
}

