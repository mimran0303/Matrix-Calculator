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
#include "Main.h"

using namespace std;
const bool verbose = true;

void help(char* argv[])
{
	cout << "Error: This program needs 3 or 4 arguments for input and output files." << endl;
	cout << "Usage: " << /* program name */argv[0] << " [command: add|sub|mul|tra|det] [input matrix] [input matrix] [output matrix]" << endl;
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

	// assign command line arguments to local variables
	char* program = argv[0];
	char* command = argv[1];
	char* file_a = argv[2];
	char* file_b = argv[3];
	char* output = argv[4];

	if (_stricmp(command, "add") == 0 /* equal */)
	{
		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::AddMatrixes(a, b);
		if (verbose) {
			a->Print();
			b->Print();
			if (c != NULL) 
				c->Print();
		}
	}
	else if (_stricmp(command, "sub") == 0)
	{
		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::SubMatrixes(a, b);
		if (verbose) {
			a->Print();
			b->Print();
			if (c != NULL)
				c->Print();
		}
	}
	else if (_stricmp(command, "mul") == 0)
	{
		Matrix* a = ReadMatrixFile(file_a);
		Matrix* b = ReadMatrixFile(file_b);
		Matrix* c = Calculator::Multiply(a, b);
		if (verbose) {
			a->Print();
			b->Print();
			if (c != NULL)
				c->Print();
		}
	}
	else if (_stricmp(command, "tra") == 0)
	{
		Matrix* a = ReadMatrixFile(file_a);
		Matrix* c = Calculator::Transpose(a);
		if (verbose) {
			a->Print();
			if (c != NULL)
				c->Print();
		}
	}
	else if (_stricmp(command, "det") == 0)
	{
		Matrix* a = ReadMatrixFile(file_a);
		int det = Calculator::Determinant(a);
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