#include<iostream>
#include "Student.h"


using namespace std;

Student::Student(int _id, string _name, int _examGrade) {
	id = _id;
	name = _name;
	examGrade = _examGrade;
}

void Student::setId(int _id) {
	id = _id;
}
void Student::setName(string  _name) {
	name = _name;
}
void Student::setExamGrade(int _examGrade) {
	examGrade = _examGrade;
}
int Student::getId() {
	return id;
}
string Student::getName() {
	return name;
}
int Student::getExamGrade() {
	return examGrade;
}
void Student::writeInfos() {
	cout << "id: " << id << " name: " << name << " Exam Grade: " << examGrade << endl;
}
