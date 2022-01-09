#include "TBinaryTreeItem.h"


template <class T>
TBinaryTreeItem<T>::TBinaryTreeItem(const T &triangle) {
    this->triag = triangle;
    this->left = NULL;
    this->right = NULL;
    this->counter = 1;
}

template <class T>
TBinaryTreeItem<T>::TBinaryTreeItem(const TBinaryTreeItem<T> &other) {
    this->triag = other.triag;
    this->left = other.left;
    this->right = other.right;
    this->counter = other.counter;
}

template <class T>
TBinaryTreeItem<T>::~TBinaryTreeItem() 
{}

template <class TT>
ostream& operator<<(ostream& os, TBinaryTreeItem<TT> tr)
{
    os << tr.triag << " ";
    return os;
}

#include "triangle.h"
template class TBinaryTreeItem<Triangle>;
template ostream& operator<<(ostream& os,  TBinaryTreeItem<Triangle> triangle);
