#pragma once

#include "LinkedList.h"

void TestAdd() {
	LinkedList* list = new LinkedList();
	list->AddtoTail(10);
	list->AddtoTail(20);
	list->AddtoTail(30);
	list->AddtoTail(40);
	list->Print();
}