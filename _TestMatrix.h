#pragma once

#include "Matrix.h"
#include "LinkedList.h"

Matrix* CreateMatrix()
{
	cout << "Initialized " << endl;
	cout << endl;
	Matrix* m = new Matrix();

	MatrixNode* n1 = m->AddRow();
	n1->row->AddColumn(5);
	n1->row->AddColumn(3);
	n1->row->AddColumn(2);

	MatrixNode* n2 = m->AddRow();
	n2->row->AddColumn(0);
	n2->row->AddColumn(1);
	n2->row->AddColumn(0);

	MatrixNode* n3 = m->AddRow();
	n3->row->AddColumn(0);
	n3->row->AddColumn(0);
	n3->row->AddColumn(1);

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
	Matrix* m = CreateMatrix();
	m->Print();
	cout << "column length:" << m->length << endl;
	cout << "row length:" << m->GetRow(0)->length << endl;
	cout << endl;
	cout << "Delete target column" << endl;
	cout << endl;
	m->DeleteColumns(1);
	m->DeleteRow(1);
	m->Print();
	cout << "column length:" << m->length << endl;
	cout << "row length:" << m->GetRow(0)->length << endl;
	cout << endl;
	cout << "Clone Matrix" << endl;
	Matrix* c = m->Clone();
	c->Print();
}



