#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

//list
template<typename t>
struct list{
	t data;
	list<t> *prev;
	list<t> *next;

	list(t const & data, list *prev = nullptr, list *next = nullptr):
	        data(data), prev(prev), next(next)
	        {}
};

//print list
template<typename t>
void print_list(list<t> *head, string next = "<->"){
	list<t> *temp = head;
	while(temp){
		if(temp->next)
			cout << temp->data << next;
		else{
			cout << temp->data;
			break;
		}
		temp = temp->next;
	}
	cout << " -|" << endl;
	while(temp){
		if(temp->prev)
			cout << temp->data << next;
		else{
			cout << temp->data;
			break;
		}
		temp = temp->prev;
	}
	cout << " -|" << endl;
}

//copy
template<typename t>
void copy_list(list<t> const *source_head, list<t> *&dest_list){
	list<t> *temp, *res;
	purge_list(dest_list);
	res = nullptr;
	while(source_head){
		if(source_head->prev == nullptr){
			temp = new list<t> (source_head->data, nullptr, nullptr);
			dest_list = temp;
			res = temp;
		}
		else{
			temp = new list<t> (source_head->data, dest_list, nullptr);
			dest_list->next = temp;
			dest_list = temp;
		}
		source_head = source_head->next;
	}
	dest_list = res;
}

//purge
template<typename t>
void purge_list(list<t> *head){
	while(head){
		list<t> *temp = head->next;
		delete [] head;
		head = temp;
	}
}

#endif /* LIST_H */
