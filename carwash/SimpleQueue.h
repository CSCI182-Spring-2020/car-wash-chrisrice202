#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class SimpleQueue
{
private:
	Node* _head, * _tail;

public:
	SimpleQueue()
	{
		_head = _tail = NULL;
	}

	virtual ~SimpleQueue();

	void QueueItem(int);
	int DequeueItem();
	int CountList();
	void IncrimentList();

	// Copy constructor
	SimpleQueue(const SimpleQueue& old);
	// Assignment Operator
	SimpleQueue& operator=(const SimpleQueue& old);
	//get head
	Node* getHead() {
		return _head;
	}
	int getSecondsWaited() {
		return _head->secondsInQueue;
	}

};

