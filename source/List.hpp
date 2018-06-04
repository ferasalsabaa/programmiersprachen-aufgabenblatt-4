# ifndef BUW_LIST_HPP
# define BUW_LIST_HPP
# include <cstddef>
#include<iostream>
// List . hpp
template <typename T>
class List;
template <typename T>
struct ListNode
{
T value = T();
ListNode* prev = nullptr;
ListNode* next = nullptr;
};
template <typename T>
class ListIterator
{
public:
// not implemented yet
// do not forget about the initialiser lists !
private:
ListNode <T>* node;
};
template <typename T>
class ListConstIterator
{
public:
// not implemented yet
// do not forget about the initialiser lists !
private:
ListNode <T>* node ;
};
template <typename T>
class List
{
public:
using value_type      = T;
using pointer         = T*;
using const_ponter    = T const*;
using reference       = T&;
using const_reference = T const&;
using iterator        = ListIterator <T>;
using const_iterator  = ListConstIterator <T>;

List() :  size_{0} , first_{nullptr} , last_{nullptr}
{}
bool empty () const 
{
  return size_==0;
}
std :: size_t size () const 
{
    return size_;
}
void push_front (T const& wert)
{
    ListNode <T>* n_node = new ListNode<T>{wert,nullptr,nullptr};
    if(empty()==false)
    {
    first_->prev=n_node;
    n_node->next=first_;
    first_ = n_node;
    }
    else
    {
     first_=last_=n_node;
    }
    ++size_;
}
 T front ()
{
    return first_->value;
}
void push_back (T const& wert)
{
    ListNode <T>* n_node = new ListNode<T>{wert,nullptr,nullptr};
    if(empty()==false)
    {
      last_->prev=n_node;
      n_node->next=last_;
      last_ = n_node;
    }
    else
    {
      first_=last_=n_node;
    }
 ++size_;
}
T back ()
{
    return last_->value;
}
void pop_front()
{
  if(empty()==true)
  {
      std::cout<<"empty";
  }
  if(size()==1)
  {
      last_=first_=nullptr;
      --size_;
  }
  else
  {
     first_ = first_->next;
     first_->prev=nullptr;
    --size_;
  }
}
void pop_back()
{
    if(empty()==true)
    {
      std::cout<<"empty";
    }
    if(size()==1)
    {
      last_=first_=nullptr;
      --size_;
    }
    else
    {
        last_=last_->prev;
        last_->next=nullptr;
        --size_;
    }
}

// not implemented yet
// do not forget about the initialiser list !
private:
std::size_t size_;
ListNode <T>* first_;
ListNode <T>* last_;
};
#endif // # define BUW_LIST_HPP


