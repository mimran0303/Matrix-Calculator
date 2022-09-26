#pragma once

#include "Matrix.h"
#include "LinkedList.h"
#include"Calculator.h"

Matrix* CreateMatrix()
{
	cout << "Initialized " << endl;
	cout << endl;
	Matrix* m = new Matrix();

	MatrixNode* n1 = m->AddRow();
	n1->linkedlist->AddColumn(5);
	n1->linkedlist->AddColumn(3);
	n1->linkedlist->AddColumn(2);

	MatrixNode* n2 = m->AddRow();
	n2->linkedlist->AddColumn(0);
	n2->linkedlist->AddColumn(1);
	n2->linkedlist->AddColumn(0);

	MatrixNode* n3 = m->AddRow();
	n3->linkedlist->AddColumn(0);
	n3->linkedlist->AddColumn(0);
	n3->linkedlist->AddColumn(1);

	return m;
}

void TestMatrixPrint()
{
	cout << ">>>> Test Matrix " << endl;
	Matrix* m = CreateMatrix();
	m->Print();
}

void TestGetSetColumn()
{
	Matrix* m = CreateMatrix();
	m->Print();

	cout << "Set value at row: 1 and column:1 => 999:" << endl;
	m->CellAt(1,1)->Value = 999;
	m->Print();
	cout << "Get value at row: 1 and column:1 is:" << m->CellAt(1, 1)->Value << endl;

	cout << "Get Column Value " << endl;
	cout << endl;
	int v = m->GetRow(0)->GetColumn(2)->Value;
	cout << "Value is " << v << endl;
	cout << endl;	

}

void TestMatrixDeleteRow()
{
	Matrix* m = CreateMatrix();
	m->Print();
	cout << "Delete first row" << endl;
	cout << endl;
	m->DeleteRow(0);
	m->Print();
}

void TestMatrixDeleteColumn()
{
	Matrix* m = CreateMatrix();
	m->Print();
	cout << endl;
	cout << "Delete target value" << endl;
	cout << endl;
	m->GetRow(0)->DeleteColumn(1);
	m->GetRow(1)->DeleteColumn(1);
	m->GetRow(2)->DeleteColumn(1);
	m->Print();
}

void TestDeleteColumns()
{
	Matrix* m = CreateMatrix();
	m->Print();
	cout << endl;
	cout << "Delete target column" << endl;
	cout << endl;
	m->DeleteColumns(1);
	m->Print();
}

void TestDeleteRowandColumns()
{
	cout << "matrix m" << endl;
	Matrix* m = CreateMatrix();
	m->Print();
	cout << "column length:" << m->ColumnCount() << endl;
	cout << "row length:" << m->RowCount() << endl;
	cout << endl;
	cout << "Delete target column" << endl;
	cout << endl;
	m->DeleteColumns(1);
	m->DeleteRow(1);
	m->Print();
	cout << "column length:" << m->ColumnCount() << endl;
	cout << "row length:" << m->RowCount() << endl;
	cout << endl;
	cout << "Clone Matrix" << endl;
	Matrix* c = m->Clone();
	c->Print();
}

void TestMatrix()
{
	cout << "test matrix" << endl;
	Matrix* m = new Matrix(4,4);
	m->Print();
}

void TestAddMatrixes()
{
	cout << "adding matrix m twice" << endl;
	cout << "matrix a" << endl;
	Matrix* m = CreateMatrix();
	m->Print();
	cout << "matrix b" << endl;
	Matrix* n = CreateMatrix();
	n->Print();
	cout << "matrix c" << endl;
	Matrix* c = Calculator::AddMatrixes(m, n);
	c->Print();
}

void TestSubMatrixes()
{
	cout << "subtract matrix m by itself" << endl;
	cout << "matrix a" << endl;
	Matrix* m = CreateMatrix();
	m->Print();
	cout << "matrix b" << endl;
	Matrix* n = CreateMatrix();
	n->Print();
	cout << "matrix c" << endl;
	Matrix* c = Calculator::SubMatrixes(m, n);
	c->Print();
}

void TestTranspose()
{
	cout << "original" << endl;
	Matrix* n = CreateMatrix();
	n->Print();
	cout << "Transpose" << endl;
	Matrix* c = Calculator::Transpose(n);
	c->Print();
}

void TestMultiply()
{
	cout << "first matrix" << endl;
	Matrix* n = CreateMatrix();
	n->Print();
	cout << "second matrix" << endl;
	Matrix* m = CreateMatrix();
	m->Print();
	cout << "product" << endl;
	Matrix* c = Calculator::Multiply(n, m);
	c->Print();
}

