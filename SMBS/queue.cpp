#include "queue.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
using namespace std;
NodeQueue::NodeQueue() {
}
void NodeQueue::SetNext(NodeQueue* Next) {
	this->Next = Next;
}
void NodeQueue::SetData(Item Data) {
	this->Data = Data;
}
Item NodeQueue::GetData() {
	return Data;
}
NodeQueue* NodeQueue::GetNext() {
	return Next;
}
Queue::Queue() {
	Front = NULL;
	Rear = NULL;
}
int Queue::NoDuplicate() {
	srand((unsigned)(time(0)));
	int id = (rand() % 1000) + 1;
	NodeQueue* newNode = Front;
	while (newNode != NULL)
	{
		if (newNode->GetData().GetID() == id)
		{
			id = NoDuplicate();
			break;
		}
		newNode = newNode->GetNext();
	}
	return id;
}
void Queue::Read(Item data) {
	NodeQueue* newNode = new NodeQueue();
	newNode->SetData(data);
	newNode->SetNext(NULL);
	if (IsEmpty())
	{
		Front = newNode;
		Rear = newNode;
	}
	else
	{
		Rear->SetNext(newNode);
		Rear = newNode;
	}
}
void Queue::Clear()
{
	while (!IsEmpty())
	{
		Dequeue();
	}

}
void Queue::DeleteSpecific(int id)
{
	int found = 0;
	NodeQueue* tempNode = Front;
	if (IsEmpty())
	{
		return;
	}
	else if (Front == Rear && tempNode->GetData().GetID() == id)
	{
		Front = NULL;
		Rear = NULL;
		found = 1;
	}
	else if (Front != Rear && tempNode->GetData().GetID() == id)
	{
		Front = Front->GetNext();
		found = 1;

	}
	else if (tempNode->GetData().GetID() == id)
	{

		Front = Front->GetNext();
		found = 1;

	}
	else
	{
		NodeQueue* previous = Front;

		while (tempNode != NULL)
		{

			if (tempNode->GetData().GetID() == id)
			{
				previous->SetNext(tempNode->GetNext());
				found = 1;
				break;
			}
			previous = tempNode;
			tempNode = tempNode->GetNext();
		}
	}

	if (found == 0)
	{
		cout << "Invalid ID, No item Deleted!\n";
		return;
	}
	else
	{
		system("cls");
		Item::TitleRibbon();
		tempNode->GetData().Display();
		Item::Line();
		cout << "Item ID " << id << " Deleted Sucessfully From Records!\n";
		delete tempNode;
		return;
	}
}
Item Queue::Search(int id)
{
	int found = 0;
	NodeQueue* tempNode = Front;
	while (tempNode != NULL)
	{
		if (tempNode->GetData().GetID() == id)
		{
			found = 1;
			break;
		}
		tempNode = tempNode->GetNext();
	}
	if (found == 0)
	{
		cout << "Item don't exists in the record!\n";
		return NULL;
	}
	else
	{
		system("cls");
		cout << "Item exists in the record!\n";
		Item::TitleRibbon();
		tempNode->GetData().Display();
		Item::Line();
		return tempNode->GetData();
	}
}
void Queue::UpdateData(int id)
{
	int found = 0;
	NodeQueue* tempNode = Front;
	while (tempNode != NULL)
	{
		if (tempNode->GetData().GetID() == id)
		{
			found = 1;
			break;
		}
		tempNode = tempNode->GetNext();
	}
	if (found == 0)
	{
		cout << "Item don't exists in the record!\n";
	}
	else
	{
		Item item;
		system("cls");
		cout << "Enter Current Details\n";
		Item::TitleRibbon();
		tempNode->GetData().Display();
		cout << "Enter Updated Details\n";
		item.SetID(id);
		item.Input();
		tempNode->SetData(item);
		system("cls");
		cout << "Record Updated!\n";

		Item::TitleRibbon();
		tempNode->GetData().Display();
		Item::Line();

	}

}
void Queue::Enqueue(Item data) {
	data.SetID(NoDuplicate());
	NodeQueue* newNode = new NodeQueue();
	newNode->SetData(data);
	newNode->SetNext(NULL);
	if (IsEmpty())
	{
		Front = newNode;
		Rear = newNode;
	}
	else
	{
		Rear->SetNext(newNode);
		Rear = newNode;
	}
	Item::TitleRibbon();
	data.Display();
	Item::Line();
}
Item Queue::Dequeue() {
	if (IsEmpty()) {
		return NULL;
	}
	else if (Front == Rear)
	{
		Item item = Front->GetData();
		Front = NULL;
		Rear = NULL;
		return item;
	}
	else {
		Item item = Front->GetData();
		NodeQueue* tempNode = Front;
		Front = Front->GetNext();
		delete tempNode;
		return item;
	}
}
void Queue::PrintQueue() {
	NodeQueue* tempNode = Front;
	if (IsEmpty()) {
		cout << "Queue is Empty!\n";
		return;
	}
	else
	{
		while (tempNode != NULL)
		{
			tempNode->GetData().Display();
			tempNode = tempNode->GetNext();
		}
	}
	Item::Line();
}
bool Queue::IsEmpty() {
	if (Front == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}
Item Queue::GetFront() {
	return Front->GetData();
}
