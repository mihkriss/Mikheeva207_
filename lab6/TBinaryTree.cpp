#include "TBinaryTree.h"
using namespace std;

template <class T>
TBinaryTree<T>::TBinaryTree() : root(NULL)
{}

template <class T>
void print_tree(ostream& os, shared_ptr <TBinaryTreeItem<T>> root)
{
    if (!root)
    {
        return;
    }
    if (root->left)
    {
        os << root->counter << "*" << root->triag.GetArea() << ": [";
        print_tree(os, root->left);
        if (root->right)
        {
            os << ", ";
            print_tree(os, root->right);
        }
        os << "]";
    } 
    else if (root->right)
    {
       os << root->counter << "*" << root->triag.GetArea() << ": [";
        print_tree(os, root->right);
        if (root->left) 
        {
            os << ", ";
            print_tree(os, root->left);
        }
        os << "]";
    }
    else
    {
        os << root->counter << "*" << root->triag.GetArea();
    }
}

template <class TT>
std::ostream& operator << (ostream& os, const TBinaryTree<TT>& tree)
{
    print_tree(os, tree.root);
    os;
    return os;
}

template <class T>
void TBinaryTree<T>::Push(const T &tr) 
{
    T triangle = tr;
    if (root == NULL) 
    {
        shared_ptr <TBinaryTreeItem<T>> c(new TBinaryTreeItem<T>(t));
        root = c;
    }
    else if (root->triag.GetArea() == t.GetArea()) 
    {
        root->counter++;
    }
    else 
    {
        shared_ptr<TBinaryTreeItem<T>> parent = root;
        shared_ptr<TBinaryTreeItem<T>> currentur;
        bool childInLeft = true;
        if (t.GetArea() < parent->triag.GetArea()) 
        {
            current = root->left;
        }
        else if (t.GetArea() > parent->triag.GetArea()) 
        {
            current = root->right;
            childInLeft = false;
        }
        while (current != NULL) 
        {
            if (current->triag == t) 
            {
                current->counter++;
            }
            else 
            {
                if (t.GetArea() < current->triag.GetArea()) 
                {
                    parent = current;
                    current = parent->left;
                    childInLeft = true;
                }
                else if (t.GetArea() > current->triag.GetArea()) 
                {
                    parent = current;
                    current = parent->right;
                    childInLeft = false;
                }
            }
        }
        shared_ptr<TBinaryTreeItem<T>> c(new TBinaryTreeItem<T>(t));
        current = c;
        if (childInLeft == true)
        {
            parent->left = current;
        }
        else 
        {
            parent->right = current;
        }
    }
}

template <class T>
shared_ptr<TBinaryTreeItem<T>> __Pop(shared_ptr<TBinaryTreeItem<T>> root)
{
    if (root->left == NULL) 
    {
        return root;
    }
    return __Pop(root->left);
}

template <class T>
shared_ptr<TBinaryTreeItem<T>> _Pop(shared_ptr<TBinaryTreeItem<T>> root, T &t)
{
    if (root == NULL) 
    {
        return root;
    }
    else if (triangle.GetArea() < root->triag.GetArea()) 
    {
        root->left = _Pop(root->left, triangle);
    }
    else if (t.GetArea() > root->triag.GetArea()) 
    {
        root->right = _Pop(root->right, triangle);
    }
    else 
    {
        if (root->left == NULL && root->right == NULL) 
        {
            if (root->counter > 1)
            {
                --root->counter;
                return root;
            }
            root = NULL;
            return root;
        }
        else if (root->left == NULL && root->right != NULL) 
        {
            if (root->counter > 1)
            {
                --root->counter;
                return root;
            }
            root = root->right;
            root->right = NULL;
            return root;
        }
        else if (root->right == NULL && root->left != NULL) 
        {
            if (root->counter > 1)
            {
                --root->counter;
                return root;
            }
            root = root->left;
            root->left = NULL;
            return root;
        }
        else 
        {
            shared_ptr<TBinaryTreeItem<T>> childInLeft = __Pop(root->right);
            root->triag.A = childInLeft->triag.GetArea();
            root->right = _Pop(root->right, childInLeft->triag);
        }
    }
    return root;
}

template <class T>
void TBinaryTree<T>::Pop(const T &t)
{
    T tr = triangle;
    root = _Pop(root, tr);
}

template <class T>
unsigned _Count(shared_ptr<TBinaryTreeItem<T>> current, unsigned res, T& triangle)
{
    if (current != NULL) 
    {
        _Count(current->left, res, triangle);
        _Count(current->right, res, triangle);
        if (current->triag.GetArea() == triangle.GetArea()) 
        {
            return current->counter;
        }
    }
    return 0;
}

template <class T>
size_t TBinaryTree<T>::Count(const T& triangle)
{
    T tr = triangle;
    return _Count(root, 0, tr);
}

template <class T>
T& _GetItemNotLess(double area, shared_ptr<TBinaryTreeItem<T>> root)
{
    if (root->triag.GetArea() >= area)
    {
        return root->triag;
    }
    else
    {
        _GetItemNotLess(area, root->right);
    }
}

template <class T>
const T& TBinaryTree<T>::GetItemNotLess(double area)
{
    return _GetItemNotLess(area, root);
}

template <class T>
void _Clear(shared_ptr<TBinaryTreeItem<T>> current)
{
    if (current!= NULL)
    {
        _Clear(current->left);
        _Clear(current->right);
        current = NULL;
    }
}

template <class T>
void TBinaryTree<T>::Clear()
{
    _Clear(root);
    root = NULL;
}

template <class T>
bool TBinaryTree<T>::Empty()
{
    return (root == NULL);
}

template <class T>
TBinaryTree<T>::~TBinaryTree()
{
    Clear();
}

template class TBinaryTree<Triangle>;
template ostream& operator<<(ostream& os, const TBinaryTree<Triangle>& tr);
