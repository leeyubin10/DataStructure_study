#include <iostream>
using namespace std;

// 노드 삽입 삭제 출력
class Node {
public:
	Node* link;
	int data;
};

Node* Head;

void insert_node(Node *pre, Node *new_node) {
	if (Head == NULL)
		Head = new_node;
	else if (pre == NULL) {
		new_node->link = Head;
		Head = new_node;
	}
	else {
		new_node->link = pre->link;
		pre->link = new_node;
	}
}

void insert_node_at_rear(Node *new_node) {
	if (Head == NULL) {
		Head = new_node;
	}
	else {
		Node* list;
		list = Head;
		while (list->link != NULL) {
			list = list->link;
		}
		list->link = new_node;
	}
}

void insert_node_at_front(Node *new_node) {
	new_node->link = Head;
	Head = new_node;
}

void delete_node(int x) {
	Node*list = Head;
	if (Head == NULL) return;
	else if (Head->data == x) {
		Head = Head->link;
		return;
	}
	else {
		while (list->link != NULL) {
			if (list->link->data == x) {
				list->link = list->link->link;
				return;
			}
			list = list->link;
		}
	}
}

void print_list() {
	for (Node*ptr = Head; ptr != NULL; ptr = ptr->link) {
		if (ptr->link == NULL) {
			cout << ptr->data << endl;
		}
		else
			cout << ptr->data << "-->";
	}
}

void main() {
	Head = NULL;

	int data_number;
	cout << "전체 입력 데이터의 개수는? : ";
	cin >> data_number;

	for (int i = 0; i < data_number; i++) {
		int i_data;
		cout << "새로운 값을 입력하시오(#" << i + 1 << ") : ";
		cin >> i_data;

		Node* new_node = new Node;
		new_node->data = i_data;
		new_node->link = NULL;

		insert_node_at_front(new_node);
	}

	cout << "##구성된 연결리스트는 :";
	print_list();

	for (int i = 0; i < 3; i++) {
		int del_data;
		cout << "삭제할 노드의 값: ";
		cin >> del_data;

		delete_node(del_data);

		cout << "##삭제후 연결리스트는 :";

		print_list();
	}
}