#include "triangle.h"
#include <iostream>
#include "TBinaryTree.h"
#include "TBinaryTreeItem.h"

int main () {
    Triangle a (std:: cin);
    std:: cout << "Area of a triangle:" << " " << a.Area() << std:: endl;

    Triangle b (std:: cin);
    std:: cout << "Area of a triangle:" << " " << b.Area() << std:: endl;

    Triangle c (std:: cin);
    std:: cout << "Area of a triangle:" << " " << c.Area() << std:: endl;


    TBinaryTree tree;
    std:: cout << "Is tree empty? " << tree.Empty() << std:: endl;
    tree.Push(a);
    std:: cout << "And now, is tree empty? " << tree.Empty() << std:: endl;
    tree.Push(b);
    tree.Push(c);
    std:: cout << "The number of figures with area in [minArea, maxArea] is: " << tree.Count(0, 100000) << std:: endl;
    std:: cout << "The result of searching the same-figure-counter is: " << tree.root->ReturnCounter() << std:: endl;
    std:: cout << "The result of function named GetItemNotLess is: " << tree.GetItemNotLess(0, tree.root) << std:: endl;
    std:: cout << tree << std:: endl;
    tree.root = tree.Pop(tree.root, a);
    std:: cout << tree << std:: endl;
    system("pause");

}


