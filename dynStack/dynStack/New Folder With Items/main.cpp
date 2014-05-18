//
//  main.cpp
//  dynStack
//
//  Created by Thomas on 5/7/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include <iostream>
#include "dynStack.h"

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    DynStack<int> *stack = new DynStack<int>(2);
    cout << "Pushing 3\n";
    (*stack) += 3;
    
    cout << "Pushing 4\n";
    (*stack) += 4;
    
    cout << "\n";
    
    std::cout << "Popped: " << stack->pop() << "\n";
    
    
    std::cout << "Top of stack is now: " << stack->getTopOfStack() << "\n";
    std::cout << "Size of stack is " << stack->getSize() << "\n";
    std::cout << "Number of Items in stack is: " << stack->getNumItems() << "\n";
    
    cout << "\n";
    
    cout << "Pushing 8\n";
    *stack += 8;
    cout << "Pushing 10\n";
    *stack += 10;   
    
    std::cout << "Top of stack is now: " << stack->getTopOfStack() << "\n";
    std::cout << "Size of stack is " << stack->getSize() << "\n";
    std::cout << "Number of Items in stack is: " << stack->getNumItems() << "\n";
    
    cout << "\n";
    
    
    cout << "Now printing stack contents.\n";
    std::cout << *stack;


    
    return 0;
}

