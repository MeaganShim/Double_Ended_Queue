/*
 * dequeuealisttest.h
 *
 *  Created on: Feb 1, 2021
 *      Author: Meagan
 */

#ifndef DEQUEUEALISTTEST_H_
#define DEQUEUEALISTTEST_H_

#include <iostream>
using namespace std;

class Node{
// purpose of node is to store data and pointers to next and previous element
private:
	string url_name;
	string url;
	Node* next;
	Node* prev;
public:
	Node();
	Node(string in_url_name, string in_url);
	string get_url();
	string get_url_name();
	Node* get_next();
	Node* get_prev();
	void set_next(Node* updated_next);
	void set_prev(Node* updated_prev);
	~Node();
};

class LinkedList: public Node {
	// the purpose of linked list class is to link the nodes together
private:
	int size;
	Node* head;
	Node* tail;
public:
	LinkedList();
	Node* get_hPtr();
	Node* get_tPtr();
	void set_hPtr(Node* new_hPtr);
	void set_tPtr(Node* new_tPtr);
	void push_front(string in_url_name, string in_url);
	void push_back(string in_url_name, string in_url);
	void pop_front();
	void pop_back();
	void get_size();
	int return_size();
	void front();
	void back();
	void empty();
	void clear(bool print_success);
//	void find(string wanted_url);
//	void print();
	~LinkedList();
};

class dequeue{
private:
	Node* top;
	Node* bottom;
	LinkedList list;
public:
	dequeue(LinkedList list);
	void push_front(string url_name, string url);
	void push_back(string url_name, string url);
	LinkedList get_LL();
	void LL_size();
	void pop_front();
	void pop_back();
	void front();
	void back();
	void empty_check();
	void clear_LL();
	void find(string wanted_url_name);
	void print();
	~dequeue();
};

#endif /* DEQUEUEALISTTEST_H_ */
