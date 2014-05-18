//
//  histo.c
//  homework2
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
    int i;
    for (i = 0; i<256; i++) {
        histo[i] = 0;
    }
}

// construct the histogram from string
void cons_histogram(const char string[], int histo[]){
    int length_of_string = strlen(string);
    int i;
    for (i = 0; i < length_of_string; i++) {
        histo[i] = (int)string[i];
    }
}

// report a most occurring character
void most_frequent(const int histo[], char* ret_val){
    int counter[256] = {0};
    int i;
    for (i = 0; i < 256; i++) {
        counter[histo[i]]++;
    }
    
    int max = 0;
    char character = 0;
    for (i = 1; i < 256; i++) {
        if (max < counter[i]) {
            max = counter[i];
            character = (char)i;
        }
    }
    
    *ret_val = character;
    
}

// display the histogram sparsely
void display_histogram(const int histo[]){
    char most_common;
    
    most_frequent(histo, &most_common);
    
    int counter[256] = {0};
    int i;
    for (i = 0; i < 256; i++) {
        counter[histo[i]]++;
    }
    
    for (i = 1; i < 256; i++) {
        if (counter[i] > 0) {
            printf("%c occured %d times\n", (char)i, counter[i]);
        }
    }
    
    printf("Most common char is %c\n", most_common);
    
}