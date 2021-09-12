//============================================================================
// Name        : dequeuealisttest.cpp
// Author      : Meagan Shimonov
// Version     :1.0
// Copyright   : Your copyright notice
// Description : implement dequeue as linked list
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include "dequeuealisttest.h"
using namespace std;

Node::Node(){
	url_name = "none";
	url = "none";
	next = NULL;
	prev = NULL;
}
Node::Node(string in_url_name, string in_url){
	url_name = in_url_name;
	url = in_url;
	next = NULL;
	prev = NULL;
}

string Node::get_url_name(){
	return url_name;
}

string Node::get_url(){
	return url;
}


Node* Node::get_next(){
	return next;
}

Node* Node::get_prev(){
	return prev;
}

void Node::set_next(Node* updated_next){
	next = updated_next;
}

void Node::set_prev(Node* updated_prev){
	prev = updated_prev;
}

Node::~Node(){
	url_name = "none";
	url = "none";
	next = NULL;
	prev = NULL;
}

LinkedList::LinkedList(){
	size = 0;
	head = NULL;
	tail = NULL;
}

Node* LinkedList::get_hPtr(){
	return head;
}

Node* LinkedList::get_tPtr(){
	return tail;
}

void LinkedList::set_hPtr(Node* new_hPtr){
	head = new_hPtr;
}

void LinkedList::set_tPtr(Node* new_tPtr){
	tail = new_tPtr;
}

void LinkedList::push_front(string in_url_name, string in_url){
	Node* new_node = new Node(in_url_name, in_url);
	// we add first element to linked list if the size is zero
	if(size == 0){
		head = new_node;
		tail = head;
		head->set_next(NULL);
		head->set_prev(NULL);
	}
	else{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;
	}
	// increment the size of the queue
	size++;
	new_node = NULL;
	delete new_node;
	cout << "success" << endl;
}

void LinkedList::push_back(string in_url_name, string in_url){
	Node* new_node = new Node(in_url_name, in_url);
	if(size == 0){
		head = new_node;
		tail = head;
		head->set_next(NULL);
		head->set_prev(NULL);
	}
	else {
		tail->set_next(new_node);
		tail->get_next()->set_prev(tail);
		tail = new_node;
	}
	new_node = NULL;
	delete new_node;
	size++;
	cout << "success" << endl;
}

void LinkedList::pop_front(){
	if(size == 0){
		cout << "failure" << endl;
	}
	else if(size == 1){
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
		cout << "success" << endl;
	}
	else{
		Node* tmp = head;
		head = head->get_next();
		head->set_prev(NULL);
//		tmp->set_next(NULL);
		// added
//		tmp->set_prev(NULL);
		delete tmp;
		tmp = nullptr;
		size--;
		cout << "success" << endl;
	}
}

void LinkedList::pop_back(){
	if(size == 0){
		cout << "failure" << endl;
	}
	else if(size == 1){
		delete tail;
		tail = nullptr;
		head = nullptr;
		size--;
		cout << "success" << endl;
	}
	else{
		Node* tmp = tail;
		tail = tail->get_prev();
		tail->set_next(NULL);
		delete tmp;
		tmp = nullptr;
		size--;
		cout << "success" << endl;
	}
}

void LinkedList::get_size(){
	cout << "size is " << size << endl;
}

int LinkedList::return_size(){
	return size;
}

void LinkedList::back(){
	if(size == 0){
		cout << "failure" << endl;
	}
	else{
		cout << "back is " << tail->get_url_name() << " " << tail->get_url() << endl;
	}
}

void LinkedList::empty(){
	if(size == 0){
		cout << "empty 1" << endl;
	}
	else{
		cout << "empty 0" << endl;
	}
}

void LinkedList::clear(bool print_success){
	Node* current = head;
	while(head != NULL){
		head = head->get_next();
		delete current;
		current = NULL;
		current = head;
	}
	size = 0;
	if(print_success == true){
		cout << "success" << endl;
	}
}


LinkedList::~LinkedList(){
	Node* current = head;
	while(head != NULL){
		head = head->get_next();
		delete current;
		current = head;
	}
}

dequeue::dequeue(LinkedList LL){
	list = LL;
	top = list.get_hPtr();
	bottom = list.get_tPtr();
}

LinkedList dequeue::get_LL(){
	return list;
}

void dequeue::LL_size(){
	list.get_size();
}

void dequeue::push_front(string url_name, string url){
	list.push_front(url_name, url);
	top = list.get_hPtr();
	if(list.return_size() == 1){
		bottom = list.get_tPtr();
	}
}

void dequeue::push_back(string url_name, string url){
	list.push_back(url_name, url);
	bottom = list.get_tPtr();
	if(list.return_size() == 1){
		top = list.get_hPtr();
	}
}

void dequeue::pop_back(){
	list.pop_back();
	if(list.return_size() == 0){
		top = NULL;
		bottom = NULL;
		return;
	}
	else{
		bottom = list.get_tPtr();
	}
}

void dequeue::pop_front(){
	list.pop_front();
	if(list.return_size() == 0){
		top = NULL;
		bottom = NULL;
		return;
	}
	else {
		top = list.get_hPtr();
	}
}


void dequeue::front(){
	if(list.return_size() == 0){
		cout << "failure" << endl;
	}
	else {
		cout << "front is " << top->get_url_name() << " " << top->get_url() << endl;
	}
}

void dequeue::back(){
	if(list.return_size() == 0){
		cout << "failure" << endl;
	}
	else{
		cout << "back is " << bottom->get_url_name() << " " << bottom->get_url() << endl;
	}
}

void dequeue::empty_check(){
	list.empty();
}

void dequeue::clear_LL(){
	list.clear(true);
	top = NULL;
	bottom = NULL;
}

void dequeue::print(){
	// print list in reverse order
	if(list.return_size() == 0){
		return;
	}
	else{
		Node* current = bottom;
		while(current != NULL){
		cout << current->get_url_name() << " " << current->get_url() << endl;
		current = current->get_prev();
		}
	}
}

void dequeue::find(string wanted_url_name){
	string original_url_name = wanted_url_name;
	transform(wanted_url_name.begin(), wanted_url_name.end(), wanted_url_name.begin(), ::tolower);
	bool found = false;
	Node* current = top;
	while(current != NULL){
		string current_url_name = current->get_url_name();
		transform(current_url_name.begin(), current_url_name.end(), current_url_name.begin(), ::tolower);
		if(current_url_name == wanted_url_name){
			found = true;
			cout << "found " << current->get_url_name() << " " << current->get_url() << endl;
			break;
		}
		else{
			current = current->get_next();
		}
	}
	if(found == false){
		cout << "not found " << original_url_name << endl;
	}
}

dequeue::~dequeue(){
//	list.clear(false);
	// Linked list clear function already deletes and sets head and tail to null
//	delete top;
//	delete bottom;
//	top = NULL;
//	bottom = NULL;
}


int main() {
	string input;
	bool continue_input = true;
	LinkedList LL1;
	dequeue dq1(LL1);
	while(continue_input == true){
		getline(cin,input);
		string command = input.substr(0, input.find(" "));

		// remove any extra spacing
		char last_char = command.back();
		if(isspace(last_char)){
			command = command.substr(0, command.size() - 1);
		}

		if(command == "push_front"){
			// get url name and url from input
			string url_params = input.substr(input.find('"'));
			url_params = url_params.substr(1, url_params.size());
		    string url_name = url_params.substr(0, url_params.find('"'));
			string url = url_params.substr(url_params.find('"') + 2);
			url = url.substr(1, url.size() - 2);
			dq1.push_front(url_name, url);
		}
		else if(command == "push_back"){
			// get url and url name from input
			string url_params = input.substr(input.find('"'));
			url_params = url_params.substr(1, url_params.size());
			string url_name = url_params.substr(0, url_params.find('"'));
			string url = url_params.substr(url_params.find('"') + 2);
			url = url.substr(1, url.size() - 2);
			dq1.push_back(url_name, url);
		}
		else if(command == "pop_front"){
		 	//remove first element in dequeue
			dq1.pop_front();
		}
		else if(command == "pop_back"){
			// remove last element in dequeue
			dq1.pop_back();
		}
		else if(command == "size"){
			// get number of elements in dequeue
			dq1.LL_size();
		}
		else if(command == "front"){
			// return first element in dequeue
			dq1.front();
		}
		else if(command == "back"){
//			 return last element in dequeue
			dq1.back();
		}
		else if(command == "empty"){
			// check to see if queue is empty
			dq1.empty_check();
		}
		else if(command == "clear"){
			// remove all elements and make size be zero
			dq1.clear_LL();
		}
		else if(command == "find"){
			// get url name and search in dequeue
			string url_params = input.substr(input.find('"'));
			url_params = url_params.substr(1, url_params.size());
			string url_name = url_params.substr(0, url_params.find('"'));
			dq1.find(url_name);
		}
		else if(command == "print"){
			// print all entries in dequeue starting at back
			dq1.print();
		}
		else if(command == "exit"){
			continue_input = false;
			break;
		}
	}
	return 0;
}
