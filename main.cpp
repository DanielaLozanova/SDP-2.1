#include<iostream>
#include"List.h"

using namespace std;

bool containsCycle(ListNode* start)
{
	if (start == nullptr) return false;
	ListNode *slow_p = start, *fast_p = start;

	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p) {
			return true;
		}
	}
	return false;
}

int main()
{
	List l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.makeC(2);
	bool x;
	int val=2;
	ListNode* node;
	node = l.find(val);
	x = containsCycle(node);
	if (x == true)
	{
		cout << "Found Loop" << endl;
		l.undoC();
	}
	else cout << "No loop" << endl;
	l.push_back(4);
	l.push_back(5);
	node = l.find(val);
	x = containsCycle(node);
	if (x == true)
	{
		cout << "Found Loop" << endl;
		l.undoC();
	}
	else cout << "No loop" << endl;
	return 0;
}