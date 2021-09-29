#include <iostream>
using namespace std;

// 연결리스트를 이용한 큐의 기본 함수 구현, 몇 가지 간이 테스트
#define element int

class Node {
public:
	element data;
	Node* link;
};

Node* front = NULL;
Node* rear = NULL;

bool is_queue_empty() {
	return (front == NULL);	// return (rear == NULL);
}

void enQueue(element data) {
	// 새로운 노드를 첫 노드로 추가
	Node *new_node = new Node;
	new_node->data = data;
	new_node->link = NULL;

	if (is_queue_empty()) {
		front = rear = new_node;
	}
	else {
		rear->link = new_node;
		rear = new_node;
	}
}

element deQueue() {
	if (is_queue_empty()) {
		cout << "ERROR: Queue Empty" << endl;
		return -1;
	}
	else {
		element item = front->data;
		front = front->link;
		if (front == NULL) rear = NULL;
		return item;
	}
}

element peek() {
	if (is_queue_empty()) {
		cout << "ERROR: Queue Empty" << endl;
		return -1;
	}
	else {
		return front->data;
	}
}

void print_Queue() {
	cout << "QUEUE STATUS" << endl;
	if (is_queue_empty()) return;
	else {
		for (Node *ptr = front; ptr != NULL; ptr = ptr->link)
			cout << ptr->data << " ";
	}
	cout << endl;
}


void main() {

	enQueue(10);
	enQueue(20);
	enQueue(30);

	print_Queue();

	deQueue();
	deQueue();
	enQueue(40);

	print_Queue();

}