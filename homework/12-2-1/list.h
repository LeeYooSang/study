#include <iostream> 

 

using namespace std; 

 

template <class T> 

class Node { 

public: 	

	T data;

	Node<T>* next; 

};

 

 template <class T> 

class List { 

private: 	

	Node<T> * head; 	

	int size; 

public: 	

	List() : head(NULL) {}

	~List() {Node<T> *iter = head;

			while(iter!=NULL){

				iter = iter->next;

				delete head;

				head = iter;

			} 	

	} 		

	List(T* arr, int n_nodes):List() 

	{ 		

		head = new Node<T>;

		Node<T> *iter = head;

		for(int i = 0; i<n_nodes;i++){ 

			iter->data = arr[i];

			if(i == (n_nodes-1)){

				iter->next = NULL;

			} 			

			else{ 				

				iter->next = new Node<T>;

				iter = iter->next;

			} 		

		} 		

		this->size = n_nodes; 	

	} 		

	void insert_at (int idx, const T& data){ 		

		Node<T>* iter = this->head;

		Node<T>* new_node = new Node<T>;

		new_node->data = data; 		

		for(int i = 0;i<(idx-1);i++){ 

			iter = iter->next; 		

		} 		

		Node<T>* temp = iter->next; 	

		iter->next = new_node;

		new_node->next = temp;

		this->size += 1; 	

	} 		

	void remove_at(int idx){ 	

		Node<T>* delete_Node = new Node<T>; 

		Node<T>* next_Node = new Node<T>; 

		Node<T>* iter = this->head; 	

		for(int i=0;i<(idx-1);i++){ 	

			iter = iter->next; 	

		} 		

		delete_Node = iter->next;

		next_Node = delete_Node->next;

		iter->next = next_Node;

		delete delete_Node;

		this->size -=1; 	

	} 	

	void pop_back(){ 	

		Node<T>* iter = this->head; 

 		for(int i=0;i<(this->size-2);i++){ 	

			iter = iter->next; 	

		} 	

		delete iter->next; 	

		iter->next = NULL; 	

		this->size -=1; 	

	} 

	void push_back(const T& val){ 	

		Node<T>* iter = this->head; 

		Node<T>* new_node = new Node<T>; 

		new_node->data = val; 		

		new_node->next = NULL; 		

		for(int i = 0; i<(this->size-1);i++){ 	

			iter = iter->next; 		

		} 	

		iter->next = new_node; 	

		this->size += 1;	 

	} 		

	void pop_front(){ 

		Node<T>* iter = this->head; 

		Node<T>* front_Node = this->head; 	

		iter = iter->next; 	

		this->head = iter; 	

		delete front_Node; 	

		this->size -=1; 

	}

	void push_front(const T& val) { 	

		Node<T>* new_node = new Node<T>; 

		new_node->data = val; 		

		new_node->next = this->head; 

		this->head = new_node; 	

		this-> size += 1; 	

	} 	 

	friend ostream& operator<<(ostream& out, List& rhs){ 

		Node<T> * iter = rhs.head; 		

		while(iter != NULL){ 		

			out<<iter->data << " "; 

			iter = iter->next; 	

		} 		return out; 

	} 

};
