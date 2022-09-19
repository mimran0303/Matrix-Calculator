#pragma once

#include<iostream>

using namespace std;

class Column //Node (previously)
{
public:
	int Value;
	Column* next;

	Column(int d)
	{
		Value = d;
		next = NULL;
	}
};

class Row //Linkedlist
{
public:

	Column* head;
	Column* tail;

	void AddColumn(int d) //previously known as AddtoTail
	{
		Column* n = new Column(d); //created new tail
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

	Column* GetColumn(int position) 
	{
		return FindNode(position);
	}

	Column* FindNode(int position)
	{
		int i = 0; //start at position 0
		Column* current = head; //head is first node
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

	void DeleteColumn(int position)
	{
		Column* previous = head; //node that is before targeted nodes, pointing to head (it needs a starting point)
		Column* current = head;//target node, pointing to head (it needs a starting point)
		int i = 0;
		while (current!=NULL)
		{
			if (i == position)//checks if position is within range
			{
				if (i == 0)
				{
					Column* oldhead = head;//define old head
					head = head->next;//point to new head
					delete oldhead;
					return;
				}
				Column* after = current->next;//we define the node After, which comes after the Target
				previous->next = after;//now we have Previous point to After, ingonring the Target
				delete current;//Target is now deleted
				return;
			}
			i++;//increment count
			previous = current;//pointing at same node
			current = current->next;//Current/Target now points to node After
		}
	}

	void Print()
	{
		Column* current = head;//starts at head
		while (current != NULL)
		{
			cout << current->Value << " ";//prints data in current
			current = current->next; //goes to next node
		}
		cout << endl;
	}
};

