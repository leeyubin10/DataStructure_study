#include <iostream>
using namespace std;

#define element int
const int MAX_SIZE = 1000;

element Stack[MAX_SIZE];
int top = -1;

bool is_stack_empty() {
	return (top == -1);
}

bool is_stack_full() {
	return (top == MAX_SIZE - 1);
}

void push(char  data) {
	if (is_stack_full()) {
		cout << "ERROR: Stack Full" << endl;
		return;
	}
	else {
		Stack[++top] = data;
	}
}

element pop() {
	if (is_stack_empty()) {
		cout << "ERROR: Stack Empty" << endl;
		return -1;
	}
	else {
		return Stack[top--];
	}
}

void print_stack() {
	cout << "STACK STATUS" << endl;
	for (int i = top; i >= 0; i--)
		cout << Stack[i] << endl;
}

bool check_matching(char sentence[])
{
	int len = strlen(sentence);

	for (int i = 0; i < len; i++)
	{
		if (sentence[i] == '(' || sentence[i] == '{' || sentence[i] == '{' || sentence[i] == '<') { // ���� ��ȣ
			push(sentence[i]);
		}
		else if (sentence[i] == ')') {
			if (is_stack_empty()) return false;

			char left = pop();
			if (left == '(') continue;
			else return false;
		}
		else if (sentence[i] == ']') {
			if (is_stack_empty()) return false;

			char left = pop();
			if (left == '[') continue;
			else return false;
		}
		else if (sentence[i] == '}') {
			if (is_stack_empty()) return false;

			char left = pop();
			if (left == '{') continue;
			else return false;
		}
		else if (sentence[i] == '>') {
			if (is_stack_empty()) return false;

			char left = pop();
			if (left == '<') continue;
			else return false;
		}
	}
	if (is_stack_empty()) return true;
	else return false;
}

void main() {

	char string[100];
	cout << "������ �Է��ϼ��� :";
	cin.getline(string, 100);

	if (check_matching(string) == true) cout << string << "==> ��ȣ OK" << endl;
	else cout << string << "==> ��ȣ ERROR" << endl;

}