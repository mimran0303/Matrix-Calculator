#pragma once

#include<iostream>
#include "LinkedList.h"


using namespace std;

class MatrixNode
{
public:

	LinkedList* linkedlist;
	MatrixNode* next;
	MatrixNode()
	{
		linkedlist = new LinkedList();
		next = NULL;
	}

	LinkedList* Columns()
	{
		return linkedlist;
	}

	MatrixNode* Clone()
	{
		MatrixNode* copy = new MatrixNode(); //new node
		copy->linkedlist = linkedlist->Clone();//Clone is now assigned to new node
		return copy;
	}
};

class Matrix
{
private:
	int length = 0;

private:
	MatrixNode* head;
	MatrixNode* tail;

public:
	Matrix()
	{
		head = NULL;
		tail = NULL;
	}

	Matrix(int rowsize, int columnsize)
	{
		head = NULL;
		tail = NULL;
		for (int i = 0; i < rowsize; i++)
		{
			MatrixNode* r = AddRow();

			for (int j = 0; j < columnsize; j++)
			{
				r->linkedlist->AddColumn(0);
			}
		}
	}

	int RowCount()
	{
		return length;
	}

	int ColumnCount()
	{
		if (GetRow(0) == NULL)
			return 0;
		return GetRow(0)->Count();
	}

	MatrixNode* AddRow()
	{
		MatrixNode* n = new MatrixNode(); //created new tail
		AddRow(n);
		return n;
	}
	
	MatrixNode* AddRow(MatrixNode* n)
	{
		length++;
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

	Node* CellAt(int row, int col) 
	{
		Node* cell = GetRow(row)->GetColumn(col);
		return cell;
	}

	LinkedList* GetRow(int position) //
	{
		MatrixNode* node = Find(position);
		if (node == NULL)
		{
			return NULL;
		}
		else
			return node->linkedlist;
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
				length--;
				if (i == 0) // special case
				{
					MatrixNode* oldhead = head;//defining old head
					head = head->next;//now make head point to SecondNode
					delete oldhead;//delete head
					return;
				}

				// General Case
				MatrixNode* after = current->next;//we define the node After, which comes after the Target
				previous->next = after;//now we have Previous point to After, ingnoring the Target
				delete current;//Target is now delete
				return;

				
			}
			i++;//increment count
			previous = current;//pointing at same node
			current = current->next;//Current/Target now points to node After
		}
	}

	void DeleteColumns(int position)
	{
		MatrixNode* current = head;//starting at head
		while (current!=NULL)
		{
			current->linkedlist->DeleteColumn(position);
			current = current->next;
		}
	}

	void Print()
	{
		cout << "----------- Matrix ------------ " << endl;
		MatrixNode* current = head;//starts at head
		while (current != NULL)
		{
			current->linkedlist->Print();
			current = current->next; //goes to next node
		}
		cout << ">>>> RowCount=" << RowCount() << ", ColumnCount=" << ColumnCount() << endl;
	}

	Matrix* Clone()
	{
		Matrix* copy = new Matrix(); //making copy
		MatrixNode* current = head; //we have current
		while (current != NULL)
		{
			MatrixNode* c = current->Clone();//clone matrix node
			copy->AddRow(c);//row with all matrix node is copied
			current = current->next;//next in matrix node
		}
		return copy;
	}
	
};

