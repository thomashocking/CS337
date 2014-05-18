//
//  lists.c
//  hw4
//
//  Created by Thomas on 2/27/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
// create an empty list - set *node = NULL

void create_list(node** head)
{
    *head = NULL;
}

// add a new node to the front of the list

void add_front(node** head, node* new_node)
{
    if(*head == NULL){
        *head = new_node;
    }else{
        node *temp = *head;
        *head = new_node;
        (*head)->next = temp;
    }
}

// add a new node to the end of the list

void add_end(node** head, node* new_node)
{
    if (*head == NULL) {
        *head = new_node;
    }else{
        node *cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
        cur->next->next = NULL;
    }
}

// add a new node in the list, in (ascending) sorted order

void add_inorder(node** head, node* new_node) {
    node *prev = NULL;
    node *cur = *head;
    while (cur != NULL) {
        if (new_node->data > cur->data) {
            prev = cur;
            cur = cur->next;
        }else break;
    }
    
    if (prev != NULL) {
        prev->next = new_node;
        new_node->next = cur;
    }else{
        new_node->next = *head;
        *head = new_node;
    }
    
    return;
}

// remove and return the node at the front of the list or NULL if empty

node* rem_front(node** head)
{
    node *oldFront = (node *)malloc(sizeof(node));
    oldFront->data = (*head)->data;
    free(*head);
    *head = (*head)->next;
    return oldFront;
}

// remove and return the node at the end of the list or NULL if empty

node* rem_end(node** head)
{
    node *cur = *head;
    node *pre = cur;

    while (cur->next != NULL) {
        pre = cur;
        cur = cur->next;
    }
    node *oldLast = (node*)malloc(sizeof(node));
    oldLast->data = cur->data;
    
    if(cur == *head && pre == *head){
        *head = NULL;
    }else{
        free(pre->next);
        pre->next = NULL;
        return oldLast;
    }
    return oldLast;
}

// remove and return the first node in the list whose data value matches key
// return NULL if no such node exists in the list
node* rem_inorder(node** head, int key){
    node* prev = NULL;
	node* cur = *head;
	while (cur!=NULL) {
		if (cur->data == key) break;
		prev = cur;
		cur = cur->next;
	}
	if (cur != NULL) {
		if (prev)prev->next = cur->next;
        else *head = cur->next;
	}
	return cur;
}

// return the number of nodes in the list

int list_len(const node* head)
{
    int count = 0;
    node *cur = head;
    
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
    
}

// print the data values of all the nodes in the list (from start to end)

void print_list(const node* head)
{
    node *cur = head;
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}

// free the entire list and set *node = NULL

void free_list(node** head)
{
    if (*head == NULL) {
        return;
    }else{
        free_list(&(*head)->next);
        free(*head);
    }
    *head = NULL;
}