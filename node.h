#ifndef Node_H
#define Node_H

template <typename T> class Node {
	
	public:		
		Node<T>( T _data ){  
			data = _data;
		};


		Node<T>(){};

		T getData(){
			return data;
		}

		void setData( T _data ){
			data = _data;			
		}


		const T& operator=(const T& rv) const {
        	data = rv.getData();
    	}

		bool operator>( const Node<T>& rv) const {
        	return (data > rv.getData());
     	}

		bool operator>=( const Node<T>& rv)  const {
        	return (data >= rv.getData());
     	}

		bool operator<( const Node<T>& rv)  const {
        	return (data < rv.getData());
     	}

	private:
		T data;
};



#endif // Node_H