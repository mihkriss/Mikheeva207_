#ifndef TITERATOR_H
#define TITERATOR_H

#include <memory>
#include "TBinaryTreeItem.h"
#include "TBinaryTree.h"

template <class Root, class T>
class TIterator
{
private:
    std::shared_ptr<Root> root;

public:
    TIterator(std::shared_ptr<Root> n)
    {
        root = n;
    }
    T& operator*() {
        return root->triag;
    }
    void Left()
    {
        if (root == NULL) {
            return;
        }
        root = root->left;
    }
    void Right()
    {
        if (root == NULL) {
            return;
        }
        root = root->right;
    }
    bool operator== (TIterator &i) {
        return root == i.root;
    }

    bool operator!= (TIterator &i) {
        return !(root == i.root);
    }
   
};
#endif