/* Quoc Lien.
*  Bungie Programming Test.
*  Duplicating a Singly Linkedlist,
*  with no dependency on original list.
*  10/18/2014
*/

#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *reference;
};

class SLL {
public:
	// Initializing a node.
	void init_node(s_node *, int);
	// Duplicates a linkedlist and returns its list. 
	struct s_node *duplicate_list(struct s_node *list);
	void print_list(s_node *list);
};

#endif
