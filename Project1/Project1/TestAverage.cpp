#include <iostream>
#include <iomanip>
using namespace std;

double calculator(int scores[], int count)
{
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += scores[i];
	}
	double average = sum / count;
	return average;
}

int main()
{
	int scores[10] = { 90,100,95,60,70,50,20,100,98,100 };

	cout << fixed << setprecision(1) << "2학년 1반의 시험 성적 평균: " << calculator(scores, sizeof(scores) / sizeof(int)) << endl;

	return 0;
}