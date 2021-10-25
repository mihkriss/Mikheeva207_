#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "triangle.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Triangle& triangle);
TBinaryTreeItem(const TBinaryTreeItem& other);
Triangle& GetTriangle();
void SetTriangle(Triangle& triangle);
TBinaryTreeItem* GetLeft();
TBinaryTreeItem* GetRight();
void SetLeft(TBinaryTreeItem* item);
void SetRight(TBinaryTreeItem* item);
void SetTriangle(const Triangle& triangle);
void IncreaseCounter();
void DecreaseCounter();
int ReturnCounter();
virtual ~TBinaryTreeItem();

private:
Triangle triangle;
TBinaryTreeItem *left;
TBinaryTreeItem *right;
int counter;
};
#endif