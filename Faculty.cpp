#include "Faculty.h"

Faculty::Faculty() {
    m_ID = -1;
}

Faculty::Faculty(int id) {
    m_ID = id;
    m_fName = "";
    m_profession = "";
    m_department = "";
    m_adviseeList [0] = -1;
}

Faculty::Faculty(int id, string n, string p, string d) {
    m_ID = id;
    m_fName = n;
    m_profession = p;
    m_department = d;
    for (int i = 0; i < 10; ++i) {
        m_adviseeList[i] = -1;
    }
}

Faculty::~Faculty() {
    
}

void Faculty::setID(int id) {
    m_ID = id;
}

void Faculty::setName(string n) {
    m_fName = n;
}

void Faculty::setProfession(string p) {
    m_profession = p;
}

void Faculty::setDepartment(string d) {
    m_department = d;
}

int Faculty::getID() {
    return m_ID;
}

string Faculty::getName() {
    return m_fName;
}

string Faculty::getProfession() {
    return m_profession;
}

string Faculty::getDepartment() {
    return m_department;
}

bool Faculty::operator>(Faculty& compFac) {
    return (m_ID > compFac.m_ID);
}

bool Faculty::operator<(Faculty& compFac) {
    return (m_ID < compFac.m_ID);
}

bool Faculty::operator==(Faculty& compFac) {
    return (this->m_ID == compFac.m_ID);
}

bool Faculty::operator!=(Faculty& compFac) {
    return (this->m_ID != compFac.m_ID);
}

ostream& operator<<(ostream& os, const Faculty& f) {
    os << "\nFaculty ID: " << f.m_ID
       << "\nFaculty Name: " << f.m_fName
       << "\nFaculty Profession: " << f.m_profession
       << "\nFaculty Department: " << f.m_department;
    if (f.m_adviseeList[0] == -1) {
        os << "\nFaculty Advisee List: N/A";
        os << "\n";
    } else {
        os << "\nFaculty Advisee ID List: ";
        for (int i = 0; i < 10; ++i) { 
            if (f.m_adviseeList[i] != -1 && f.m_adviseeList[i] != 0) {
                os << f.m_adviseeList[i] << " ";
            }
        }
        os << "\n";
    }
    return os;
}

void Faculty::initializeAIDList() {
    for (int i = 0; i < 10; ++i) {
        m_adviseeList[i] = -1;
    }
}

void Faculty::addAdvisee(int id) { 
    int i = 0;
    while (i < 10 && m_adviseeList[i] != -1) {
        if(m_adviseeList[i] == id) {
            i = 10;
            break;
        }
        i++;
    }
    if (i < 10) {
        m_adviseeList[i] = id;
    }
}

void Faculty::removeAdvisee(int id) {
    for (int i = 0; i < 10; ++i) {
        if (m_adviseeList[i] == id) {
            m_adviseeList[i] = 0;
        }
    }
}

int Faculty::getAdviseeID(int i) {
    if (m_adviseeList[i] != 0 && m_adviseeList[i] != -1) {
        return m_adviseeList[i];
    }
    return 0;
}