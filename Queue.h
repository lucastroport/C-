#ifndef QUEUE_H
#define QUEUE_H

 template<class T>
     class Queue{
      public:
         /*Constructors*/
         Queue(){}
         //Destructor
        virtual~Queue(){}
        //Pre: -
        //Post: Empties the structure
        virtual void empty()=0;
        //Pre: -
        //Post: Adds an element at the end of the structure
        virtual void enqueue (T e) = 0;
        //Pre: the structure is not empty
        //Post: Removes the element at the end of the structure and returns it
        virtual T dequeue() = 0;
        //Pre: -
        //Post: returns true if the structure is empty
        virtual bool isEmpty() = 0;
        //Pre: -
        //Post: returns the number of elements the structure has
        virtual int getElementCount() = 0;
        //Pre: the structure is not empty
        //Post: Returns a new copy of the structure
        virtual Queue<T> *clone() = 0;
        //Pre: -
        //Post: prints the elements of the structure
        virtual void print()=0;
     };
#endif