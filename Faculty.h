#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
using namespace std;

class Faculty{
    public:
        Faculty();
        Faculty(int id);
        Faculty(int id, string n, string p, string d);
        virtual ~Faculty();
        void setID(int id);
        void setName(string n);
        void setProfession(string cl);
        void setDepartment(string m);
        int getID();
        string getName();
        string getProfession();
        string getDepartment();
        bool operator>(Faculty& compFac);
        bool operator<(Faculty& compFac);
        bool operator==(Faculty& compFac);
        bool operator!=(Faculty& compFac);
        friend ostream& operator<<(ostream& os, const Faculty& f);
        void initializeAIDList();
        void addAdvisee(int sID);
        void removeAdvisee(int id);
        int getAdviseeID(int i);
    private:
        int m_ID;
        string m_fName;
        string m_profession;
        string m_department;
        int m_adviseeList[10];
};

#endif