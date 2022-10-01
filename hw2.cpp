#include<iostream>
#include<fstream>
#include<ostream>
#include <iomanip> 
#include <ctype.h>
#include<string.h>
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include <math.h>

using namespace std;
const bool verbose = false;

// ----------------------------------------------------------------------
//
// Linked List
// 
// ----------------------------------------------------------------------

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
		while (current != NULL)
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
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(1);
			cout << (float)current->Value << " ";//prints data in current
			current = current->next; //goes to next node
		}
		cout << endl;
	}

};

// ----------------------------------------------------------------------
//
// Matrix
// 
// ----------------------------------------------------------------------

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
		while (current != NULL)
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

// ----------------------------------------------------------------------
//
// Calculator
// 
// ----------------------------------------------------------------------

class Calculator
{
public:

	static Matrix* AddMatrixes(Matrix* a, Matrix* b) //input is 2 matrices, output in one matrix
	{
		if (a == NULL || b == NULL)//special case
		{
			cout << "The operation was not possible" << endl;
			return NULL;
		}
		if (a->RowCount() != b->RowCount() || a->ColumnCount() != b->ColumnCount())
		{
			cout << "Row Count and Column Count should be same to be able to add" << endl;
			return NULL;
		}

		int max_row = a->RowCount();
		int max_column = a->ColumnCount();
		Matrix* c = new Matrix(max_row, max_column);
		for (int i = 0; i < max_row; i++)
		{
			for (int j = 0; j < max_column; j++)
			{
				c->CellAt(i, j)->Value = a->CellAt(i, j)->Value + b->CellAt(i, j)->Value;
			}
		}
		return c;
	}

	static Matrix* SubMatrixes(Matrix* a, Matrix* b) //input is 2 matrices, output in one matrix
	{
		if (a == NULL || b == NULL)//special case
		{
			cout << "The operation was not possible" << endl;
			return NULL;
		}
		if (a->RowCount() != b->RowCount() || a->ColumnCount() != b->ColumnCount())
		{
			cout << "Row Count and Column Count should be same to be able to subtract" << endl;
			return NULL;
		}

		int max_row = a->RowCount();
		int max_column = a->RowCount();
		Matrix* c = new Matrix(max_row, max_column);
		for (int i = 0; i < max_row; i++)
		{
			for (int j = 0; j < max_column; j++)
			{
				c->CellAt(i, j)->Value = a->CellAt(i, j)->Value - b->CellAt(i, j)->Value;
			}
		}
		return c;
	}
private:
	static int FindProduct(Matrix* a, int row_a, Matrix* b, int col_b)
	{
		int p = 0;
		for (int n = 0; n < a->ColumnCount() /* or b->ColumnCount() must be same */; n++)
		{
			p = p + a->CellAt(row_a, n)->Value * b->CellAt(n, col_b)->Value;
		}
		return p;
	}
public:
	static Matrix* Multiply(Matrix* a, Matrix* b)
	{
		if (a == NULL || b == NULL)//special case
		{
			cout << "The operation was not possible" << endl;
			return NULL;
		}
		if (a->ColumnCount() != b->RowCount())
		{
			cout << "Column Count or first matrix should be same as Row Count of second matrix" << endl;
			return NULL;
		}

		Matrix* result = new Matrix(a->RowCount(), b->ColumnCount());
		for (int r = 0; r < a->RowCount(); r++)
		{
			for (int c = 0; c < b->ColumnCount(); c++)
			{
				result->CellAt(r, c)->Value = FindProduct(a, r, b, c);
			}
		}
		return result;
	}

	static Matrix* Transpose(Matrix* a)
	{
		if (a == NULL)//special case
		{
			cout << "The operation was not possible because matrix is null" << endl;
			return NULL;
		}

		int max_row = a->RowCount();
		int max_column = a->ColumnCount();
		Matrix* c = new Matrix(max_row, max_column);
		for (int i = 0; i < max_row; i++)
		{
			for (int j = 0; j < max_column; j++)
			{
				c->CellAt(j, i)->Value = a->CellAt(i, j)->Value;
			}
		}
		return c;
	}
public:
	static int GetCofactor(Matrix* a)//in this function we look at column and row and do calculations for cofactor
	{
		int max_row = a->RowCount();
		int max_column = a->ColumnCount();
		int result1 = 1;
		int result2 = 1;

		for (int i = 0; i < a->ColumnCount(); i++)
		{
			result1 = result1 * a->CellAt(i, i)->Value; //result is 0
		}

		for (int j = 0; j < a->ColumnCount(); j++)
		{
			result2 = result2 * a->CellAt(j, max_column - j - 1)->Value;
		}

		return(result1 - result2);
	}

	static int Determinant(Matrix* a) //Delete Column and Delete Row will be used?? ... recursion?
	{
		int max_row = a->RowCount();
		int max_column = a->ColumnCount();

		int result = 0;

		if (max_row != max_column || (max_row <= 1 && max_column <= 1))//special case, matrix must be square, therefore rows and columns must be equal
		{
			cout << "The operation was not possible because Row Count and Column Count has to be same" << endl;
			return -1;
		}

		for (int j = 0; j < max_column; j++)
		{
			Matrix* b = a->Clone();
			b->DeleteRow(0);
			b->DeleteColumns(j);
			int exp = (int)pow(-1, (j + 2));
			int targetNumber = a->CellAt(0, j)->Value;
			int cofactor = GetCofactor(b);
			result = result + exp * targetNumber * cofactor; // -1 or 1 * value at target node in row 0 * Cofactor
		}
		return result;
	}
};

// ----------------------------------------------------------------------
//
// Main
// 
// ----------------------------------------------------------------------

void help(char* argv[])
{
	cout << "Error: This program needs 3 or 4 arguments for input and output files." << endl;
	cout << "Usage 1: " << /* program name */argv[0] << " [command: add|sub|mul] [input matrix] [input matrix] [output matrix]" << endl;
	cout << "Usage 2: " << /* program name */argv[0] << " [command: tra] [input matrix] [output matrix]" << endl;
	cout << "Usage 3: " << /* program name */argv[0] << " [command: det] [input matrix] [output file]" << endl;
}

char* ConvertToCharPointer(string& s)
{
	int len = s.length();
	char* str = new char[len + 1];
	strcpy(str, s.c_str());
	return str;
}

string trim(string s)
{
	s.erase(s.find_last_not_of(' ') + 1); //suffixing spaces
	s.erase(0, s.find_first_not_of(' ')); //prefixing spaces
	return s;
}

void Parse(string str, MatrixNode* n)
{
	char* cstr = ConvertToCharPointer(str);
	char* strNumber = strtok(cstr, " ");

	while (strNumber != NULL)
	{
		int i = atoi(strNumber);
		n->Columns()->AddColumn(i);
		strNumber = strtok(NULL, " ");
	}
}

Matrix* ReadMatrixFile(string filename)
{
	ifstream fileread;
	fileread.open(filename);
	if (fileread.is_open())
	{
		string line;
		Matrix* m = new Matrix();
		while (getline(fileread, line))
		{
			line = trim(line);
			if (line.length() == 0)
				continue;
			MatrixNode* n1 = m->AddRow();
			Parse(line, n1);
		}
		fileread.close();
		return m;
	}
	return NULL;
}

void WriteToFile(string filename, Matrix* m)
{
	ofstream filewrite;
	filewrite.open(filename);
	if (filewrite.is_open()) {
		filewrite.setf(ios::fixed);
		filewrite.setf(ios::showpoint);
		filewrite.precision(1);
		for (int i = 0; i < m->RowCount(); i++)
		{
			for (int j = 0; j < m->ColumnCount(); j++)
			{
				filewrite << (float)m->CellAt(i, j)->Value;
				if (j < m->ColumnCount() - 1)
					filewrite << " ";
			}
			filewrite << endl;
		}
	}
	filewrite.close();
}

void WriteToFile(string filename, int i)
{
	ofstream filewrite;
	filewrite.open(filename);
	filewrite.setf(ios::fixed);
	filewrite.setf(ios::showpoint);
	filewrite.precision(1);
	filewrite << (float)i << endl;
	filewrite.close();
}

int main(int argc, char* argv[])
{
	if (argc <= 3)
	{
		help(argv);
		return -1;
	}

	if (verbose)
	{
		cout << "Command Line Parameters " << endl;
		if (argc >= 1) cout << "argv[0] => " << argv[0] << endl;
		if (argc >= 2) cout << "argv[1] => " << argv[1] << endl;
		if (argc >= 3) cout << "argv[2] => " << argv[2] << endl;
		if (argc >= 4) cout << "argv[3] => " << argv[3] << endl;
		if (argc >= 5) cout << "argv[4] => " << argv[4] << endl;
	}

	char* program = argv[0];
	char* command = argv[1];

	if (strncasecmp(command, "add", 3) == 0)
	{
		char* file_a = argv[2];
		char* file_b = argv[3];
		char* output = argv[4];

		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::AddMatrixes(a, b);

		WriteToFile(output, c);

		if (verbose) {
			a->Print();
			b->Print();
			if (c != NULL)
				c->Print();
		}
	}
	else if (strncasecmp(command, "sub", 3) == 0)
	{
		char* file_a = argv[2];
		char* file_b = argv[3];
		char* output = argv[4];

		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::SubMatrixes(a, b);

		WriteToFile(output, c);

		if (verbose) {
			a->Print();
			b->Print();
			if (c != NULL)
				c->Print();
		}
	}
	else if (strncasecmp(command, "mul", 3) == 0)
	{
		char* file_a = argv[2];
		char* file_b = argv[3];
		char* output = argv[4];

		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::Multiply(a, b);

		WriteToFile(output, c);

		if (verbose) {
			a->Print();
			b->Print();
			if (c != NULL)
				c->Print();
		}
	}
	else if (strncasecmp(command, "tra", 3) == 0)
	{
		char* file_a = argv[2];
		char* output = argv[3];

		Matrix* a = ReadMatrixFile(file_a);
		Matrix* c = Calculator::Transpose(a);

		WriteToFile(output, c);

		if (verbose) {
			a->Print();
			if (c != NULL)
				c->Print();
		}
	}
	else if (strncasecmp(command, "det", 3) == 0)
	{
		char* file_a = argv[2];
		char* output = argv[3];

		Matrix* a = ReadMatrixFile(file_a);
		int det = Calculator::Determinant(a);

		WriteToFile(output, det);

		if (verbose) {
			a->Print();
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(1);
			cout << (float)det << endl;
		}
	}
	else
	{
		help(argv);
	}
}
