#ifndef stack_H
#define stack_H	

#define limit 350 
  
  
class stack
{ 
    int top; 

public: 
    char a[limit]; 
  
    stack() { top = -1; } 
    bool push(char x); 
    char pop(); 
    bool empty();
}; 

#endif