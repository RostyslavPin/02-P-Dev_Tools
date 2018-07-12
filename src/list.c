#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void	tailadd(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return;
}

void	insert(struct Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		printf("previus node can't be NULL\n");
		return;
	}
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

int		count(struct Node* node)
{
	int len;

	len = 0;
	while (node != NULL)
	{
		len++;
		node = node->next;
	}
	return len;
}

void	clear(struct Node** head_ref)
{
	struct Node* node = *head_ref;
	struct Node* next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*head_ref = NULL;
}

void	remove_node(struct Node** head_ref, struct Node *del)
{
	if (*head_ref == NULL || del == NULL)
		return;
	if (*head_ref == del)
		*head_ref = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return;
}

void	reverse(struct Node** head_ref)
{
	struct Node *temp = NULL;
	struct Node *node = *head_ref;

	while (node != NULL)
	{
		temp = node->prev;
		node->prev = node->next;
		node->next = temp;
		node = node->prev;
	}
	if (temp != NULL)
		*head_ref = temp->prev;
}

void	sorted_insert(struct Node** head_ref, struct Node* new_node)
{
	struct Node* node;

	if (*head_ref == NULL)
		*head_ref = new_node;
	else if ((*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		new_node->next->prev = new_node;
		*head_ref = new_node;
	}
	else
	{
		node = *head_ref;
		while (node->next != NULL && node->next->data < new_node->data)
			node = node->next;
		new_node->next = node->next;
		if (node->next != NULL)
			new_node->next->prev = new_node;
		node->next = new_node;
		new_node->prev = node;
	}
}

void	insertion_sort(struct Node** head_ref)
{
	struct Node* sorted = NULL;
	struct Node* node = *head_ref;

	while (node != NULL)
	{
		struct Node* next = node->next;
		node->prev = node->next = NULL;
		sorted_insert(&sorted, node);
		node = next;
	}
	*head_ref = sorted;
}

void	print_list(struct Node* node)
{
	struct Node* last;

	while (node != NULL)
	{
		printf("%d\n", node->data);
		last = node;
		node = node->next;
	}
}