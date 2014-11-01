#include "SLL.h"

s_node *head = NULL, *tail = NULL;

/* Initializing LinkedList Node */
void init_node(s_node * n, int d) {
	n->data = d;
	n->next = NULL;
	n->reference = NULL;
}

/* Parameter: Pointer to a LinkedList.
 * Purpose: To duplicate the Singly LinkedList without referencing the original.
 * Time & Space Complexity: T = O(n), S = O(n)
 */
struct s_node *duplicate_list(struct s_node *list) {
	// Checking for NULL list - Base Case
	if(list == NULL) {
		return NULL;
	}

	// Creating new LinkedList.
	s_node *node = new s_node;
	// Head pointer and tail pointer for O(1) Head/Tail insertion.
	head = tail = node;

	/* Duplicating the original list, using a current pointer to next nodes. */
	s_node *current = list;
	while(current != NULL) {
		node->data = current->data;
		
		// Do not need to create a new node if the next equals to NULL.
		if(current->next != NULL) {
			s_node *new_node = new s_node; // Creating a new node for the linkedlist, and initalize it to 0.
			init_node(new_node, 0);
			node->next = new_node;
			node = node->next;
			tail = node; // Point tail to the new node.
		} 

		current = current->next;
	}

	return head;
}

/* Prints the LinkedList */
void print_list(s_node *list) {
	s_node *temp = list;
	while(temp != NULL) {
		printf("%i\t%p\n", temp->data, temp); // Prints the Data, and its Address.
		temp = temp->next;
	}
}

int main(int argc, char* argv[]) {
	s_node *list, *dup;
	s_node linkedlist, one, two, three, four;

	// Creating a test LinkedList
	init_node(&linkedlist, 0);
	init_node(&one, 1);
	init_node(&two, 2);
	init_node(&three, 3);
	init_node(&four, 4);

	linkedlist.next = &one;
	one.next = &two;
	two.next = &three;
	three.next = &four;

	list = &linkedlist;

	dup = duplicate_list(list);
	printf("%s\n", "Original linkedlist and Address.");
	print_list(list);
	printf("%s\n", "Duplicate linkedlist and Address.");
	print_list(dup);

	return 0;
}
