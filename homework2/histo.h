//
//  histo.h
//  homework2
//
//  Created by Thomas Hocking on 2/12/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#define hw2_histo_h

#define MAX_CHAR 255 // largest ASCII(Extended) value for characters

typedef unsigned char byte; // may be useful for casting(s)

void init_histogram(int histo[]); // set all elements of the histogram to zero

void cons_histogram(const char string[], int histo[]); // construct the histogram from string

void most_frequent(const int histo[], char* ret_val); // report a most occurring character

void display_histogram(const int histo[]); // display the histogram sparsely

