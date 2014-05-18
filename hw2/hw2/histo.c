//
//  histo.c
//  hw2
//
//  Created by Thomas Hocking on 2/12/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "histo.h"
#include <string.h>

// set all elements of the histogram to zero
void init_histogram(int histo[]){
    int i = 0;
    while (histo[i] != NULL) {
        histo[i] = 0;
        i++;
    }
}

// construct the histogram from string
void cons_histogram(const char string[], int histo[]){
    int i = 0;
    while (string[i] != '\0') {
        histo[i] = string[i];
        i++;
    }
}

// report a most occurring character
void most_frequent(const int histo[], char* ret_val){
    
}

// display the histogram sparsely
void display_histogram(const int histo[]);