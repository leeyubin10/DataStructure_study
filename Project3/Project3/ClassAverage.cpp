#include <iostream>
using namespace std;

//#define CLASS 3
//#define SUB_NUM 3
//#define STUDENT_NUM 10

const int CLASS = 3;
const int SUB_NUM = 3;
const int STUDENT_NUM = 10;

void main()
{
	//char Name[SUB_NUM][10] = { "국어", "영어", "수학" };
	int score[CLASS][SUB_NUM][STUDENT_NUM] = { {{75, 60, 88, 50, 48, 64, 95, 100, 67, 99}, {85, 80, 89, 93, 97, 83, 78, 94, 100, 100},{70, 50, 80, 79, 85, 38, 52, 89, 93, 84}},
	{{50,42,88,94,65,73,48,93,56,78},{63,45,89,94,88,79,100,88,100,60},{89,98,75,41,25,100,97,85,74,62}},
	{{85, 70, 89, 93, 57, 83, 98, 94, 80, 100},{63,95,49,94,88,69,100,58,100,30},{39,98,100,41,65,100,57,85,74,82}} };

	//각 반별 과목별 평균
	double threeclass_average[CLASS][SUB_NUM];

	for (int stdcl = 0; stdcl < CLASS; stdcl++)
	{
		for (int subj = 0; subj < SUB_NUM; subj++)
		{
			int sum = 0;
			for (int stdnt = 0; stdnt < STUDENT_NUM; stdnt++)
				sum += score[stdcl][subj][stdnt];
			threeclass_average[stdcl][subj] = (double)sum / STUDENT_NUM;
		}
	}

	cout << "3학년 1반 국어 평균: " << threeclass_average[0][0] << endl;
	cout << "3학년 1반 영어 평균: " << threeclass_average[0][1] << endl;
	cout << "3학년 1반 수학 평균: " << threeclass_average[0][2] << endl << endl;

	cout << "3학년 2반 국어 평균: " << threeclass_average[1][0] << endl;
	cout << "3학년 2반 영어 평균: " << threeclass_average[1][1] << endl;
	cout << "3학년 2반 수학 평균: " << threeclass_average[1][2] << endl << endl;

	cout << "3학년 3반 국어 평균: " << threeclass_average[2][0] << endl;
	cout << "3학년 3반 영어 평균: " << threeclass_average[2][1] << endl;
	cout << "3학년 3반 수학 평균: " << threeclass_average[2][2] << endl << endl;

	//해당 학년의 과목별 평균
	double thirdgrade_average[SUB_NUM];

	for (int subj= 0; subj < SUB_NUM; subj++)
	{
		int sum = 0;
		for (int stdcl = 0; stdcl < CLASS; stdcl++)
			for(int stdnt = 0; stdnt < STUDENT_NUM; stdnt++)
				sum += score[stdcl][subj][stdnt];
		thirdgrade_average[subj] = (double)sum / (CLASS * STUDENT_NUM);
	}

	cout << "3학년 전체 국어 평균: " << thirdgrade_average[0] << endl;
	cout << "3학년 전체 영어 평균: " << thirdgrade_average[1] << endl;
	cout << "3학년 전체 수학 평균: " << thirdgrade_average[2] << endl;
}