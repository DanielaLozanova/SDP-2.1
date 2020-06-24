#pragma once
struct ListNode;
class List 
{
private:
	ListNode *l;
	ListNode *front, *back;
	void copy_list(const List&);
	void delete_list();
public:
	List();
	List(const List&);
	List& operator=(const List&);
	~List();

	bool empty()const;
	void push_back(const int);
	void makeC(int num);
	void undoC();
	ListNode* find(int value)const;
};

struct ListNode
{
	int data;
	ListNode *next;
	ListNode(const int data) : data(data) {
		next = nullptr;
	}
};

