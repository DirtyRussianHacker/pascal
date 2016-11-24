#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

//queue
template<typename t>
class queue{
	list<t> *_first;
	list<t> *_last;

public:
	queue(): _first(nullptr), _last(nullptr){
		cout << "queue::constructor called" << endl;
	};

	queue(queue const &sec){
		_first = nullptr;
		_last = nullptr;
		copy_list(sec._first, _first);
		cout << "queue::copy constructor called" << endl;
	};

	~queue(){
		purge_list(_first);
		cout << "queue::destructor called" << endl;
	}

	void enqueue(t data){
		if(_first == nullptr){
			_first =  new list<t>(data, nullptr, nullptr);
			_last = _first;
		}else{
			_last = new list<t>(data, _last, nullptr);
			_last->prev->next = _last;
		}
		cout << "queue::enqueue called" << endl;
	}

	bool empty(){
		cout << "queue::empty called" << endl;
		return (_first == _last) == nullptr;
	}

	void dequeue(){
		cout << "queue::dequeue called" << endl;
		_first = _first->next;
	}

	t front(){
		cout << "queue::front called" << endl;
		return _first->data;
	}

	t front() const{
		cout << "queue::front const called" << endl;
		return _first->data;
	}

	queue & operator=(queue const &second){
		copy_list(second._first, _first);
		cout << "queue::operator= called" << endl;
	}



};

#endif /* QUEUE_H */
