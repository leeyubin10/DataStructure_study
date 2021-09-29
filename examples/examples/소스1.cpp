#include <iostream>
using namespace std;

// ��� ���� ���� ���
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
	cout << "��ü �Է� �������� ������? : ";
	cin >> data_number;

	for (int i = 0; i < data_number; i++) {
		int i_data;
		cout << "���ο� ���� �Է��Ͻÿ�(#" << i + 1 << ") : ";
		cin >> i_data;

		Node* new_node = new Node;
		new_node->data = i_data;
		new_node->link = NULL;

		insert_node_at_front(new_node);
	}

	cout << "##������ ���Ḯ��Ʈ�� :";
	print_list();

	for (int i = 0; i < 3; i++) {
		int del_data;
		cout << "������ ����� ��: ";
		cin >> del_data;

		delete_node(del_data);

		cout << "##������ ���Ḯ��Ʈ�� :";

		print_list();
	}
}