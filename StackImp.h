
#ifndef STACKIMP_H
#define STACKIMP_H

#include <iostream>
#include <stddef.h>
#include "NodeList.h"
#include "Stack.h"
using namespace std;

template <class T>
class StackImp : public Stack<T> 
{
    private:
        NodeList<T> *head;
        NodeList<T> *end;
        int elements;
        int maxCap;

    public:
        
        StackImp(){
            this->head = this->end = NULL;
            this->elements = 0;
            this->maxCap = INT_MAX;
        }
       ~StackImp(){
           this->empty();
       }

       StackImp(int n){
            this->head = this->end = NULL;
            this->elements = 0;
            this->maxCap = n;
        }

       void empty(){
           while(!this->isEmpty()) {this->pop();}
       }
        
        
        void push (T e){
            if(!this->isFull()){//We only add an element at the top of the stack if is not full.
                NodeList<T>* node = new NodeList<T>;
                node->prev = NULL;
                node->data = e;
                if(isEmpty()){
                    node->next = NULL;
                    this->head = this->end = node;
                }else{
                    node->next = this->head;
                    this->head->prev = node;
                    this->head = node;
                }
                this->elements++;
            }
        }
        
        T pop(){
            T element = this->head->data;
            NodeList<T>* tmp = this->head;
            this->head = this->head->next;
            if(this->head != NULL) this->head->prev = NULL;
            delete tmp;
            if(this->head == NULL) this->end = NULL;//In case it was the only node left
            this->elements--;

            return element;
        }

        bool isEmpty() {return this->elements == 0;}
        
        int getElementCount(){return this->elements;}
        
        StackImp<T> *clone(){
            StackImp<T> *ret = new StackImp<T>();
            NodeList<T>* tmp = this->end;
            while(tmp != NULL){
                ret->push(tmp->data);
                tmp = tmp->prev;
            }
            delete tmp;
            return ret;
        }
        
        void print(){
                StackImp<T>* tmp = this->clone();
                while(!tmp->isEmpty()){
                    cout << tmp->pop();
                    if(!tmp->isEmpty()) cout << " - ";
                }
                delete tmp;
                cout<<endl;
        
        }
            
        
        bool isFull(){return this->elements == this->maxCap;}
};

#endif


