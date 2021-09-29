#include <iostream>
using namespace std;

// ť�� �⺻ �Լ� ����, �׽�Ʈ
#define element int
#define MAX_SIZE 100

class QUEUE {
public:
	element Queue[MAX_SIZE];
	int front, rear;

	QUEUE() {
		front = rear = -1;
	}
	
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
};

void main() {
	QUEUE Myqueue;

	Myqueue.enQueue(10);
	Myqueue.enQueue(20);
	Myqueue.enQueue(30);

	Myqueue.print_Queue();

	Myqueue.deQueue();
	Myqueue.deQueue();
	Myqueue.enQueue(40);

	Myqueue.print_Queue();

}