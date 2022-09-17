#pragma once

#include "LinkedList.h"

void TestAdd() {
	cout << ">>>> Testing Add" << endl;
	LinkedList* list = new LinkedList();
	list->AddtoTail(10);
	list->AddtoTail(20);
	list->AddtoTail(30);
	list->AddtoTail(40);
	list->Print();
}

void TestDelete() {
	cout << ">>> Testing Delete" << endl;
	LinkedList* list = new LinkedList();
	list->AddtoTail(10);
	list->AddtoTail(20);
	list->AddtoTail(30);
	list->AddtoTail(40);
	cout << "Before Delete" << endl;
	list->Print();

	cout << "After Delete" << endl;
	list->Delete(1);
	list->Print();
}

void TestFind() {
	cout << ">>> Testing Find" << endl;
	LinkedList* list = new LinkedList();
	list->AddtoTail(10);
	list->AddtoTail(20);
	list->AddtoTail(30);
	list->AddtoTail(40);
	list->Print();

	Node* f = list->FindNode(1);
	if (f == NULL)
		cout << "Not Found" << endl;
	else
		cout << "Found Node: " << f->data << endl;

	f = list->FindNode(100);
	if (f == NULL)
		cout << "Not Found" << endl;
	else
		cout << "Found Node: " << f->data << endl;
}