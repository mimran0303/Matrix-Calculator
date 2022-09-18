#pragma once

#include "Matrix.h"
#include "LinkedList.h"

void TestMatrix()
{
	cout << ">>>> Test Matrix " << endl;

	cout << "Initialized " << endl;
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

	m->Print();

	cout << "Set Column " << endl;
	m->GetRow(1)->GetColumn(1)->Value = 239;

	m->Print();

	cout << "Get Column Value " << endl;
	int v = m->GetRow(0)->GetColumn(2)->Value;
	cout << "Value is " << v << endl;
}