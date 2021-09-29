#include <iostream>
using namespace std;

// ��ü ���� ��� ������ �⺻ �Լ� ����, �� ���� ���� �׽�Ʈ
#define element int

const int MAX_SIZE = 1000;

class Stack {
public:
	element MyStack[MAX_SIZE];
	int top;

	Stack() {
		top = -1;
	}

	bool is_stack_empty() {
		return (top == -1);
	}

	bool is_stack_full() {
		return (top == MAX_SIZE - 1);
	}

	void push(char data) {
		if (is_stack_full()) {
			cout << "ERROR: STACK FULL" << endl;
			return;
		}
		else {
			MyStack[++top] = data;
		}
	}

	char pop() {
		if (is_stack_empty()) {
			cout << "ERROR: Stack Empty" << endl;
			return -1;
		}
		else {
			return MyStack[top--];	// ***
		}
	}

	char peek() {
		if (is_stack_empty()) {
			cout << "ERROR: Stack Empty" << endl;
			return -1;
		}
		else {
			return MyStack[top];	// ***
		}
	}

	void print_stack() {
		cout << "STACK STATUS (top = " << top << ")" << endl;

		if (is_stack_empty()) return;
		else {
			for (int i = top; i >= 0; i--)
				cout << MyStack[i] << endl;
		}
	}

};

void postfix(char expr[]) {
	Stack MyStack;

	cout << "�Է� ���� = " << expr << endl;
	cout << "���� ���� = ";

// convert to postfix	*���� �Ұ�ȣ��, ��Ģ����, �ǿ����ڴ� ���ڸ�
	for (int i = 0; i < strlen(expr); i++) {
		if (expr[i] == '(')	// ���� ��ȣ��
		{
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')	// �����ڸ�
		{
			MyStack.push(expr[i]);
		}
		else if (expr[i] == ')')	// ������ ��ȣ��
		{
			cout << MyStack.pop();
		}
		else if (expr[i] == ' ') {
			continue;
		}
		else	// �ǿ����ڸ�
		{
			cout << expr[i];
		}
	}
	while (!MyStack.is_stack_empty())
		cout << MyStack.pop();
	cout << endl << endl;
}

void main() {

	char string[100];
	cout << "������ �Է��ϼ��� :";
	cin.getline(string, 100);

	postfix(string);
}