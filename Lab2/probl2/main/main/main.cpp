#include <iostream>
#include "Student.h"
#include "GradeComparisons.h"

using namespace std;

void handleComparison(int result, Student firstStudent, Student secondStudent) {
	if (result == 0) {
		cout << firstStudent.getName() << " and " << secondStudent.getName() << " are equal" << endl;
	}
	else if (result == -1) {
		cout << secondStudent.getName() << " is first" << endl;
	}
	else {
		cout << firstStudent.getName() << " is first" << endl;
	}
}

int main()
{
	Student s1, s2;
	char name1[] = "Alin", name2[] = "Razvan";
	s1.setName(name1), s2.setName(name2);
	s1.setMathGrade(6), s2.setMathGrade(5);
	s1.setEnglishGrade(7), s2.setEnglishGrade(6);
	s1.setHistoryhGrade(5), s2.setHistoryhGrade(7);

	cout << "Compared by name, ", handleComparison(compareNames(s1, s2), s1, s2);
	cout << "Compared by math grades, ", handleComparison(compareMathGrades(s1, s2), s1, s2);
	cout << "Compared by english grades, ", handleComparison(compareEnglishGrades(s1, s2), s1, s2);
	cout << "Compared by history grades, ", handleComparison(compareHistoryGrades(s1, s2), s1, s2);
	cout << "Compared by average grades, ", handleComparison(compareAverageGrades(s1, s2), s1, s2);
	return 0;
}
