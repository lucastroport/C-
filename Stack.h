#ifndef STACK_H
#define STACK_H


     template<class T>
     class Stack{
      public:
      /*Constructors*/
         Stack(){}
      //Contructor with max capacity
        Stack(int n){}
         //Destructor
        virtual~Stack(){}
        //Pre: -
        //Post: Empties the structure
        virtual void empty()=0;
        //Pre: -
        //Post: Adds an element at the top of the structure
        virtual void push (T e) = 0;
        //Pre: the structure is not empty
        //Post: Removes the element at the top of the structure and returns it
        virtual T pop() = 0;
        //Pre: -
        //Post: returns true if the structure is empty
        virtual bool isEmpty() = 0;
        //Pre: -
        //Post: returns the number of elements the structure has
        virtual int getElementCount() = 0;
        //Pre: the structure is not empty
        //Post: Returns a new copy of the structure
        virtual Stack<T> *clone() = 0;
        //Pre: -
        //Post: prints the elements of the structure
        virtual void print()=0;
        //Pre: -
        //Post: Returns true if the structure has reached its max capacity
        virtual bool isFull() = 0;
        

     };

#endif