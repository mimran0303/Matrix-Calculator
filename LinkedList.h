#pragma once

#include<iostream>

using namespace std;

class Node
{
public:
	int Value;
	Node* next;
public:
	Node(int d)
	{
		Value = d;
		next = NULL;
	}
};

class LinkedList
{
public:

	void AddColumn(int d) { 
		Append(d);
	}

	Node* GetColumn(int position)
	{
		return FindNode(position);
	}

	void DeleteColumn(int position)
	{
		DeleteNode(position);
	}

	int Count() 
	{
		return length;
	}

private:

	int length = 0;
	Node* head;
	Node* tail;

private:
	void Append(int d) //previously known as AddtoTail
	{
		Node* n = new Node(d); //created new tail
		// Special Condition: Initially when nothing in list
		length++;
		if (head == NULL)
		{
			head = n;
			tail = n;
			return;
		}
		// General Case when at least one or more nodes exist in list:
		tail->next = n; //new tail point at old tail
		tail = n;
		n->next = NULL;
	}

public:
	Node* FindNode(int position)
	{
		int i = 0; //start at position 0
		Node* current = head; //head is first node
		while (current != NULL)//current CANNOT equal to NULL
		{
			if (i == position) //checks if position is within range
			{
				// cout << current->Value << endl;
				return current;
			}
			current = current->next; //next current
			i++; //increments count
		}
		return NULL;
	}

private:
	void DeleteNode(int position)
	{
		Node* previous = head; //node that is before targeted nodes, pointing to head (it needs a starting point)
		Node* current = head;//target node, pointing to head (it needs a starting point)
		int i = 0;
		while (current!=NULL)
		{
			if (i == position)//checks if position is within range
			{
				length--;
				if (i == 0)
				{
					Node* oldhead = head;//define old head
					head = head->next;//point to new head
					delete oldhead;
					return;
				}
				Node* after = current->next;//we define the node After, which comes after the Target
				previous->next = after;//now we have Previous point to After, ingonring the Target
				delete current;//Target is now deleted
				return;
			}
			i++;//increment count
			previous = current;//pointing at same node
			current = current->next;//Current/Target now points to node After
		}
	}

public:
	LinkedList* Clone() //clones row
	{
		LinkedList* rowcopy = new LinkedList(); //create rowcopy
		Node* current = head; //traverse
		while (current != NULL) //adds new cells as it traverses
		{
			rowcopy->AddColumn(current->Value); //as it traverses through columns it copies into clone
			current = current->next; //tells it to traverse
		}
		return rowcopy;
	}

public:
	void Print()
	{
		Node* current = head;//starts at head
		while (current != NULL)
		{
			cout << current->Value << " ";//prints data in current
			current = current->next; //goes to next node
		}
		cout << endl;
	}

};

