#ifndef BSTREE_H
#define BSTREE_H

template <class T>
class BSTree{
    public:
        BSTree *left;
        BSTree *right;
        T data;
        unsigned int height;
        unsigned int reps;

        BSTree(const T &e) : data(e), left(NULL), right(NULL),height(0),reps(0){}
        BSTree() : left(NULL), right(NULL),height(0),reps(0){}
};      



#endif