#include "Student.h"
#include <cstring>
#pragma warning(disable:4996)

void Student::setName(char name[]) {
	strcpy(this->name, name);
}
char* Student::getName() {
	return name;
}

bool Student::setMathGrade(float grade) {
	if (grade < 1 || grade > 10)
		return false;
	mathGrade = grade;
	return true;
}
float Student::getMathGrade() {
	return mathGrade;
}

bool Student::setEnglishGrade(float grade) {
	if (grade < 1 || grade > 10)
		return false;
	englishGrade = grade;
	return true;
}
float Student::getEnglishGrade() {
	return englishGrade;
}

bool Student::setHistoryhGrade(float grade) {
	if (grade < 1 || grade > 10)
		return false;
	historyGrade = grade;
	return true;
}
float Student::getHistoryGrade() {
	return historyGrade;
}

float Student::avarageGrade() {
	return (mathGrade + englishGrade + historyGrade) / 3;
}