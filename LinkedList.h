#pragma once

#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int d)
	{
		data = d;
	}
};

class LinkedList
{
public:

	Node* head;
	Node* tail;

	void AddtoTail(int d)
	{
		Node* n = new Node(d); //created new tail
		// Special Condition: Initially when nothing in list
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

	void SetAt()
	{

	}

	Node* FindNode(int position)
	{
		int i = 0; //start at position 0
		Node* current = head; //head is first node
		while (current != NULL)//current CANNOT equal to NULL
		{
			if (i == position) //checks if position is within range
			{
				return current;
			}
			current = current->next; //next current
			i++; //increments count
		}
	}

	void Delete(int position)
	{
		Node* previous = head; //node that is before targeted nodes, pointing to head (it needs a starting point)
		Node* current = head;//target node, pointing to head (it needs a starting point)
		int i = 0;
		while (current!=NULL)
		{
			if (i == position)//checks if position is within range
			{
				Node* after = current->next;//we define the node After, which comes after the Target
				previous->next = after;//now we have Previous point to After, ingonring the Target
				delete current;//Target is now deleted
			}
			i++;//increment count
			previous = current;//pointing at same node
			current = current->next;//Current/Target now points to node After
		}
	}

	void Print()
	{
		Node* current = head;//starts at head
		while (current != NULL)
		{
			cout << current->data << endl;//prints data in current
			current = current->next; //goes to next node
		}
	}
};

