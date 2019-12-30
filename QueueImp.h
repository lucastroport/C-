#ifndef QUEUEIMP_H
#define QUEUEIMP_H

#include <iostream>
#include <stddef.h>
#include "NodeList.h"
#include "Queue.h"
using namespace std;

template <class T>
class QueueImp : public Queue<T> 
{
    private:
        NodeList<T> *head;
        NodeList<T> *end;
        int elements;
    
    public:
        QueueImp(){
            this->head = this->end = NULL;
            this->elements = 0;
        }
        ~QueueImp(){
            this->empty();
        }

        void empty(){
            while(!this->isEmpty()) this->dequeue();
        }

        void enqueue(T e){
            NodeList<T>* node = new NodeList<T>;
            node->data = e;
            node->next = NULL;
            if(this->isEmpty()){
                node->prev = NULL;
                this->head = this->end = node;
            }else{
                node->prev = this->end;
                this->end->next = node;
                this->end = node;
            }
            this->elements++;

        }

        T dequeue(){
            T element = this->head->data;
            NodeList<T>* tmp = this->head;
            this->head = this->head->next;
            if (this->head != NULL) this->head->prev = NULL;
            delete tmp;
            if(this->head == NULL) this->end = NULL;
            this->elements--;

            return element;
        }

        bool isEmpty() { return this->elements == 0;}

        int getElementCount(){ return this->elements;}

        QueueImp<T> *clone(){
            QueueImp<T> *ret = new QueueImp<T>();
            NodeList<T>* tmp = this->head;

            while(tmp != NULL){
                ret->enqueue(tmp->data);
                tmp = tmp->next;
            }
            delete tmp;
            return ret;            
        }

        void print(){
            NodeList<T>* tmp = this->head;
            while(tmp != NULL) {
                cout << tmp->data;
                tmp = tmp->next;
                if (tmp != NULL) cout<<" - ";
            }
            delete tmp;
            cout<<endl;

        }


};


#endif