#include "../include/stack.h"
#include <iostream>


bool stack::push(char x) 
{ 
    if (top >= (limit - 1)) { 
       
        return false; 
    } 
    else { 
        a[++top] = x; 
        
        return true; 
    } 
} 
  
char stack::pop() 
{ 
    if (top < 0) { 

        return 0; 
    } 
    else { 
        char x = a[top--]; 
        return x; 
    } 
}
bool stack::empty() 
{ 
    return (top < 0); 
} 