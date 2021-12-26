#include <iostream>
#include "triangle.h"
#include "TLinkedList.h"
#include "TLinkedListItem.h"
#include "TAllocatorBlock.h"

int main () {
    Triangle a (std:: cin);
    std:: cout << "Area of a triangle:" << " " << a.Area() << std:: endl;

    Triangle b (std:: cin);
    std:: cout << "Area of a triangle:" << " " << b.Area() << std:: endl;

    Triangle c (std:: cin);
    std:: cout << "Area of a triangle:" << " " << c.Area() << std:: endl;

  //lab8
    TLinkedList list;
    std:: cout << "Is list empty? " << list.Empty() << std:: endl;
    list.InsertFirst(a);
    std:: cout << "And now, is tree empty? " << list.Empty() << std:: endl;
    list.InsertLast(b);
    list.InsertLast(c);
    std:: cout << "The length of your list is: " << list.Length() << std:: endl;
    std:: cout << list;
    return 0;
}




