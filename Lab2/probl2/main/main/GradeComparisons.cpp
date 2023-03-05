#include "GradeComparisons.h"
#include <cstring>

int compareNames(Student &firstStudent, Student &secondStudent) {
	if (strcmp(firstStudent.getName(), secondStudent.getName()) == 0) {
		return 0;
	}
	else if (strcmp(firstStudent.getName(), secondStudent.getName()) < 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int compareMathGrades(Student &firstStudent, Student &secondStudent) {
	if (firstStudent.getMathGrade() == secondStudent.getMathGrade()) {
		return 0;
	}
	else if (firstStudent.getMathGrade() < secondStudent.getMathGrade()) {
		return -1;
	}
	else {
		return 1;
	}
}
int compareEnglishGrades(Student &firstStudent, Student &secondStudent) {
	if (firstStudent.getEnglishGrade() == secondStudent.getEnglishGrade()) {
		return 0;
	}
	else if (firstStudent.getEnglishGrade() < secondStudent.getEnglishGrade()) {
		return -1;
	}
	else {
		return 1;
	}
}
int compareHistoryGrades(Student &firstStudent, Student &secondStudent) {
	if (firstStudent.getHistoryGrade() == secondStudent.getHistoryGrade()) {
		return 0;
	}
	else if (firstStudent.getHistoryGrade() < secondStudent.getHistoryGrade()) {
		return -1;
	}
	else {
		return 1;
	}
}

int compareAverageGrades(Student &firstStudent, Student &secondStudent) {
	if (firstStudent.avarageGrade() == secondStudent.avarageGrade()) {
		return 0;
	}
	else if (firstStudent.avarageGrade() < secondStudent.avarageGrade()) {
		return -1;
	}
	else {
		return 1;
	}
}