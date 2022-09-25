#pragma once
#include"LinkedList.h"
#include"Matrix.h"
#include<iostream>

using namespace std;

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

		int max_row = a->GetRow(0)->length;
		int max_column = a->length;
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

		int max_row = a->GetRow(0)->length;
		int max_column = a->length;
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


};
