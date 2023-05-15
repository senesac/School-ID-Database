#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "Database.h"

using namespace std;

int main() {
    Database database;
    database.chooseOption();

    BST<Student>* studentTree = new BST<Student>;
    BST<Faculty>* facultyTree = new BST<Faculty>;
    Student student1(72, "Dominick Deleon", "Junior", "CompSci", 4.0);
    Student student2(34, "Dominick Deleon", "Junior", "CompSci", 4.0);
    Student student3(11, "Dominick Deleon", "Junior", "CompSci", 4.0);
    Student student4(89, "Dominick Deleon", "Junior", "CompSci", 4.0);
    Student student5(45, "Dominick Deleon", "Junior", "CompSci", 4.0);
    Student student6(37, "Dominick Deleon", "Junior", "CompSci", 4.0);
    Faculty faculty1(12, "Elia Lledo", "Professor", "Compsci");
    cout << faculty1;

    // faculty1.addAdvisee(72);

    // cout << faculty1;

    // studentTree->insert(student1);
    // studentTree->insert(student2);
    // studentTree->insert(student3);
    // studentTree->insert(student4);
    // studentTree->insert(student5);
    // studentTree->insert(student6);
    // facultyTree->insert(faculty1);

    // studentTree->printInOrder();

    // studentTree->remove(student6);

    // studentTree->printInOrder();

    // facultyTree->printInOrder();

    // Student temp(72);

    // bool contains = studentTree->contains(temp);


}
