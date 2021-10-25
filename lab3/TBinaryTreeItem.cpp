#include "TBinaryTreeItem.h"


TBinaryTreeItem::TBinaryTreeItem(const Triangle &triangle) {
    this->triangle = triangle;
    this->left = this->right = NULL;
    this->counter = 1;
}

TBinaryTreeItem::TBinaryTreeItem(const TBinaryTreeItem &other) {
    this->triangle = other.triangle;
    this->left = other.left;
    this->right = other.right;
    this->counter = other.counter;
}

Triangle& TBinaryTreeItem::GetTriangle() {
    return this->triangle;
}

void TBinaryTreeItem::SetTriangle(const Triangle& triangle){
    this->triangle = triangle;
}
std::shared_ptr<TBinaryTreeItem> TBinaryTreeItem::GetLeft(){
    return this->left;
}
std::shared_ptr<TBinaryTreeItem> TBinaryTreeItem::GetRight(){
    return this->right;
}


void TBinaryTreeItem::SetLeft(std::shared_ptr<TBinaryTreeItem> item) {
    if (this != NULL){
        this->left = item;
    }
}

void TBinaryTreeItem::SetRight(std::shared_ptr<TBinaryTreeItem> item) {
    if (this != NULL){
        this->right = item;
    }
}

void TBinaryTreeItem::IncreaseCounter() {
    if (this != NULL){
        counter++;
    }
}
void TBinaryTreeItem::DecreaseCounter() {
    if (this != NULL){
        counter--;
    }
}

int TBinaryTreeItem::ReturnCounter() {
    return this->counter;
}

TBinaryTreeItem::~TBinaryTreeItem() {
}


