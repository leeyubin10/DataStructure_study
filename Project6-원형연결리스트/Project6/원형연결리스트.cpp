#include <iostream>
using namespace std;

class CNode {
public:
	int data;
	CNode* link;
};

CNode* Head = NULL;

void insert_node_at_front(CNode* new_node) {
	if (Head == NULL) {
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
	}
}

void insert_node_at_rear(CNode* new_node) {
	if (Head == NULL) {
		new_node->link = new_node;
		Head = new_node;
	}
	else {
		new_node->link = Head->link;
		Head->link = new_node;
		Head = new_node;
	}
}

void delete_node(int key) 
{
	if (Head == NULL)	return;
	else if (Head->link == Head && Head->data == key) Head = NULL;
	else
	{
		CNode* pre = Head;
		do
		{
			if (pre->link->data == key) {
				CNode* removed = pre->link;
				pre->link = removed->link;	//pre->link = pre->link->link;
				if (Head == removed) Head = pre;
				return;
			}
			pre = pre->link;
		} while (pre != Head);
	}
}

void print_list() {
	cout << "원형연결리스트 결과" << endl;

	if (Head == NULL) return;
	else
	{
		CNode* ptr = Head;

		do
		{
			cout << ptr->link->data << endl;
			ptr = ptr->link;
		} while (ptr != Head);
	}
}

void main() {
	int num;
	cout << "입력 개수는? ";
	cin >> num;

	for (int i = 0; i < num; i++)
	{	// 입력값을 받아 연결리스트에 추가

		CNode* new_node = new CNode;
		int data;

		cin >> data;
		new_node->data = data;
		new_node->link = NULL;

		// 전체 연결리스트에 추가/삽입
		insert_node_at_rear(new_node);
	}

	print_list();

	int del_data;

	cout << "삭제할 값은";
	cin >> del_data;

	delete_node(del_data);

	print_list();
}