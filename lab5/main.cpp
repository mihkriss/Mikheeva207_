#include <iostream>
#include "triangle.h"
#include "TBinaryTree.h"
#include "TBinaryTreeItem.h"
int main () {
    
    Triangle a (std::cin);
    std:: cout << "The area of your figure is : " << a.Area() << std:: endl;

    Triangle b (std::cin);
    std:: cout << "The area of your figure is : " << b.Area() << std:: endl;

    Triangle c (std::cin);
    std:: cout << "The area of your figure is : " << c.Area() << std:: endl;


    //lab2
    TBinaryTree<Triangle> tree;
    std:: cout << "Is tree empty? " << tree.Empty() << std:: endl;
    tree.Push(a);
    std:: cout << "And now, is tree empty? " << tree.Empty() << std:: endl;
    tree.Push(b);
    tree.Push(c);
    std:: cout << "The number of figures with area in [minArea, maxArea] is: " << tree.Count(0, 100000) << std:: endl;
    std:: cout << "The result of searching the same-figure-counter is: " << tree.root->ReturnCounter() << std:: endl;
    std:: cout << "The result of function named GetItemNotLess is: " << tree.GetItemNotLess(0, tree.root) << std:: endl;

    //lab5
    TIterator<TBinaryTreeItem<Triangle, Triangle> iter(tree.root);
    std:: cout << "The figure that you have put in root is: " << *iter << std:: endl;
    iter.GoToLeft();
    std:: cout << "The first result of Left-Iter function is: " << *iter << std:: endl;
    iter.GoToRight();
    std:: cout << "The first result of Right-Iter function is: " << *iter << std:: endl;
    TIterator<TBinaryTreeItem<Triangle>, Triangle> first(tree.root->GetLeft());
    TIterator<TBinaryTreeItem<Triangle>, Triangle> second(tree.root->GetLeft());
    if (first == second) {
        std:: cout << "YES, YOUR ITERATORS ARE EQUALS" << std::endl;
    }
    TIterator<TBinaryTreeItem<Triangle>, Triangle third(tree.root->GetRight());
    TIterator<TBinaryTreeItem<Triangle>, Triangle> fourth(tree.root->GetLeft());
    if (third != fourth) {
        std:: cout << "NO, YOUR ITERATORS ARE NOT EQUALS" << std::endl;
    }
    return 0;
}