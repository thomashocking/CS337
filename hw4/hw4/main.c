//
//  main.c
//  hw4
//
//  Created by Thomas on 2/27/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int main(int args, char* argv[])
{
	setbuf(stdout,NULL);
    
	node* head1;
	printf("Creating an empty list...\n\n");
	create_list(&head1);
    
	printf("Testing print_list on an empty list...\n\n");
	print_list(head1);
	printf("Testing add_front...\n");
	//Test add_front
	int i;
	for(i = 0; i < 10; i++)
	{
		node* node1 = (node*)malloc(sizeof(node));
		node1->data = i*2;
		add_front(&head1, node1);
	}
	printf("Printing list of elements {18,16,14,12,10,8,6,4,2,0}:\n\n");
	print_list(head1);
	printf("\nTesting remove back. This should be the previous nodes returned in ascending order.\n");
	for(i = 0; i < 10; i++)
	{
		node* node2 = rem_end(&head1);
		printf("\tRemoved node: %d\n", node2->data);
		free(node2);
	}
	printf("Printing empty list. No elements should be present...\n\n");
	print_list(head1);
    
	
	//Testing add_end and rem_front
	printf("Testing add_end...\n");
	for(i = 0; i < 10; i++)
	{
		node* node1 = (node*)malloc(sizeof(node));
		node1->data = i*2;
		add_end(&head1,node1);
	}
	printf("Printing the list {0,2,4,6,8,10,12,14,16,18}:\n\n");
	print_list(head1);
	printf("\nTesting rem_front. List items should be returned in ascending order.\n");
	for(i = 0; i < 10; i++)
	{
		node* returnedNode = rem_front(&head1);
		printf("\tRemoved node : %d\n",returnedNode->data);
		free(returnedNode);
	}
	printf("Testing print on an empty list...\n\n");
	print_list(head1);
    
	for(i = 0; i < 10; i++)
	{
		node* node1 = (node*)malloc(sizeof(node));
		node1->data = i*2;
		add_end(&head1,node1);
	}
    
	printf("\nTesting free_list\n");
	free_list(&head1);
	if(head1 == NULL)
	{
		printf("\tPassed!\n");
	}
	else
	{
		printf("\tFailed.\n");
		return 1;
	}
    
    
    printf("\nTesting add_inorder\n");
    for (i = 10; i > 0; i--) {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = i;
        printf("Adding: %d\n", i);
        add_inorder(&head1, new_node);
    }
    print_list(head1);

    
    printf("\nTesting rem_inorder\n");
    for (i = 10; i > 0; i--) {
        printf("Removing: %d\n", i);
        rem_inorder(&head1, i);
        if (i % 2 == 0) {
            print_list(head1);
        }
    }
    
    print_list(head1);
    
	printf("Testing completed!\n");
	return 0;
}
