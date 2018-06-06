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
using Self = ListIterator<T>;
using value_type = T;
using pointer = T*;
using reference = T&;
using difference_type = ptrdiff_t;
using iterator_category = std::bidirectional_iterator_tag;

ListIterator() : node{nullptr}
{}         // not implemented yet ; initialisierlist ?
ListIterator (ListNode <T>* n) : node{n}
{} // not implemented yet ; initialiserlist ?
reference operator*() const
 {
     return node->value;   //value
 } // not implemented yet
 
pointer operator->() const 
{
    return &(node->value);    //adresse
} // not implemented yet


Self& operator++() 
{
    node = node->next;
    return *this;  //iterator von node
} // not implemented yet
Self operator++(int) 
{
    Self result = *this;
    ++(*this);
    return result;
} // not implemented yet
bool operator==(Self const& x) const
 {
     return node == x.getnode();
 } // not implemented yet
bool operator!=(Self const& x) const
 {
     return node != x.getnode();
 } // not implemented yet
Self next () const
{
if ( node )
return ListIterator ( node -> next );
else
return ListIterator ( nullptr );
}
ListNode <T>* getnode() const
{
    return node;
} //pointer auf node haben


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
~List()
{
    clear();
}
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
void clear()
{
    
        while(first_!=nullptr && last_!=nullptr)
        {
            pop_back();
        }
    
}
//4.6
iterator begin() const
{
  return ListIterator<T>(first_);
}
iterator end() const
{
   return ListIterator<T>();
}

// not implemented yet
// do not forget about the initialiser list !
private:
std::size_t size_;
ListNode <T>* first_;
ListNode <T>* last_;
};

template <typename T>
bool operator ==( List <T> const& xs , List <T> const& ys ) //const methode mussen .. 
{    bool result=true;
     if(xs.size()==ys.size())
     {
        auto x = xs.begin();
        auto y = ys.begin();
        for(unsigned int i=0;i<xs.size();++i)
        {
            if(*x!=*y)
            {
                result = false;
                break; //..
            }
            ++x;
            ++y;
        }
     }

     return result;
}
template <typename T>
bool operator !=( List <T > const& xs , List <T > const& ys )
{
     bool result=true;
    if (xs.size()==ys.size())
    {
      auto x = xs.begin();
      auto y = ys.begin();
      for(unsigned int i=0;i<xs.size();i++)
      {
        if(*x==*y)
        {
            result = false;
            break;
        }
        ++x;
        ++y;
      }
    }
    else
    {
        result=true;
    }
    return result;
}
#endif // # define BUW_LIST_HPP


