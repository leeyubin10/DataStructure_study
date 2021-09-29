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

char post_fix_expr[1000];
int p_index = 0;

char * postfix(char expr[]) {
	Stack MyStack;

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
			//cout << MyStack.pop();
			post_fix_expr[p_index++] = MyStack.pop();
		}
		else if (expr[i] == ' ') {
			continue;
		}
		else	// �ǿ����ڸ�
		{
			//cout << expr[i];
			post_fix_expr[p_index++] = expr[i];
		}
	}
	while (!MyStack.is_stack_empty())
		post_fix_expr[p_index++] = MyStack.pop();
	//cout << endl << endl;
	post_fix_expr[p_index] = '\0';

	return post_fix_expr;

}

int calculate(char postfix[]) {

	Stack MyStack;

	for (int i = 0; i < strlen(postfix); i++)
	{
		// �����ڸ� pop() �� ���, ��� ����� �ٽ� ���ÿ� push
		if (postfix[i] == '+') {
			int opr2 = MyStack.pop();
			int opr1 = MyStack.pop();
			MyStack.push(opr1 + opr2);
		}
		else if (postfix[i] == '*') {
			int opr2 = MyStack.pop();
			int opr1 = MyStack.pop();
			MyStack.push(opr1 * opr2);
		}
		else if (postfix[i] == '-') {
			int opr2 = MyStack.pop();
			int opr1 = MyStack.pop();
			MyStack.push(opr1 - opr2);
		}
		else if (postfix[i] == '/') {
			int opr2 = MyStack.pop();
			int opr1 = MyStack.pop();
			MyStack.push(opr1 / opr2);
		}
		else if (postfix[i] >= '0' && postfix[i] <= '9') {	// �ǿ����ڸ� ���ÿ� push
			MyStack.push(postfix[i]-'0');
		}
	}
	// ��������� ���ÿ� ���� �ִ� ���� pop�Ͽ� ��ȯ
	return MyStack.pop();
}

void main() {

	char string[100];
	cout << "����ǥ�� ������ �Է��ϼ��� :";
	cin.getline(string, 100);

	char *post_expr = postfix(string);
	//cout << string << " ==> " << post_expr << endl;

	cout << string << " = " << post_expr << " = " << calculate(post_expr) << endl;

}