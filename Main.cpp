#include<iostream>
#include<fstream>
#include<ostream>
#include <iomanip> 
#include <ctype.h>
#include<string>
#include"LinkedList.h"
#include <string.h>
#include<algorithm>
#include "_TestLinkedList.h"
#include<sstream>
#include "_TestMatrix.h"

using namespace std;
const bool verbose = true;

char* ConvertToCharPointer(string& s)
{
	int len = s.length();
	char* str = new char[len + 1];
	strcpy(str, s.c_str());
	return str;
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
	filewrite.close();
}

void RunTests() 
{
	////TestDelete();
	//TestFind();
	//TestMatrixDeleteColumn();
	//TestDeleteColumns();
	//TestDeleteRowandColumns();
	//TestGetSetColumn();
	//TestMatrix();
	/*TestAddMatrixes();
	TestSubMatrixes();*/
	//TestTranspose();
	//TestMultiply();
	//TestDeterminant();
}

int main(int argc, char* argv[])
{
	if (argc <= 3)
	{
		cout << "Error: This program needs 3 or 4 arguments for input and output files." << endl;
		cout << "Usage: " << /* program name */argv[0] << " [command: add|sub|mul|tra|det] [input matrix] [input matrix] [output matrix]" << endl;
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

	// assign command line arguments to local variables
	char* program = argv[0];
	char* command = argv[1];
	char* file_a = argv[2];
	char* file_b = argv[3];
	char* output = argv[4];

	if (strcmp(command, "add") == 0 /* equal */)
	{
		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::AddMatrixes(a, b);
		if (verbose) {
			a->Print();
			b->Print();
			c->Print();
		}
	}
	else if (strcmp(command, "sub") == 0)
	{
		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::SubMatrixes(a, b);
		if (verbose) {
			a->Print();
			b->Print();
			c->Print();
		}
	}
	else if (strcmp(command, "mul") == 0)
	{
		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::Multiply(a, b);
		if (verbose) {
			a->Print();
			b->Print();
			c->Print();
		}
	}
	else if (strcmp(command, "tra") == 0)
	{
		Matrix* a = ReadMatrixFile(file_a);
		Matrix* c = Calculator::Transpose(a);
		if (verbose) {
			a->Print();
			c->Print();
		}
	}
	else if (strcmp(command, "det") == 0)
	{
		Matrix* a = ReadMatrixFile(file_a);
		int det = Calculator::Determinant(a);
		if (verbose) {
			a->Print();
			cout << det << endl;
		}
	}
}