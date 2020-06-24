#include"List.h"
#include<iostream>
using namespace std;
List::List() 
{
	front = back = nullptr;
}

List::List(const List& other) 
{
	copy_list(other);
}

List& List::operator=(const List& other) 
{
	if (this != &other) {
		delete_list();
		copy_list(other);
	}
	return *this;
}

List::~List() 
{
	delete_list();
}

bool List::empty() const 
{
	return (front == nullptr);
}

void List::push_back(const int data) 
{
	ListNode *node = new ListNode(data);
	if (empty())
		front = node;
	else
		back->next = node;
	back = node;
}

void List::makeC(int pos)
{
	ListNode* curr = front;
	--pos;
	int cnt = 0;
	while (cnt!=pos)
	{
		curr=curr->next;
		++cnt;
	}
	back->next = curr;
}

void List::undoC()
{
	back->next = nullptr;
}

ListNode * List::find(int value) const
{
	if (empty()) return nullptr;
	ListNode *temp = front;
	while (temp != nullptr)
	{
		if (value == temp->data) return temp;
		temp = temp->next;
	}
	return nullptr;
}

void List::copy_list(const List& other) 
{
	front = nullptr;
	ListNode *ptr = other.front;
	while (ptr != nullptr) {
		push_back(ptr->data);
		ptr = ptr->next;
	}
}

void List::delete_list() {
	while (front != nullptr) {
		ListNode *ptr = front;
		front = front->next;
		delete ptr;
	}
	front = back = nullptr;
}
