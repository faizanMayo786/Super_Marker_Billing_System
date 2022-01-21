#pragma once
#include "item.h"
class NodeQueue {
private:
	Item Data;
	NodeQueue* Next;
public:
	NodeQueue();
	void SetNext(NodeQueue* Next);
	void SetData(Item Data);
	Item GetData();
	NodeQueue* GetNext();
};
class Queue
{
private:
	NodeQueue* Front;
	NodeQueue* Rear;

public:
	Queue();
	int NoDuplicate();
	void Enqueue(Item);
	Item Dequeue();
	void PrintQueue();
	bool IsEmpty();
	Item GetFront();
	void Read(Item data);
	void Clear();
	void DeleteSpecific(int id);
	Item Search(int id);
	void UpdateData(int id);
	void Swip(NodeQueue* lPtr1, NodeQueue* lPtr2) {
		Item temp = lPtr1->GetData();
		lPtr1->SetData(lPtr2->GetData());
		lPtr2->SetData(temp);
	}
	void Sort() {
		int swapp;
		NodeQueue* head = Front;
		NodeQueue* lPtr;
		NodeQueue* rPrt = NULL;
		do
		{
			swapp = 0;
			lPtr = head;
			while (lPtr->GetNext() != rPrt)
			{
				if (lPtr->GetData().GetID() > lPtr->GetNext()->GetData().GetID())
				{
					Swip(lPtr, lPtr->GetNext());
					swapp = 1;
				}
				lPtr = lPtr->GetNext();
			}
			rPrt = lPtr;

		} while (swapp);
		cout << "Items Sorted...\n";

	}
};
