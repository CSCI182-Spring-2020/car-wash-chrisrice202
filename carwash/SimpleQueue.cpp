#include "SimpleQueue.h"
#include "Node.h"

/// <summary>
/// Destructor
/// </summary>
SimpleQueue::~SimpleQueue()
{
	Node* temp;
	while (_head != NULL)
	{
		temp = _head;
		_head = temp->next;
		delete temp;
	}
}

/// <summary>
/// Queues a new item at the correct spot of the Priority Queue
/// </summary>
/// <param name="newValue">The integer value of the new item</param>
/// <param name="nodePriority">The priority of the new item</param>
void SimpleQueue::QueueItem(int newValue)
{
	// Start at the head
	Node* newNode = new Node();
	newNode->next = NULL;
	newNode->value = newValue;

	// Check if Queue empty, if so, insert the new item, return
	if (_head == NULL)
	{
		_head = _tail = newNode;
		cout << "Queued Item " << newNode->value << endl;
		return;
	}

	// Loop to end
	Node* currentNode = _head;
	Node* priorNode = NULL;
	while (currentNode != _tail)
	{
		priorNode = currentNode;
		currentNode = currentNode->next;
	}

	// Insert the new item
	currentNode->next = newNode;

	// Set the position for the tail if this is last item
	_tail = newNode;

	cout << "Queued Item " << newNode->value << endl;
}

/// <summary>
/// Dequeues the next item in the queue
/// </summary>
/// <returns>The value of the next node</returns>
int SimpleQueue::DequeueItem()
{
	// Is empty?
	if (_head == NULL)
		return -1;

	Node* temp = _head;
	_head = temp->next;

	// Set the new head to maintain the list
	// even if the next it is NULL (empty)
	if (_head == NULL)
		_tail = NULL;

	int nReturn = temp->value;
	delete temp;

	cout << "Dequeued Node" << endl;
	return nReturn;
}

/// <summary>
/// Display the entire list as it exists currently
/// </summary>
int SimpleQueue::CountList()
{

	// If empty, just return nothing
	if (_head == NULL)
		return 0;

	Node* temp = _head;
	int carsInList = 0;

	// Loop through until all item have been printed
	while (1)
	{
		carsInList++;

		// If at end, exit
		if (temp == _tail)
			return carsInList;

		temp = temp->next;
	}
}

void SimpleQueue::IncrimentList()
{

	// If empty, just return nothing
	if (_head == NULL)
		return;

	Node* temp = _head;

	// Loop through until all items have been incrimented
	while (1)
	{
		temp->secondsInQueue++;

		// If at end, exit
		if (temp == _tail)
			return;

		temp = temp->next;
	}
}