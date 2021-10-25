#ifndef TBINARYTREE_H
#define TBINARYTREE_H
#include "TBinaryTreeItem.h"

class TBinaryTree {
public:
TBinaryTree();
TBinaryTree(const TBinaryTree &other);
void Push(Triangle &triangle);
TBinaryTreeItem* Pop(TBinaryTreeItem* root, Triangle &triangle);
Triangle& GetItemNotLess(double area, TBinaryTreeItem* root);
void Clear();
bool Empty();
int Count(double minArea, double maxArea);
friend std::ostream& operator<<(std::ostream& os, TBinaryTree& tree);
virtual ~TBinaryTree();
TBinaryTreeItem *root;
};
#endif