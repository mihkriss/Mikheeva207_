
#ifndef HLISTITEM_H
#define HLISTITEM_H
#include <iostream>
#include "triangle.h"
#include <memory>

template <class T> class HListItem {
public:
  HListItem(const std::shared_ptr<Triangle> &triangle);
  template <class A> friend std::ostream& operator<<(std::ostream& os, HListItem<A> &obj);
  ~HListItem();
  std::shared_ptr<T> triangle;
  std::shared_ptr<HListItem<T>> next;
};
#include "HListItem.cpp"
#endif
