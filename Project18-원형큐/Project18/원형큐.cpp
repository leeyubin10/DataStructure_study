#include <iostream>
using namespace std;

// ¿øÇüÅ¥
#define element int
#define MAX_SIZE 6

element CQueue[MAX_SIZE];
int front = 0;
int rear = 0;

bool is_queue_empty() {
	return (front == rear);
}

bool is_queue_full() {
	return (front == (rear+1) % MAX_SIZE);
}

void enQueue(element data) {
	if (is_queue_full()) {
		cout << "ERROR: CQueue Full" << endl;
		return;
	}
	else {
		rear = (rear + 1) % MAX_SIZE;	// *****
		CQueue[rear] = data;
	}
}

element deQueue() {
	if (is_queue_empty()) {
		cout << "ERROR: CQueue Empty" << endl;
		return -1;
	}
	else {
		front = (front + 1) % MAX_SIZE;
		return CQueue[front];
	}
}

void print_Queue() {

	if(front <= rear) {
		for (int i = front + 1; i <= rear; i++)
			cout << CQueue[i] << " ";
	}
	else {
		for(int i = front +1; i <= MAX_SIZE-1; i++)
			cout << CQueue[i] << " ";

		for(int i = 0; i <= rear; i++)
			cout << CQueue[i] << " ";
	}
	cout << endl;
}

void main() {

	enQueue(10);
	enQueue(20);
	enQueue(30);
	enQueue(40);
	enQueue(50);
	deQueue();

	enQueue(60);

	print_Queue();

	deQueue();
	deQueue();
	enQueue(70);

	print_Queue();

}