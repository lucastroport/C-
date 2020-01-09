#ifndef ORDLISTIMP_H
#define ORDLISTIMP_H

#include <iostream>
#include <stddef.h>
#include "NodeList.h"
#include "OrdList.h"
#include "BSTree.h"

using namespace std;

template <class T>
class OrdListImp : public OrdList<T> 
{
    private:
        BSTree<T> *root;
        int elements;

    public:
        OrdListImp(){
            this->root = NULL;
            this->elements = 0;
        }

        ~OrdListImp(){
            this->empty();
        }
        void empty(){
            this->emptyTree();
        }
        void emptyTree(){
            while(this->root != NULL){
                this->deleteMinNode(this->root);
            }
        }

        void deleteMinNode(BSTree<T>* &tree){
            if(tree != NULL){
                deleteMinNode(tree->left);
            }else{
                if(tree->reps > 1) tree->reps--;
                else{
                    delete tree;
                    tree = NULL;
                }
            }
        }

        void insert(T e){

            this->addToBSTree(this->root,e);
            this->elements++;
            
        }

        void addToBSTree(BSTree<T>* &tree,T e){
            
            if(tree == NULL){
                BSTree <T> *node = new BSTree<T>;
                node->data = e;
                node->left = node->right = NULL;
                node->reps = 1;
                tree = node;

            }else{

                if(e < tree->data) addToBSTree(tree->left,e);
                else if(e > tree->data) addToBSTree(tree->right,e);
                else tree->reps++;
            }
        }

        void removeElement(T e){
            this->removeFromBSTree(this->root,e);
            
        }

        void removeFromBSTree(BSTree<T>* &tree, T e){
            if(tree != NULL){

                if(e == tree->data){
                    
                    if(tree->reps > 1) tree->reps--;
                    else{
                        this->deleteNode(tree);
                    }
                    this->elements--;

                }else if (e < tree->data) removeFromBSTree(tree->left,e);
                else removeFromBSTree(tree->right,e);
            }
        }

        void deleteNode(BSTree<T>* &tree){

            if(tree != NULL){
                if(tree->left == NULL && tree->right == NULL){
                    delete tree;
                    tree = NULL;

                }else if(tree->left != NULL && tree->right != NULL){
                    BSTree<T>* nodeMax = this->searchMaxNode(tree->left);
                    tree->data = nodeMax->data;
                    tree->reps = nodeMax->reps;
                    this->deleteMaxNode(nodeMax);

                }else {
                    BSTree<T>* tmp = tree;

                    if(tree->left != NULL) tree = tree->left;
                    else if(tree->right != NULL) tree = tree->right;

                    delete tmp;
                }
            }
        }

         BSTree<T>* searchMaxNode(BSTree<T>* &tree){

             if(tree != NULL){
                if(tree->right != NULL) searchMaxNode(tree->right);
                else return tree;
             }
            return NULL;
                 
         }
        void deleteMaxNode(BSTree<T>* &tree){

            if(tree != NULL){
                deleteMaxNode(tree->right);
            }else{
                if(tree->reps > 1) tree->reps--;
                else{
                    delete tree;
                    tree = NULL;
                }
            }
        }


        bool isEmpty(){
            return this->elements == 0;
        }

        int size() {
            return this->elements;
        }

        bool exists(T e){
            return this->existsInBSTree(this->root, e);
        }

        bool existsInBSTree(BSTree<T>* tree, T e){
            if(tree != NULL){
                
                if(tree->data == e) return true;
                else if(tree->data > e) return existsInBSTree(tree->left,e);
                else if(tree->data < e) return existsInBSTree(tree->right,e);

                return existsInBSTree(tree->left,e) || existsInBSTree(tree->right,e);

            }
            return false;
        }

        OrdListImp<T> *clone() {
            OrdListImp<T>* ret = new OrdListImp<T>();
            ret->root = this->cloneTree(this->root);
            ret->elements = this->elements;
            return ret;
            

        }

        BSTree<T>* cloneTree(BSTree<T>* tree){
            if(tree == NULL) return NULL;
            else{
                BSTree<T>* a = new BSTree<T>;
                a->reps = tree->reps;
                a->data = tree->data;
                a->left = cloneTree(tree->left);
                a->right = cloneTree(tree->right);
                return a;
            }
        }
       
       void print(){
           OrdListImp<T>* copy = this->clone();
            this->printTree(copy->root);
       }

       void printTree(BSTree<T>* &tree){
           
            if(tree != NULL){
                printTree(tree->left);
                cout << tree->data<<" - ";
                printTree(tree->right);
            }
       }
};

#endif