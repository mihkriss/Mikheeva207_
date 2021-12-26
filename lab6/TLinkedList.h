#ifndef HLIST_H
#define HLIST_H
#include <iostream>
#include "HListItem.h"
#include "triangle.h"
#include <memory>

template <class T> class TLinkedList {
public:
  TLinkedList();
  int size_of_list;
  size_t Length();
  std::shared_ptr<Triangle>& First();
  std::shared_ptr<Triangle>& Last();
  std::shared_ptr<Triangle>& GetItem(size_t idx);
  bool Empty();
  TLinkedList(const std::shared_ptr<TLinkedList> &other);
  void InsertFirst(const std::shared_ptr<Triangle> &&triangle);
  void InsertLast(const std::shared_ptr<Triangle> &&triangle);
  void RemoveLast();
  void RemoveFirst();
  void Insert(const std::shared_ptr<Triangle> &&triangle, size_t position);
  void Remove(size_t position);
  void Clear();
  template <class A> friend std::ostream& operator<<(std::ostream& os, TLinkedList<A>& list);
  ~TLinkedList(); 
private:
  std::shared_ptr<HListItem<T>> front;
  std::shared_ptr<HListItem<T>> back;
};
#include "TLinkedList.cpp"
#endif 
