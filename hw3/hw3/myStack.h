//
//  myStack.h
//  hw3
//
//  Created by Thomas Hocking on 2/19/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#ifndef hw3_myStack_h
#define hw3_myStack_h

double* create_a_stack(int* size, int *top);


//add a new value to the top of the stack if not full

void add(double **stack, int *top, int* size, const double new_value);

//remove (and return) the value at the top of the stack (if not empty)

void rem(double **stack, int *top, int* size);



void p_stack(double *stack,  int* size);

#endif
