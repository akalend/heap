#ifndef HeapIterator_H
#define HeapIterator_H

#include <iterator>
#include <initializer_list>

#include "node.h"

template <typename T> class Heap;

template<typename T, bool is_const_iterator = false>
class HeapIterator: public std::iterator<std::input_iterator_tag, T>
{
    using data_ptr_t = Node<T>*;    
    using reference_t = std::conditional_t<is_const_iterator, typename std::add_const_t<T>, T&>;
    
    data_ptr_t p;
    
    friend class Heap<T>;

    HeapIterator(data_ptr_t ptr) : p(ptr) {}

public:
    HeapIterator(const HeapIterator &it) : p( it.p ){}


    bool operator!=(HeapIterator const& other) const { return p != other.p; }
    bool operator==(HeapIterator const& other) const { return p == other.p; }
    reference_t operator*() const { return p->getData(); }
    HeapIterator& operator++() {++p; return *this;}

    // const T& operator=(const T& rv) const {
 //         rv.push_back( p->getData() );
 //         return this;
 //    }

};



#endif // HeapIterator_H
