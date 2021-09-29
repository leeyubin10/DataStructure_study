#include <iostream>
using namespace std;

// 큐의 기본 함수 구현, 테스트
#define element int
#define MAX_SIZE 100

element Queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool is_queue_empty() {
	return (front == rear);
}

bool is_queue_full() {
	return (rear == MAX_SIZE - 1);
}

void enQueue(element data) {
	if (is_queue_full()) {
		cout << "ERROR: Queue Full" << endl;
		return;
	}
	else {
		Queue[++rear] = data;	// rear++; Queue[rear] = data;
	}
}

element deQueue() {
	if (is_queue_empty()) {
		cout << "ERROR: Queue Empty" << endl;
		return -1;
	}
	else {
		return Queue[++front];
	}
}

element peek() {
	if (is_queue_empty()) {
		cout << "ERROR: Queue Empty" << endl;
		return -1;
	}
	else {
		return Queue[front + 1];
	}
}

void print_Queue() {
	cout << "QUEUE STATUS (front = " << front << ", rear = " << rear << ")" << endl;

	if (is_queue_empty()) return;
	else {
		for (int i = front + 1; i <= rear; i++)
			cout << Queue[i] << " ";
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