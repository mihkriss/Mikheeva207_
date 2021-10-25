#include "TBinaryTree.h"

TBinaryTree::TBinaryTree () {
    root = NULL;
}

std::shared_ptr<TBinaryTreeItem> copy (std::shared_ptr<TBinaryTreeItem> root) {
    if (!root) {
        return NULL;
    }
    std::shared_ptr<TBinaryTreeItem> root_copy(new TBinaryTreeItem (root->GetTriangle()));
    root_copy->SetLeft(copy(root->GetLeft()));
    root_copy->SetRight(copy(root->GetRight()));
    return root_copy;
}

TBinaryTree::TBinaryTree (const TBinaryTree &other) {
    root = copy(other.root);
}

void Print (std::ostream& os, std::shared_ptr<TBinaryTreeItem> node){
    if (!node){
        return;
    }
    if(node->GetLeft()){
        os << node->GetTriangle().GetArea() << ": [";
        Print (os, node->GetLeft());
        if (node->GetRight()){
            if (node->GetRight()){
                os << ", ";
                Print (os, node->GetRight());
            }
        }
        os << "]";
    } else if (node->GetRight()) {
       os << node->GetTriangle().GetArea() << ": [";
        Print (os, node->GetRight());
        if (node->GetLeft()){
            if (node->GetLeft()){
                os << ", ";
                Print (os, node->GetLeft());
            }
        }
        os << "]";
    }
    else {
        os << node->GetTriangle().GetArea();
    }
}

std::ostream& operator<< (std::ostream& os, TBinaryTree& tree){
    Print(os, tree.root);
    os << "\n";
}

void TBinaryTree::Push (Triangle &triangle) {
    if (root == NULL) {
    std::shared_ptr<TBinaryTreeItem> help(new TBinaryTreeItem(triangle));
    root = help;
    }
    else if (root->GetTriangle() == triangle) {
        root->IncreaseCounter();
    }
    else {
        std::shared_ptr<TBinaryTreeItem> parent = root;
        std::shared_ptr<TBinaryTreeItem> current;
        bool childInLeft = true;
        if (triangle.GetArea() < parent->GetTriangle().GetArea()) {
            current = root->GetLeft();
        }
        else if (triangle.GetArea() > parent->GetTriangle().GetArea()) {
            current = root->GetRight();
            childInLeft = false;
        }
        while (current != NULL) {
            if (current->GetTriangle() == triangle) {
                current->IncreaseCounter();
            }
            else {
            if (triangle.GetArea() < current->GetTriangle().GetArea()) {
                parent = current;
                current = parent->GetLeft();
                childInLeft = true;
                }
            else if (triangle.GetArea() > current->GetTriangle().GetArea()) {
                parent = current;
                current = parent->GetRight();
                childInLeft = false;
            }
        }
    }
        std::shared_ptr <TBinaryTreeItem> item (new TBinaryTreeItem(triangle));
        current = item;
        if (childInLeft == true) {
            parent->SetLeft(current);
        }
        else {
            parent->SetRight(current);
        }
    }
}

 std::shared_ptr<TBinaryTreeItem> FMRST (std::shared_ptr<TBinaryTreeItem> root) {
    if (root->GetLeft() == NULL) {
        return root;
    }
    return FMRST(root->GetLeft());
}

std::shared_ptr <TBinaryTreeItem> TBinaryTree:: Pop(std::shared_ptr <TBinaryTreeItem> root, Triangle &triangle) {
    if (root == NULL) {
        return root;
    }
    else if (triangle.GetArea() < root->GetTriangle().GetArea()) {
        root->SetLeft(Pop(root->GetLeft(), triangle));
    }
    else if (triangle.GetArea() > root->GetTriangle().GetArea()) {
        root->SetRight(Pop(root->GetRight(), triangle));
    }
    else {
        //first case of deleting - we are deleting a list
        if (root->GetLeft() == NULL && root->GetRight() == NULL) {
            root = NULL;
            return root;
        }
        //second case of deleting - we are deleting a verex with only one child
        else if (root->GetLeft() == NULL && root->GetRight() != NULL) {
            std::shared_ptr <TBinaryTreeItem> pointer = root;
            root = root->GetRight();
            return root;
        }
        else if (root->GetRight() == NULL && root->GetLeft() != NULL) {
            std::shared_ptr <TBinaryTreeItem> pointer = root;
            root = root->GetLeft();
            return root;
        }
        //third case of deleting 
        else {
            std::shared_ptr <TBinaryTreeItem> pointer = FMRST(root->GetRight());
            root->GetTriangle().area = pointer->GetTriangle().GetArea();
            root->SetRight(Pop(root->GetRight(), pointer->GetTriangle()));
        }
    }
}

void RecursiveCount(double minArea, double maxArea, std::shared_ptr <TBinaryTreeItem> current, int& ans) {
    if (current != NULL) {
        RecursiveCount(minArea, maxArea, current->GetLeft(), ans);
        RecursiveCount(minArea, maxArea, current->GetRight(), ans);
        if (minArea <= current->GetTriangle().GetArea() && current->GetTriangle().GetArea() < maxArea) {
            ans += current->ReturnCounter();
        }
    }
}

int TBinaryTree::Count(double minArea, double maxArea) {
    int ans = 0;
    RecursiveCount(minArea, maxArea, root, ans);
    return ans;
}

Triangle& TBinaryTree::GetItemNotLess(double area, std::shared_ptr <TBinaryTreeItem> root) {
    if (root->GetTriangle().GetArea() >= area) {
        return root->GetTriangle();
    }
    else {
        GetItemNotLess(area, root->GetRight());
    }
}

void RecursiveClear(std::shared_ptr <TBinaryTreeItem> current){
    if (current!= NULL){
        RecursiveClear(current->GetLeft());
        RecursiveClear(current->GetRight());
            current = NULL;
    }
}

void TBinaryTree::Clear(){
    RecursiveClear(root);
    root = NULL;
}

bool TBinaryTree::Empty() {
     if (root == NULL) {
         return true;
     }
     return false;
}

TBinaryTree::~TBinaryTree() {
    Clear();
    std:: cout << "Your tree has been deleted" << std:: endl;
}