#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "triangle.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Triangle& triangle);
TBinaryTreeItem(const TBinaryTreeItem& other);
Triangle& GetTriangle();
void SetTriangle(Triangle& triangle);
std::shared_ptr<TBinaryTreeItem> GetLeft();
std::shared_ptr<TBinaryTreeItem> GetRight();
void SetLeft(std::shared_ptr<TBinaryTreeItem> item);
void SetRight(std::shared_ptr<TBinaryTreeItem> item);
void SetTriangle(const Triangle& triangle);
void IncreaseCounter();
void DecreaseCounter();
int ReturnCounter();
virtual ~TBinaryTreeItem();

private:
Triangle triangle;
std::shared_ptr<TBinaryTreeItem> left;
std::shared_ptr<TBinaryTreeItem> right;
int counter;
};
#endif