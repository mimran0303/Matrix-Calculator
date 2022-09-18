#pragma once

#include<iostream>
#include "LinkedList.h"

using namespace std;

class MatrixNode
{
public:
	Row* row;
	MatrixNode* next;
	MatrixNode()
	{
		row = new Row();
		next = NULL;
	}
};

class Matrix
{
public:

	MatrixNode* head;
	MatrixNode* tail;

	MatrixNode* AddRow()
	{
		MatrixNode* n = new MatrixNode(); //created new tail
		// Special Condition: Initially when nothing in list
		if (head == NULL)
		{
			head = n;
			tail = n;
			return n;
		}
		// General Case when at least one or more nodes exist in list:
		tail->next = n; //new tail point at old tail
		tail = n;
		n->next = NULL;
		return n;
	}

	void SetAt()
	{

	}

	Row* GetRow(int position) //
	{
		MatrixNode* node = Find(position);
		if (node == NULL)
		{
			return NULL;
		}
		else
			return node->row;
	}

	MatrixNode* Find(int position)
	{
		int i = 0; //start at position 0
		MatrixNode* current = head; //head is first node
		while (current != NULL)//current CANNOT equal to NULL
		{
			if (i == position) //checks if position is within range
			{
				// cout << current->row << endl;
				return current;
			}
			current = current->next; //next current
			i++; //increments count
		}
		return NULL;
	}

	void DeleteRow(int position)
	{
		MatrixNode* previous = head; //node that is before targeted nodes, pointing to head (it needs a starting point)
		MatrixNode* current = head;//target node, pointing to head (it needs a starting point)
		int i = 0;
		while (current != NULL)
		{
			if (i == position)//checks if position is within range
			{
				MatrixNode* after = current->next;//we define the node After, which comes after the Target
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
		MatrixNode* current = head;//starts at head
		while (current != NULL)
		{
			current->row->Print();
			current = current->next; //goes to next node
		}
	}
};

