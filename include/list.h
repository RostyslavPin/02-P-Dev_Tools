#ifndef LIST_H
# define LIST_H

struct Node {
	int				data;
	struct Node*	next; 
	struct Node*	prev;
};
/** 
 * tailadd() - appends one element to the end of the list.
 * @list head position:	List in which we add node.
 * @new node:	Node which we want to add.
 */
void	tailadd(struct Node** head_ref, int new_data);
/** 
 * insert() - put node at exact position in the list.
 * @list prev position:	List in which we add node.
 * @new node:	Node which we want to add.
 */
void	insert(struct Node* prev_node, int new_data);
/** 
 * count() - returns the number of elements in a list, which are equal to the given one.
 * @list:	List in which we want to know the size.
 */
int		count(struct Node* node);
/** 
 * clear() - make the list empty.
 * @list:	List which we want to clean.
 */
void	clear(struct Node** head_ref);
/** 
 * remove_node() - removes node from list.
 * @list:	List in which we want to know remove node.
 * @position:	Position of node.
 */
void	remove_node(struct Node** head_ref, struct Node *del);
/** 
 * reverse() - verse the order of items in the list.
 * @list:	List which need to reverse.
 */
void	reverse(struct Node** head_ref);
/** 
 * sorted_insert() - function to insert a new node in sorted way in a sorted doubly linked list.
 * @list:	The list.
 * @new node:	New node in a sorted way.
 */
void	sorted_insert(struct Node** head_ref, struct Node* new_node);
/** 
 * insertion_sort() - function to sort a doubly linked list using insertion sort.
 * @list:	List which need to sort.
 */
void	insertion_sort(struct Node** head_ref);
/** 
 * print_list() - show the elements in the list.
 * @list:	List which need to print.
 */
void	print_list(struct Node* node);
# endif