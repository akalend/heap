#ifndef HeapIterator_H
#define HeapIterator_H

#include <iterator>
#include <initializer_list>

#include "node.h"

class OwnContainer;

template<typename T>
class HeapIterator: public std::iterator<std::input_iterator_tag, T>
{
    friend class Heap;
private:
    HeapIterator(T* p);
public:
    HeapIterator(const HeapIterator &it);

    bool operator!=(HeapIterator const& other) const;
    bool operator==(HeapIterator const& other) const; //need for BOOST_FOREACH
    typename HeapIterator::reference operator*() const;
    HeapIterator& operator++();
private:
    // T* p;
    Node<T>* p;
};

template<typename T>
HeapIterator< Node<T> >::HeapIterator( Node<T> *p) : p(p)
{ }


// template<typename T>
// HeapIterator<T>::HeapIterator(const HeapIterator& it) :p(it.p)
// { }

// template<typename T>
// bool HeapIterator<T>::operator!=(HeapIterator const& other) const
// {
//     return p != other.p;
// }

// template<typename T>
// bool HeapIterator<T>::operator==(HeapIterator const& other) const
// {
//     return p == other.p;
// }

// template<typename T>
// typename HeapIterator<T>::reference HeapIterator<T>::operator*() const
// {
//     return *p;
// }

// template<typename T>
// HeapIterator<T> &HeapIterator<T>::operator++()
// {
//     ++p;
//     return *this;
// }

#endif // HeapIterator_H
