#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

Node* Head;


void insert_node_A(Node *pre, Node *new_node) {	// A, B, C
	if (Head == NULL) {	// 공백리스트인 경우
		Head = new_node;
	}
	else if (pre == NULL) {	// pre가 NULL이면 첫번째 노드로 삽입
		new_node->link = Head;
		Head = new_node;
	}
	else {	// pre 다음에 삽입
		new_node->link = pre->link;
		pre->link = new_node;
	}
}

void insert_node_at_rear(Node* new_node) {
	if (Head == NULL) { // 공백리스트인 경우
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

void delete_node (int x) {	// x값을 갖는 노드를 연결리스트에서 삭제
	Node* list = Head; // list ==> pre

	if (Head == NULL)	return;	//삭제할 것이 없음
	else if (Head->data == x)	//찾는 노드(삭제 노드)가 첫 노드인 경우
	{
		Head = Head->link;
		return;
	}
	else // 나머지 경우
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

	// 연결리스트 구성
	int data_number;
	cout << "전체 입력 데이터의 개수는? :";
	cin >> data_number;

	for (int i = 0; i < data_number; i++) // XX개의 데이터 입력
	{
		// 새로운 데이터를 차례로 입력을 받음
		int i_data;
		cout << "새로운 값을 입력하시오(#" << i+1 << ") : ";
		cin >> i_data;

		// 새로운 노드를 생성하여 내용을 수정
		Node* new_node = new Node;
		new_node->data = i_data;
		new_node->link = NULL;

		// 전체 연결리스트에 추가/삽입
		insert_node_at_front(new_node);
	}

	// 확인용으로 출력
	cout << "##구성된 연결리스트는 :";
	print_list();


	// 연결리스트에서 노드 삭제 반복
	for (int i = 0; i < 3; i++) {
		int del_data;
		cout << "삭제할 노드의 값 :";
		cin >> del_data;

		delete_node(del_data);

		cout << "##삭제후 연결리스트는 :";
		print_list();
	}
}