#ifndef ORDLIST_H
#define ORDLIST_H

template<class T>
class OrdList {
    public:

    /*Constructors*/
         OrdList(){}
         //Destructor
        virtual~OrdList(){}
        //Pre: -
        //Post: Empties the structure
        virtual void empty()=0;
        //Pre: -
        //Post: adds element e to the ordered list
        virtual void insert (T e) = 0;
        //Pre: The element exists
        //Post: searchs and removes the element e from the list
        virtual void removeElement(T e) = 0;
        //Pre: -
        //Post: returns true if the list is empty
        virtual bool isEmpty() = 0;
        //Pre: -
        //Post: returns true if the element e exists in the list
        virtual bool exists(T e) = 0;
        //Pre: -
        //Post: returns the number of elements the list has.
        virtual int size() = 0;
        //Pre: the structure is not empty
        //Post: Returns a new copy of the list
        virtual OrdList<T> *clone() = 0;
        //Pre: -
        //Post: prints the elements of the list
        virtual void print()=0;
     
 };
#endif