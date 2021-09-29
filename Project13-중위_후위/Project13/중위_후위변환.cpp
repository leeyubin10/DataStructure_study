#include <iostream>
using namespace std;

// 객체 선언 방식 스택의 기본 함수 구현, 몇 가지 간이 테스트
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

	cout << "입력 수식 = " << expr << endl;
	cout << "후위 수식 = ";

// convert to postfix	*가정 소괄호만, 사칙연산, 피연산자는 한자리
	for (int i = 0; i < strlen(expr); i++) {
		if (expr[i] == '(')	// 왼쪽 괄호면
		{
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')	// 연산자면
		{
			MyStack.push(expr[i]);
		}
		else if (expr[i] == ')')	// 오른쪽 괄호면
		{
			cout << MyStack.pop();
		}
		else if (expr[i] == ' ') {
			continue;
		}
		else	// 피연산자면
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
	cout << "수식을 입력하세요 :";
	cin.getline(string, 100);

	postfix(string);
}