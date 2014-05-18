//
//  myStack.c
//  hw3
//
//  Created by Thomas Hocking on 2/19/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include "myStack.h"
#include <stdlib.h>
#include <stdio.h>

double* create_a_stack(int* size, int *top)
{
    //create stack of size 2.
    *top = 0;
    double *new_stack = (double *) malloc(sizeof(double) * (*size));
    int i;
    for (i = 0; i < *size; i++) {
        new_stack[i] = 0.0;
    }
    
    return new_stack;
}

//add a new value to the top of the stack if not full

void add(double **theStack, int *top, int *size, const double new_value)
{

    (*theStack)[*top] = new_value;
    ++(*top);
    
    double *stack = *theStack;

    
    if(*top==*size){
        *size *= 2;
        double *temp_stack = (double*)malloc(sizeof(stack) * (*size));
        int i;
        for(i = 0; i < *size; i++){
            temp_stack[i] = stack[i];
        }
        
        free(stack);
        *theStack = temp_stack;
        temp_stack = NULL;
    }
}

//remove (and return) the value at the top of the stack (if not empty)

void rem(double **theStack, int *top, int *size)
{
    double *stack = *theStack;
    
    if(*top != 0){
        --(*top);
        
    }

    
    if(*top<=*size/2){
        *size /= 2;

        double *temp_stack = (double*)malloc(sizeof(stack) * (*size));
        int i;
        for(i = 0; i < *size; i++){
            temp_stack[i] = stack[i];
        }
        
        free(stack);
        *theStack = temp_stack;
        temp_stack = NULL;
    }
}

void p_stack(double *stack,int *size){
    int count = 0;
    int i = 0;
    printf("\n");
    for (count = *size; count >= i; count--) {
        printf("|%.2f|\n", stack[count]);
    }
}