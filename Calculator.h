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
	static int FindProduct(Matrix* a, Matrix* b, int rowofa, int colofb)
	{
		int p = 0;
		for (int r=0; r<a->ColumnCount(); r++)
		{
			p = p + a->CellAt(rowofa,r)->Value * b->CellAt(r,colofb)->Value;
		}
		return p;
	}
public:
		static Matrix* Multiply(Matrix* a, Matrix* b)
	{
		int max_row = a->RowCount();
		int max_column = a->ColumnCount();
		
		Matrix* result = new Matrix(max_row, max_column);
		for (int r=0;r<max_row;r++)
		{
			for (int c=0;c<max_column;c++)
			{
				result->CellAt(r, c)->Value = FindProduct(a,b,r,c);
			}
		}
		return result;
	}
	static Matrix* Transpose(Matrix* a)
	{
		if (a == NULL )//special case
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
			result1 = result1 * a->CellAt(i,i)->Value; //result is 0
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

		if (max_row!=max_column||(max_row<=1 && max_column<=1))//special case, matrix must be square, therefore rows and columns must be equal
		{
			cout << "The operation was not possible because Row Count and Column Count has to be same" << endl;
			return NULL;
		}
		
		for (int j = 0; j < max_column; j++)
		{
			Matrix*b=a->Clone();
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
