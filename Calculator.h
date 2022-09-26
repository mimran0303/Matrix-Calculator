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
	static int FindProduct(Matrix* a, Matrix* b, int rowofa, int colofb)
	{
		int p = 0;
		for (int r=0; r<a->ColumnCount(); r++)
		{
			p = p + a->CellAt(rowofa,r)->Value * b->CellAt(r,colofb)->Value;
		}
		return p;
	}
	static Matrix* Multiply(Matrix* a, Matrix* b)
	{
		int max_row = a->RowCount();
		int max_column = a->ColumnCount();
		
		if (max_row != max_column)
		{
			cout << "The operation was not possible" << endl;
			return 0;
		}
		Matrix* result = new Matrix(max_row, max_column);
		for (int r=0;r<max_row;r++)
		{
			for (int c=0;c<max_column;c++)
			{
				result->CellAt(c, r)->Value = FindProduct(a,b,r,c);
			}
		}
		return result;
	}
	static Matrix* Transpose(Matrix* a)
	{
		if (a == NULL )//special case
		{
			cout << "The operation was not possible" << endl;
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
	static Matrix* DetMatrixes(Matrix* a)
	{

	}
};
