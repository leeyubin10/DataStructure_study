#include <iostream>
using namespace std;

// ��ü ���� ��� ������ �⺻ �Լ� ����, �� ���� ���� �׽�Ʈ
#define element int

const int MAX_SIZE = 100;

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
			cout << "ERROR: Stack Full" << endl;
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

	void print_stack() {
		cout << "STACK STATUS (top = " << top << ")" << endl;

		if (is_stack_empty()) return;
		else {
			for (int i = top; i >= 0; i--)
				cout << MyStack[i] << endl;
		}
	}

};

bool check_matching(char sentence[])
{
	int len = strlen(sentence);
	Stack MyStack;

	for (int i = 0; i < len; i++)
	{
		if (sentence[i] == '(' || sentence[i] == '{' || sentence[i] == '{' || sentence[i] == '<') { // ���� ��ȣ
			MyStack.push(sentence[i]);
		}
		else if (sentence[i] == ')') {
			if (MyStack.is_stack_empty()) return false;

			char left = MyStack.pop();
			if (left == '(') continue;
			else return false;
		}
		else if (sentence[i] == ']') {
			if (MyStack.is_stack_empty()) return false;

			char left = MyStack.pop();
			if (left == '[') continue;
			else return false;
		}
		else if (sentence[i] == '}') {
			if (MyStack.is_stack_empty()) return false;

			char left = MyStack.pop();
			if (left == '{') continue;
			else return false;
		}
		else if (sentence[i] == '>') {
			if (MyStack.is_stack_empty()) return false;

			char left = MyStack.pop();
			if (left == '<') continue;
			else return false;
		}
	}
	if (MyStack.is_stack_empty()) return true;
	else return false;
}

void main() {

	char string[100];
	cout << "������ �Է��ϼ��� :";
	cin.getline(string, 100);

	if (check_matching(string) == true) cout << string << "==> ��ȣ OK" << endl;
	else cout << string << "==> ��ȣ ERROR" << endl;

}