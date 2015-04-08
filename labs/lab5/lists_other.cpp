//#include <iostream>
#include "lists.h"

/*template <typename T> 
class Node {
public: */
	Node::Node(T d, Node * n, Node * p) {data = d; next = n; prev = p;}
	
	/*T data;
	Node * next;
	Node * prev;
};*/

 /*template <typename T>
 class List {
public:*/
	List::List() {
		head = NULL;
		tail = NULL;
		}
	void List::push_front(T element) {
		Node<T> * node = new Node<T>(element, head, NULL);
		//if (head != NULL) {(node->next)->prev = node;} //me being dumb. next line is better replacement
		if (head != NULL) {head->prev = node;}
		if (head == NULL) {tail = node;}
		head = node;
	}	
	void List::push_back(T element) {
		Node<T> * node = new Node<T>(element, NULL, tail);
		//if (tail != NULL) {(node->prev)->next = node;} //me being dumb. next line is better replacement
		if (tail != NULL) {tail->next = node;}
		if (tail == NULL) {head = node;}
		tail = node;
	}
	void List::pop_back() {
		Node<T> * node;
		node = tail->prev;
		delete tail;
		tail = node;
		if (tail != NULL) {tail->next = NULL;}
		if (tail == NULL) {head = NULL;}
	}
	void List::pop_front() {
		Node<T> * node;
		node = head->next;
		delete head;
		head = node;
		if (head != NULL) {head->prev = NULL;}
		if (head == NULL) {tail = NULL;}
	}
	T List::front() {
		return head->data;
	}
	T List::back() {
		return tail->data;
	}
	bool List::empty() {
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
	int List::size() {
		int result = 0;
		for (Node<T> * pointer = begin(); pointer != end(); pointer = pointer->next) {
			result++;
		}
		return result;
	}
	Node<T> * List::begin() {
		return head;
	}
	Node<T> * List::end() {
		return NULL;
	}
	/*Node<T> * List::back() {
		return tail;
	}*/
/*private: 
	Node<T> * head;
	Node<T> * tail;
 };*/
