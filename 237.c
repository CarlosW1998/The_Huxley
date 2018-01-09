#include <stdio.h>
#include<stdlib.h>

typedef struct _Tree Tree;
typedef struct _list list;

Tree *creat_tree(char value);
list *push(list *head, char value);


int main()
{
	Tree *root = creat_tree(0);

	return 0;
}
struct  _Tree
{
	char value;
	list *next;
};
struct _list
{
	Tree *actual;
	list *next;
};
Tree *creat_tree(char value)
{
	Tree *new_tree = (*Tree) malloc(sizeof(Tree));
	new_tree->value = value;
	new_tree->next = NULL;

	return new_tree;
}
list *creat_list()
{
	list *new = (*list) malloc(sizeof(list));
	new->actual = NULL;
	new->next = NULL;

	return new;
}
list *push(list *head, char value)
{
	list *new = creat_list;
	new->actual = creat_tree(value);
	new->next = head;
	return new;	
}