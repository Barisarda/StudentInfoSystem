#include<iostream>
#include "Student.h"
#include <list>
using namespace std;


void showMenu() {
	cout << "* * * * * * * * * * * * *" << endl;
	cout << "*                       *" << endl;
	cout << "*         MENU          *" << endl;
	cout << "*                       *" << endl;
	cout << "* * * * * * * * * * * * *" << endl;
	cout << "1. Add new student" << endl;
	cout << "2. Show all the list" << endl;
	cout << "3. Delete the student according to Student id." << endl;
	cout << "4. Search for student." << endl;
	cout << "5. Exit" << endl;
}

void addStudent(list<Student>* lst) {
	int id;
	char name[30];
	int examGrade;
	cout << "Please enter the student id: " << endl;
	cin >> id;
	cout << "Enter the Student's Name: " << endl;
	cin >> name ;
	cout << "Enter the Exam Grade: " << endl;
	cin >> examGrade;
	Student std(id, name, examGrade);
	lst->push_back(std);
}

void showList(list<Student>* lst) {
	list<Student>::iterator it;
	cout << endl << "- - - - Student List - - - -\n";
	for (it = lst->begin(); it != lst->end(); it++) {
		it->writeInfos();
	}
	cout << endl;
}

void deleteStudent(list<Student>* lst) {
	int id;
	cout << "Please enter the id of the student to be deleted: ";
	cin >> id;
	list<Student>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++) {
		if (it->getId() == id)
			break;
	}
	if (it == lst->end())
		cout << "Id cannot found. Deletion could not be done";
	else
	    lst->erase(it);
}

void searchStudent(list<Student>* lst) {
	int id;
	cout << "Please enter the id of the student to be searched: ";
	cin >> id;
	list<Student>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++) {
		if (it->getId() == id)
			break;
		if (it == lst->end())
			cout << "Id cannot found.";
		else
			cout << endl << "Student's infos that you searched for: \n";
		it->writeInfos();
		cout << endl;
	}
}
int main() {

	list<Student>* studentList = new list<Student>();

	int choice = 0;
	do {
		showMenu();
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 1)
			addStudent(studentList);
		else if (choice == 2)
			showList(studentList);
		else if (choice == 3)
			deleteStudent(studentList);
		else if (choice == 4)
			searchStudent(studentList);
		else if (choice == 5)
			break;
		else
			cout << "You made wrong choice ,please try again!" << endl;
	} while (choice != 5);

	return 0;
}
