//
//  lists.h
//  hw4
//
//  Created by Thomas on 2/27/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#ifndef hw4_lists_h
#define hw4_lists_h

// a recursive data type definition

// serves as the nodes of a list

typedef struct node

{
    
    int data;
    
    struct node* next;
    
} node;

// create an empty list - set *node = NULL

void create_list(node** head);

// add a new node to the front of the list

void add_front(node** head, node* new_node);

// add a new node to the end of the list

void add_end(node** head, node* new_node);

// add a new node in the list, in (ascending) sorted order

void add_inorder(node** head, node* new_node);

// remove and return the node at the front of the list or NULL if empty

node* rem_front(node** head);

// remove and return the node at the end of the list or NULL if empty

node* rem_end(node** head);

// remove and return the first node in the list whose data value matches key
// return NULL if no such node exists in the list
node* rem_inorder(node** head, int key);

// return the number of nodes in the list

int list_len(const node* head);

// print the data values of all the nodes in the list (from start to end)

void print_list(const node* head);

// free the entire list and set *node = NULL

void free_list(node** head);

#endif
