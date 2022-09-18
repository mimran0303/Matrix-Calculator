#pragma once

#include "Matrix.h"

void TestMatrix()
{
	Matrix* m = new Matrix();

	MatrixNode* n1 = m->AddRow();
	n1->row->AddtoTail(5);
	n1->row->AddtoTail(3);
	n1->row->AddtoTail(2);

	MatrixNode* n2 = m->AddRow();
	n2->row->AddtoTail(0);
	n2->row->AddtoTail(1);
	n2->row->AddtoTail(0);
	
	MatrixNode* n3 = m->AddRow();
	n3->row->AddtoTail(0);
	n3->row->AddtoTail(0);
	n3->row->AddtoTail(1);

	m->Print();
}