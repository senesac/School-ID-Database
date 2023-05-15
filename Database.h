#ifndef Database_H
#define Database_H

#include "BST.h"
#include "Faculty.h"
#include "Student.h"
#include <iostream>

class Database{
    public:
        Database();
        virtual ~Database();
        void insertStudent();
        void insertFaculty();
        void chooseOption();
        void addAdvisorID(int SID, int FID);
        void removeAdviseeID(int SID, int FID);

    private:
        BST<Student>* studentTree = new BST<Student>;
        BST<Faculty>* facultyTree = new BST<Faculty>;
};



#endif