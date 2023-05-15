#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        Student();
        Student(int id);
        Student(int id, string n, string cl, string m, double gpa);
        virtual ~Student();
        void setID(int id);
        void setName(string n);
        void setClassLevel(string cl);
        void setMajor(string m);
        void setGPA(double gpa);
        void setAdvisorID(int aID);
        int getID();
        string getName();
        string getClassLevel();
        string getMajor();
        double getGPA();
        int getAdvisorID();
        bool operator>(Student& compStd);
        bool operator<(Student& compStd);
        bool operator==(Student& compStd);
        bool operator!=(Student& compStd);
        friend ostream& operator<<(ostream& os, const Student& s);
    private:
        int m_ID;
        string m_sName;
        string m_major;
        string m_classLevel;
        double m_GPA;
        int m_advisorID;
};

#endif