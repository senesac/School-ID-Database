#include "Student.h"

Student::Student() {
    m_ID = -1;
}

Student::Student(int id) {
    m_ID = id;
    m_sName = "";
    m_classLevel = "";
    m_major = "";
    m_GPA = 0.0;
    m_advisorID = -1;
}

Student::Student(int id, string n, string cl, string m, double gpa) {
    m_ID = id;
    m_sName = n;
    m_classLevel = cl;
    m_major = m;
    m_GPA = gpa;
    m_advisorID = -1;
}

Student::~Student() {

}

void Student::setID(int id) {
    m_ID = id;
}

void Student::setName(string n) {
    m_sName = n;
}

void Student::setClassLevel(string cl) {
    m_classLevel = cl;
}

void Student::setMajor(string m) {
    m_major = m;
}

void Student::setGPA(double gpa) {
    m_GPA = gpa;
}

void Student::setAdvisorID(int aID) {
    m_advisorID = aID;
}

int Student::getID() {
    return m_ID;
}

string Student::getName() {
    return m_sName;
}

string Student::getClassLevel() {
    return m_classLevel;
}

string Student::getMajor() {
    return m_major;
}

double Student::getGPA() {
    return m_ID;
}

int Student::getAdvisorID() {
    return m_advisorID;
}

bool Student::operator>(Student& compStd) {
    return (m_ID > compStd.m_ID);
}

bool Student::operator<(Student& compStd) {
    return (m_ID < compStd.m_ID);
}

bool Student::operator==(Student& compStd) {
    return (this->m_ID == compStd.m_ID);
}

bool Student::operator!=(Student& compStd) {
    return (this->m_ID != compStd.m_ID);
}

ostream& operator<<(ostream& os, const Student& s) {
    os << "\nStudent ID: " << s.m_ID
       << "\nStudent Name: " << s.m_sName
       << "\nStudent Class Level: " << s.m_classLevel
       << "\nStudent Major: " << s.m_major
       << "\nStudent GPA: " << s.m_GPA;
    if (s.m_advisorID == -1) {
        os << "\nStudent Advisor ID: N/A";
        os << "\n";
    } else {
        os << "\nStudent Advisor ID: " << s.m_advisorID;
        os << "\n";
    }
    return os;
}