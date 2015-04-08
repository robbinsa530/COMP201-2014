#ifndef _LISTS_H
#define _LISTS_H
#include <iostream>

template <typename T> 
class Node {
public: 
	Node(T d, Node * n, Node * p) {data = d; next = n; prev = p;}
	
	T data;
	Node * next;
	Node * prev;
};

 template <typename T>
 class List {
public:
	List() {
		head = NULL;
		tail = NULL;
		}
	void push_front(T element) {
		Node<T> * node = new Node<T>(element, head, NULL);
		if (head != NULL) {head->prev = node;}
		if (head == NULL) {tail = node;}
		head = node;
	}	
	void push_back(T element) {
		Node<T> * node = new Node<T>(element, NULL, tail);
		if (tail != NULL) {tail->next = node;}
		if (tail == NULL) {head = node;}
		tail = node;
	}
	void pop_back() {
		Node<T> * node;
		node = tail->prev;
		delete tail;
		tail = node;
		if (tail != NULL) {tail->next = NULL;}
		if (tail == NULL) {head = NULL;}
	}
	void pop_front() {
		Node<T> * node;
		node = head->next;
		delete head;
		head = node;
		if (head != NULL) {head->prev = NULL;}
		if (head == NULL) {tail = NULL;}
	}
	T front() {
		return head->data;
	}
	T back() {
		return tail->data;
	}
	bool empty() {
		return (head == NULL && tail == NULL);
	}
	/*int size() {
		int i;
		Node<T> * node = head;
		for (i = 0; node != NULL; i++) {
			node = node->next;
		}
		return i;
	}*/
	int size() {
		int result = 0;
		for (Node<T> * pointer = begin(); pointer != end(); pointer = pointer->next) {
			result++;
		}
		return result;
	}
	Node<T> * begin() {
		return head;
	}
	Node<T> * end() {
		return NULL;
	}
	/*Node<T> * back() {
		return tail;
	}*/
private: 
	Node<T> * head;
	Node<T> * tail;
 };

#endif

///old lists.h

/*template <typename T>
class Node {
public:
	//creates one new node for a list
	Node(T d, Node * n, Node * p);
	//holds the data (in this case the coordinates) for the snake
	T data;
	//pointer to next node in list
	Node * next;
	//pointer to previous node in list
	Node * prev;	
};

template <typename T>
class List {
public:	
	//create list
	List();
	//add new node to front of list
	void push_front(T element);
	//add new node to back of list
	void push_back(T element);
	//remove node from back of list
	void pop_back();
	//remove node from front of list
	void pop_front();
	//return data from head
	T front();
	//return data from tail
	T back();
	//check if list is empty
	bool empty();
	//return number of elements in list
	int size();
	//returns pointer to first node
	Node<T> * begin();
	//returns pointer to NULL
	Node<T> * end();
	//returns pointer to last node
	///Node<T> * back();
private:
	//first node
	Node<T> * head;
	//last node
	Node<T> * tail;
};*/

