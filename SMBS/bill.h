#pragma once
#include "bill.h"
#include "item.h"
#include "time.h"
#include "queue.h"
class Bill
{
private:
	int invoiceID = 0;
	char customerName[15] = "";
	char contactNo[13] = "";
	char datetime[26] = "";
	int noOfOrder = 0;
	int quantity[20];
	double totalamount[20];
	Item item[20];
	int itemIndexNo = 0;
public:

	Bill(int invoiceID = 0, string customerName = "", string contactNo = "", string date = "", int itemIndexNo = 0) {
		SetInvoiceID(invoiceID);
		SetCustomerName(customerName);
		SetContactNo(contactNo);
	}
	void Input(Queue itemQueue);
	void BuyItems(Queue itemQueue);
	double CalculateTotalAmount(int index);
	void BillHeader();
	double Max();
	static void TitleRibbon();
	void Display();
	static void Line();
	void SetInvoiceID(int id);
	void SetCustomerName(string customerName);
	void SetContactNo(string contactNo);
	void SetDate();
	int GetInvoiceID();
	string GetCustomerName();
	string GetContactNo();
	string GetDate();

};
class NodeStacks {
private:
	Bill Data;
	NodeStacks* Next;
public:
	NodeStacks() {}
	NodeStacks* GetNext()
	{
		return Next;
	}
	Bill GetData()
	{
		return Data;
	}
	void SetNext(NodeStacks* Next)
	{
		this->Next = Next;
	}
	void SetData(Bill Data) {
		this->Data = Data;
	}
};
class Stack
{
private:
	NodeStacks* Top;
public:
	Stack() {
		Top = NULL;
	}
	void Read(Bill data) {
		NodeStacks* tempNode = Top;
		NodeStacks* newNode = new NodeStacks;
		newNode->SetData(data);
		newNode->SetNext(NULL);
		newNode->SetNext(tempNode);
		Top = newNode;
	}
	bool IsEmpty() {
		if (Top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Print() {
		NodeStacks* tempNode = Top;
		if (tempNode == NULL) {
			cout << "Stack is Empty! No Data to Show\n";
			return;
		}
		else
		{
			tempNode->GetData().TitleRibbon();
			while (tempNode != NULL)
			{
				tempNode->GetData().Display();
				tempNode = tempNode->GetNext();
			}
			Bill::Line();
		}
	}
	int NoDuplicate() {
		srand((unsigned)(time(0)));
		int id = (rand() % 1000) + 1;
		NodeStacks* newNode = Top;
		while (newNode != NULL)
		{
			if (newNode->GetData().GetInvoiceID() == id)
			{
				id = NoDuplicate();
				break;
			}
			newNode = newNode->GetNext();
		}
		return id;
	}
	void Push(Bill data) {
		NodeStacks* tempNode = Top;
		NodeStacks* newNode = new NodeStacks;
		data.SetInvoiceID(NoDuplicate());
		newNode->SetData(data);
		newNode->SetNext(NULL);
		newNode->SetNext(tempNode);
		Top = newNode;
	}
	Bill Search(int id) {
		NodeStacks* tempNode = Top;
		Bill bill = tempNode->GetData();
		int found = 0;
		while (tempNode != NULL)
		{
			if (tempNode->GetData().GetInvoiceID() == id)
			{
				found = 1;
				break;
			}
			tempNode = tempNode->GetNext();
		}
		if (found == 1)
		{
			system("cls");
			cout << "Record " << id << " Found!\n";
			Bill::TitleRibbon();
			tempNode->GetData().Display();
			return tempNode->GetData();

		}
		else
		{
			system("cls");
			cout << "Invalid ID!\n";
			return NULL;
		}
	}
	void Delete(int id) {
		NodeStacks* tempNode = Top;
		Bill bill = tempNode->GetData();
		int found = 0;
		NodeStacks* previous = new NodeStacks();
		while (tempNode != NULL)
		{
			if (tempNode->GetData().GetInvoiceID() == id)
			{
				found = 1;
				break;
			}
			previous = tempNode;

			tempNode = tempNode->GetNext();
		}
		if (found == 1)
		{
			system("cls");
			cout << "Record " << id << " Deleted!\n";
			Bill::TitleRibbon();
			tempNode->GetData().Display();
			Bill::Line();

			if (Top->GetData().GetInvoiceID() == id)
			{
				Top = Top->GetNext();

				delete tempNode;
				return;
			}
			previous->SetNext(tempNode->GetNext());
			delete tempNode;
		}
		else
		{
			system("cls");
			cout << "Invalid ID!\n";
		}
	}
	void Update(int id, Queue itemstream) {
		NodeStacks* tempNode = Top;
		Bill bill = tempNode->GetData();
		int found = 0;
		while (tempNode != NULL)
		{
			if (tempNode->GetData().GetInvoiceID() == id)
			{
				found = 1;
				break;
			}
			tempNode = tempNode->GetNext();
		}
		if (found == 1)
		{
			Bill bill;
			bill.SetInvoiceID(id);
			system("cls");
			cout << "Current Record Details\n";
			Bill::TitleRibbon();
			tempNode->GetData().Display();
			Bill::Line();

			cout << "Enter New Details:-\n";
			bill.Input(itemstream);
			tempNode->SetData(bill);
			cout << "Updated Record Details\n";
			Bill::TitleRibbon();
			tempNode->GetData().Display();
			Bill::Line();


		}
		else
		{
			system("cls");
			cout << "Invalid ID!\n";
		}
	}
	Bill Pop() {
		NodeStacks* tempNode = Top;
		Bill bill = tempNode->GetData();
		Top = Top->GetNext();
		delete tempNode;
		return bill;
	}
};
