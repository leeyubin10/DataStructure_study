#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

Node* Head;


void insert_node_A(Node *pre, Node *new_node) {	// A, B, C
	if (Head == NULL) {	// ���鸮��Ʈ�� ���
		Head = new_node;
	}
	else if (pre == NULL) {	// pre�� NULL�̸� ù��° ���� ����
		new_node->link = Head;
		Head = new_node;
	}
	else {	// pre ������ ����
		new_node->link = pre->link;
		pre->link = new_node;
	}
}

void insert_node_at_rear(Node* new_node) {
	if (Head == NULL) { // ���鸮��Ʈ�� ���
		Head = new_node;
	}
	else {
		Node* list = Head;

		while (list->link != NULL)
			list = list->link;
		list->link = new_node;
	}
}

void insert_node_at_front(Node* new_node) {
	new_node->link = Head;
	Head = new_node;
}

void delete_node (int x) {	// x���� ���� ��带 ���Ḯ��Ʈ���� ����
	Node* list = Head; // list ==> pre

	if (Head == NULL)	return;	//������ ���� ����
	else if (Head->data == x)	//ã�� ���(���� ���)�� ù ����� ���
	{
		Head = Head->link;
		return;
	}
	else // ������ ���
	{
		while (list->link != NULL)
		{
			if (list->link->data == x)
			{
				list->link = list->link->link;
				return;
			}
			list = list->link;
		}
	}
}

void print_list() {
	for (Node* ptr = Head; ptr != NULL; ptr = ptr->link)
		if (ptr->link == NULL) cout << ptr->data << endl;
		else cout << ptr->data << "-->";
}

void main() {
	Head = NULL;

	// ���Ḯ��Ʈ ����
	int data_number;
	cout << "��ü �Է� �������� ������? :";
	cin >> data_number;

	for (int i = 0; i < data_number; i++) // XX���� ������ �Է�
	{
		// ���ο� �����͸� ���ʷ� �Է��� ����
		int i_data;
		cout << "���ο� ���� �Է��Ͻÿ�(#" << i+1 << ") : ";
		cin >> i_data;

		// ���ο� ��带 �����Ͽ� ������ ����
		Node* new_node = new Node;
		new_node->data = i_data;
		new_node->link = NULL;

		// ��ü ���Ḯ��Ʈ�� �߰�/����
		insert_node_at_front(new_node);
	}

	// Ȯ�ο����� ���
	cout << "##������ ���Ḯ��Ʈ�� :";
	print_list();


	// ���Ḯ��Ʈ���� ��� ���� �ݺ�
	for (int i = 0; i < 3; i++) {
		int del_data;
		cout << "������ ����� �� :";
		cin >> del_data;

		delete_node(del_data);

		cout << "##������ ���Ḯ��Ʈ�� :";
		print_list();
	}
}