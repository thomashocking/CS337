//
//  main.c
//  hw2
//
//  Created by Thomas Hocking on 2/12/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "histo.h"

int main(int args, char *argv[])

{
    
    int histo[256];
    
    if (args == 2)
        
    
        
    {
    
        init_histogram(histo);
        
        cons_histogram(argv[1], histo);
        
        display_histogram(histo);
        
    }
    
    else
        
        exit(1);
    
    return 0;
    
}

