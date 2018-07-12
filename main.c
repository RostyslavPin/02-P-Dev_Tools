#include <stdlib.h>
#include <stdio.h>

struct Node {
	int				data;
	struct Node*	next; 
	struct Node*	prev;
};

void	insert(struct Node* prev_node, int new_data);
int		count(struct Node* node);
void	clear(struct Node** head_ref);
void	remove_node(struct Node** head_ref, struct Node *del);
void	reverse(struct Node** head_ref);
void	sorted_insert(struct Node** head_ref, struct Node* new_node);
void	insertion_sort(struct Node** head_ref);
void	print_list(struct Node* node);

int 	main()
{
	struct Node* head = NULL;
	tailadd(&head, 3);
	tailadd(&head, 10);
	insert(head->next, 55);
	insert(head->next, 5);
	printf("---------Unsorted-------\n");
	print_list(head);
	printf("---------Sorted---------\n");
	insertion_sort(&head);
	print_list(head);
	printf("Size is -- %d\n", count(head));
	printf("---------Reverse---------\n");
	reverse(&head);
	print_list(head);
	printf("Size is -- %d\n", count(head));
	printf("----------Remove---------\n");
	remove_node(&head, head);
	print_list(head);
	printf("Size is -- %d\n", count(head));
	printf("-----------Clear----------\n");
	clear(&head);
	printf("List is cleared size is -- %d\n", count(head));
	return (0);
}
