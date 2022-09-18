#pragma once

#include "LinkedList.h"

void TestAdd() {
	cout << ">>>> Testing Add" << endl;
	Row* list = new Row();
	list->AddColumn(10);
	list->AddColumn(20);
	list->AddColumn(30);
	list->AddColumn(40);
	list->Print();
}

void TestDelete() {
	cout << ">>> Testing Delete" << endl;
	Row* list = new Row();
	list->AddColumn(10);
	list->AddColumn(20);
	list->AddColumn(30);
	list->AddColumn(40);
	cout << "Before Delete" << endl;
	list->Print();

	cout << "After Delete" << endl;
	list->Delete(1);
	list->Print();
}

void TestFind() {
	cout << ">>> Testing Find" << endl;
	Row* list = new Row();
	list->AddColumn(10);
	list->AddColumn(20);
	list->AddColumn(30);
	list->AddColumn(40);
	list->Print();

	Column* f = list->FindNode(1);
	if (f == NULL)
		cout << "Not Found" << endl;
	else
		cout << "Found Node: " << f->Value << endl;

	f = list->FindNode(100);
	if (f == NULL)
		cout << "Not Found" << endl;
	else
		cout << "Found Node: " << f->Value << endl;
}