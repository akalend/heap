#include <cstdio>
#include <cmath>
#include <iterator>
#include <memory>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <type_traits>

#include "heapiterator.h"


#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2



template <typename T> class Heap {

	public:
		Heap() {
			size = 0;
			elem = new Node<T>[size]();
		}

		Heap(const int size ) : size(size) {
			// this->size = size;
			elem = new Node<T>[size]();
		}


		Heap(const Heap<T>  &hp) : size( hp.size ) {
			elem = new Node<T>[size]();
			for(int i=0; i < size; i++) {
				elem[i] = hp.elem[i];
			}			
		}


		~Heap() {
			if (size) {
				delete[](elem);
			} else {
				delete(elem);
			}

		}

    typedef HeapIterator<T> iterator;
    typedef HeapIterator<T, true> const_iterator;

    

    iterator begin() {
	    return iterator( elem );
    }

    iterator end() {
    	return iterator( elem + size );
    }

    const_iterator cbegin() const {
	    return const_iterator( elem );
    }

    const_iterator cend() const {
    	return const_iterator( elem + size );
    }



/*   изменение значения узла
	
Heap_Increase_Key(A, i, key)
  if key < A[i]
    then error "Новый ключ меньше предыдущего"
  A[i] ← key
  while i > 1 и A[⌊i/2⌋] < A[i]
    do Обменять A[i] ↔ A[⌊i/2⌋]
      i ← ⌊i/2⌋
*/

		void changeNode( int idx, T data) {

			if ( data <  elem[idx].getData() ) {
				printf("error new key less pred\n");
			} else {
				Node<T> nd(data); 
				elem[idx] = nd;
				while ( idx  && elem[PARENT(idx)].getData() < elem[idx].getData() ) {
					swap( &elem[idx], &elem[PARENT(idx)] );
					idx = PARENT(idx);
				}				
			}
		}

/*
		    всставка узла
	Heap_Insert(A, key)
  	A.heap_size ← A.heap_size+1
  	A[A.heap_size] ← -∞
  	Heap_Increase_Key(A, A.heap_size, key)
*/
		void push_back( T data) {

		    if(size) {

 				//  перераспределение  памяти
		       	Node<T>* tmp = new Node<T>[size+1]();
				for(int i=0; i < size; i++) {
					tmp[i] = elem[i];
				}
		    	delete[](elem);
		    	elem = tmp;

			    Node<T> nd(data);
			    int i = size++;

			    // Node<T> parent( elem[PARENT(i)].getData() );

			    while( i && nd.getData() >= elem[PARENT(i)].getData()) {

			        elem[i] = elem[PARENT(i)] ;
			        i = PARENT(i) ;
			    }

			    elem[i] = nd;

		    } else {
		        elem = new Node<T>(data);
		        size = 1;
		    }

		}


/*
		    удавление узла
		    Heap_Extract_Max(A)
		  if A.heap_size[A] < 1
		    then error "Куча пуста"
		  max ← A[1]
		  A[1] ← A[A.heap_size]
		  A.heap_size ← A.heap_size-1
		  Heapify(A, 1)
		  return max
*/
		T pop() {
		    if(!size) {
		        printf("\nHeap is empty!\n");
		        return -1;
		    }
		
			T result = elem[0].getData();
			Node<T> minNode(-9999);
			
	        //min элемент 
	        elem[0] = elem[--size];
	        

	       	Node<T>* tmp = new Node<T>[size]();
			for(int i=0; i < size; i++) {
				tmp[i] = elem[i];
			}
	    	delete[](elem);
	    	elem = tmp;	

			int index = 0, next_index = 0;

			for (;;) {

				if (LCHILD(index) < size && elem[0].getData() > elem[LCHILD(index)].getData()  ) {

					if (RCHILD(index) < size && elem[RCHILD(index)].getData() > elem[LCHILD(index)].getData()) {
						next_index = LCHILD(index);
					} else {
						next_index = RCHILD(index);
					}

				} else if ( RCHILD(index) < size && elem[0].getData() > elem[RCHILD(index)].getData() ) {

					next_index = next_index = RCHILD(index);

				} else {
					elem[index] = elem[0];
					break;
				}

				/* Swap the current node with the least of the child nodes. */

				elem[index] = elem[next_index];
				index = next_index;
			}

	    return result;
	}


		void levelorderTraversal() {
		    
		    for(int i = 0; i < size; i++) {
		        printf("%d[%d] ", elem[i].getData(), i) ;
		    }
		    printf("\n");
		}


	private:
		int size ;
		Node<T> *elem;
		


		void swap(Node<T> *n1, Node<T> *n2) {
		    Node<T> temp = *n1 ;
		    *n1 = *n2 ;
		    *n2 = temp ;
		}

/*
Build_Heap(A)
  A.heap_size ← A.length
  for i ← ⌊A.length/2⌋ downto 1
    do Heapify(A, i)
*/
void buildMinHeap( T *arr, int size) {
    
    this.size = size;
	if (this.size) {
		delete[](elem);
	} else {
		 delete(elem);
	}

    if(size) {
        elem = new Node<T>[size+1]();
    } else {
        elem = new Node<T>[0]();
    }

    for(int i = 0; i < size; i++) {
        Node<T> nd( arr[i] );
    }

    // Making sure that heap property is also satisfied
    for(int i = (this.size - 1) / 2; i >= 0; i--) {
        heapify(i);
    }
}



/*
Heapify(A, i)
  left ← 2i
  right ← 2i+1
  heap_size - количество элементов в куче
  largest ← i
  if left ≤ A.heap_size и A[left] > A[largest]
    then largest ← left
  if right ≤ A.heap_size и A[right] > A[largest]
    then largest ← right
  if largest ≠ i
    then Обменять A[i] ↔ A[largest]
         Heapify(A, largest)*/

	void heapify( int level) {
	  
	  	int largest = level;

	    if( LCHILD( level) <= size && elem[LCHILD(level)].getData() > elem[largest].getData() ) {
	        largest = LCHILD(level);
	    }

	    if ( RCHILD( level) <= size && elem[RCHILD(level)].getData() > elem[ level ].getData() ) {
	    	largest = RCHILD(level);	
	    }  

	    if(largest != level) {
	        swap(&elem[level], &elem[largest]) ;
	        heapify(largest) ;
	    }
	} 
}; 

