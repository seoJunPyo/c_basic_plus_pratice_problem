#include "Q14.h"
#define MAXNAME 20
#define GRADE_SIZE 3
#define CSIZE 4

void input_grade(struct student*);
void calc_average(struct student*);
void show_student_list(struct student[]);
float calc_total_average(struct student[]);

struct name {
	char fname[MAXNAME];
	char lname[MAXNAME];
};
struct student {
	struct name name;
	float grade[GRADE_SIZE];
	float average;
};

int Q14_5(void)
{
	struct student student_list[CSIZE] = {
		{.name = {"junpyo", "seo"}},
		{.name = {"jaemin", "lee"}},
		{.name = {"chulsoo", "kim"}},
		{.name = {"jiwoon", "moon"}},
	};
	float total_average;

	for (int i = 0; i < CSIZE; i++)
	{
		input_grade(&student_list[i]);
		calc_average(&student_list[i]);
	}

	show_student_list(student_list);
	total_average = calc_total_average(student_list);
	printf("전체 평균 : %.2f\n", total_average);

	return 0;
}

void input_grade(struct student *student)
{
	printf("%s %s의 성적을 입력하세요.\n", student->name.lname, student->name.fname);
	for (int i = 0; i < GRADE_SIZE; i++)
	{
		printf("%d번째 성적 : ", i + 1);
		while (scanf_s("%f", &student->grade[i]) != 1)
		{
			printf("정상적인 입력이 아닙니다. 다시 입력 : ");

			while (getchar() != '\n')
				continue;
		}
	}
}

void calc_average(struct student* student)
{
	float sum = 0;
	for (int i = 0; i < GRADE_SIZE; i++)
		sum += student->grade[i];

	student->average = sum / GRADE_SIZE;
}

void show_student_list(struct student student_list[])
{
	for (int i = 0; i < CSIZE; i++)
	{
		printf("%s %s의 성적 : \n", student_list[i].name.lname, student_list[i].name.fname);
		for (int i = 0; i < GRADE_SIZE; i++)
			printf("%d번째 성적 :  %.2f\n", i + 1, student_list[i].grade[i]);
		printf("평균 : %.2f\n\n", student_list[i].average);
	}
}

float calc_total_average(struct student student_list[])
{
	float sum = 0;

	for (int i = 0; i < CSIZE; i++)
		for (int j = 0; j < GRADE_SIZE; j++)
			sum += student_list[i].grade[j];

	return sum / (CSIZE * GRADE_SIZE);
}