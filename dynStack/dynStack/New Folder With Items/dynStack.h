//
//  dynStack.h
//  dynStack
//
//  Created by Thomas on 5/7/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#ifndef dynStack_dynStack_h
#define dynStack_dynStack_h
#include <iostream>

using namespace std;

template <class T>
class DynStack{
    
    private:
    // Structure for stack nodes
    T *elements;
    int currentIndex;
    int size;
    int numItems;

    bool checkFull(){
        if (currentIndex == size) {
            return true;
        }
        return false;
    }
    
    bool isHalfEmpty(){
        if(size > 0)
            if(currentIndex <= size/2) return true;
        return false;
    }
    
    public:
        // Constructor
    DynStack(int s){
        elements = new T[s];
        size = s;
        currentIndex = 0;
        numItems = 0;
    }
    
    int getNumItems(){
        return numItems;
    }
    
    int getSize(){
        return size;
    }
    
    T getTopOfStack(){
        int top;
        if(currentIndex > 0){
            top = currentIndex - 1;
        }else
            top = currentIndex;
        return elements[top];
    }
    
        // Destructor
    ~DynStack() {
        delete elements;
    }
    
    // Stack operations
    void push(T object){
        if (!checkFull()) {
            elements[currentIndex++] = object;
            numItems++;
        }else{
            int new_size;
            T* tempStack;
            
            new_size = size == 0 ? 1 : 2 * size;
            tempStack = new T[new_size];
            for ( int i = 0; i < size; i++) tempStack[i] = elements[i];
            
            delete elements;
            elements = tempStack;
            size = new_size;
            elements[currentIndex++] = object;
            numItems++;
        }
    }
    
        T pop(){
            if(!isHalfEmpty()){
                numItems--;
                return elements[--currentIndex];
            }else{
                int new_size = size/2;
                T *tempStack = new T[new_size];
                for (int i = 0; i < size; i++) {
                    tempStack[i] = elements[i];
                }
                delete elements;
                elements = tempStack;
                size = new_size;
                numItems--;
                return elements[--currentIndex];
            }
        }
    
    void operator += ( T obj ) {
        this->push(obj);
    }
    
    friend ostream& operator<<(ostream &outs, const DynStack &obj)
    {
        //  outs << obj.getData();
        for(int i = obj.numItems; i > 0; i--){
           outs << obj.elements[i-1] << "\n";
        }
        
        return outs;
    }
    
    };






#endif
