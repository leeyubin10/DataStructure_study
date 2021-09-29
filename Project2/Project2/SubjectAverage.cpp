#include <iostream>
using namespace std;

//#define SUB_NUM 3
//#define STUDENT_NUM 10

const int SUB_NUM = 3;
const int STUDENT_NUM = 10;

void main()
{
	int score[SUB_NUM][STUDENT_NUM] = { { 75, 60, 88, 50, 48, 64, 95, 100, 67, 99 },
		{ 85, 80, 89, 93, 97, 83, 78, 94, 100, 100 },
		{ 70, 50, 80, 79, 85, 38, 52, 89, 93, 84 } };

	//°ú¸ñº° Æò±Õ
	double subject_average[SUB_NUM];

	for (int subj = 0; subj < SUB_NUM; subj++)
	{
		int sum = 0;
		for (int stdnt = 0; stdnt < STUDENT_NUM; stdnt++)
			sum += score[subj][stdnt];
		subject_average[subj] = (double)sum / STUDENT_NUM;
	}
	cout << "±¹¾î Æò±Õ: " << subject_average[0] << endl;
	cout << "¿µ¾î Æò±Õ: " << subject_average[1] << endl;
	cout << "¼öÇÐ Æò±Õ: " << subject_average[2] << endl;

	//°³ÀÎº° Æò±Õ
	double personal_average[STUDENT_NUM];

	for (int stdnt = 0; stdnt < STUDENT_NUM; stdnt++)
	{
		int sum = 0;
		for (int subj = 0; subj < SUB_NUM; subj++)
			sum += score[subj][stdnt];
		personal_average[stdnt] = (double)sum / SUB_NUM;
		cout << stdnt + 1 << "¹øÂ° ÇÐ»ý Æò±Õ: " << personal_average[stdnt] << endl;
	}
}