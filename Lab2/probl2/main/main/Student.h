#pragma once

class Student
{
	char name[256];
	float mathGrade;
	float englishGrade;
	float historyGrade;

public:
	void setName(char name[]);
	char* getName();

	bool setMathGrade(float grade);
	float getMathGrade();

	bool setEnglishGrade(float grade);
	float getEnglishGrade();

	bool setHistoryhGrade(float grade);
	float getHistoryGrade();

	float avarageGrade();
};