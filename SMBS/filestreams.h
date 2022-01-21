#include "queue.h"
#include <fstream>
#include "bill.h"
#pragma once
void OverwriteItemStream(Queue itemQueue) {
	ofstream irecord("items.dat", ios::out);
	Item witem;
	irecord.clear();
	while (!itemQueue.IsEmpty())
	{
		witem = itemQueue.Dequeue();
		irecord.write((char*)& witem, sizeof(Item));
	}
	irecord.close();
}
void WriteItemStream(Queue itemQueue) {
	ofstream irecord("items.dat", ios::out);
	srand(time_t(NULL));
	Item witem;
	irecord.clear();
	witem.Input();
	itemQueue.Enqueue(witem);
	while (!itemQueue.IsEmpty())
	{
		witem = itemQueue.Dequeue();
		irecord.write((char*)& witem, sizeof(Item));
	}
	irecord.close();
}
Queue ReadItemStream(Queue itemQueue) {
	ifstream orecord("items.dat", ios::in);
	if (!orecord)
	{
		cerr << "File Not Opened!\n";
		return itemQueue;
	}
	Item item;
	orecord.read((char*)& item, sizeof(Item));
	while (!orecord.eof())
	{
		itemQueue.Read(item);
		orecord.read((char*)& item, sizeof(Item));
	}
	orecord.close();
	return itemQueue;
}

void OverwriteBillStream(Stack billStack) {
	ofstream irecord("bills.dat", ios::out);
	Bill bill;
	irecord.clear();
	while (!billStack.IsEmpty())
	{
		bill = billStack.Pop();
		irecord.write((char*)& bill, sizeof(Bill));
	}
	irecord.close();
}
void WriteBillStream(Stack billStack) {
	ofstream irecord("bills.dat", ios::out);
	srand(time_t(NULL));
	Bill bill;
	Queue read;
	read = ReadItemStream(read);
	irecord.clear();
	bill.Input(read);
	billStack.Push(bill);
	while (!billStack.IsEmpty())
	{
		bill = billStack.Pop();
		irecord.write((char*)& bill, sizeof(Bill));
	}
	irecord.close();
}
Stack ReadBillStream(Stack billStack) {
	ifstream orecord("bills.dat", ios::in);
	if (!orecord)
	{
		cerr << "File Not Opened!\n";
		return billStack;
	}
	Bill bill;
	orecord.read((char*)& bill, sizeof(Bill));
	while (!orecord.eof())
	{
		billStack.Read(bill);
		orecord.read((char*)& bill, sizeof(Bill));
	}
	orecord.close();
	return billStack;
}
