//
//  main.c
//  hw3
//
//  Created by Thomas Hocking on 2/19/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "myStack.h"

#define INIT_SIZE  2;

int main(int argc, const char * argv[])
{
    int top = 0;
    int size;
    size = INIT_SIZE;
    
    double *t_stack = create_a_stack(&size, &top);
    //adding two items.
    printf("\nTotal Size: %d\n", size);
    add(&t_stack, &top, &size, 7.0);

    add(&t_stack, &top, &size, 6.0);

    add(&t_stack, &top, &size, 5.0);

    add(&t_stack, &top, &size, 4.0);
    add(&t_stack, &top, &size, 3.0);

    //double.
    p_stack(t_stack, &top);
    printf("\nTotal Size: %d\n", size);

    
    //three items.
    add(&t_stack, &top, &size, 2.0);

    p_stack(t_stack, &top);
    printf("\nTotal Size: %d\n", size);

    
    //four items.
    add(&t_stack, &top, &size, 1.0);

    p_stack(t_stack, &top);
    printf("\nTotal Size: %d\n", size);
    
    p_stack(t_stack, &top);

    
    //remove two
    printf("Removing two.");
    rem(&t_stack, &top, &size);
    rem(&t_stack, &top, &size);
    rem(&t_stack, &top, &size);
    rem(&t_stack, &top, &size);
    rem(&t_stack, &top, &size);

    



    //back to size 2.
    printf("\n\n");
    p_stack(t_stack, &top);
    printf("\nTotal Size: %d\n", size);

    
    
    return 0;
}

