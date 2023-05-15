#include "Database.h"
#include <iostream>

Database::Database(){

}

Database::~Database(){

}

void Database::insertStudent() {
    Student tempS;
    int id;
    double gpa;
    string temp;
    cout << "Add a student's information: " << endl;
    cout << "\n   Insert Student ID: ";
    cin >> id;
    while (!cin.good()) {
        cout << "\n   Invalid response, Enter Student ID: ";
        cin.clear();
        cin.ignore();
        cin >> id;
    }
    tempS.setID(id);
    cin.clear();
    cin.ignore();

    cout << "\n   Insert Student Name: ";
    getline(cin, temp);
    tempS.setName(temp);
    cin.clear();

    cout << "\n   Insert Student Grade Level: ";
    getline(cin, temp);
    tempS.setClassLevel(temp);
    cin.clear();

    cout << "\n   Insert Student Major: ";
    getline(cin, temp);
    tempS.setMajor(temp);
    cin.clear();

    cout << "\n   Insert Student GPA: ";
    cin >> gpa;
    while (!cin.good()) {
        cout << "\n   Invalid response, Enter Student GPA: ";
        cin.clear();
        cin.ignore();
        cin >> gpa;
    }
    tempS.setGPA(gpa);
    cin.clear();
    cin.ignore();

    cout << "\n   Insert Advisor ID: ";
    cin >> id;
    while (!cin.good()) {
        cout << "\n   Invalid response, Enter Advisor ID: ";
        cin.clear();
        cin.ignore();
        cin >> id;
    }
    cin.clear();
    cin.ignore();

    studentTree->insert(tempS);
    
    addAdvisorID(tempS.getID(), id);
}

void Database::insertFaculty() {
    Faculty tempF;
    int id;
    string temp;
    cout << "Add a faculty's information: " << endl;
    cout << "\n   Insert Faculty ID: ";
    cin >> id;
    while (!cin.good()) {
        cout << "\n   Invalid response, Enter Faculty ID: ";
        cin.clear();
        cin.ignore();
        cin >> id;
    }
    tempF.setID(id);
    cin.clear();
    cin.ignore();

    cout << "\n   Insert Faculty Name: ";
    getline(cin, temp);
    tempF.setName(temp);
    cin.clear();

    cout << "\n   Insert Faculty's Profession: ";
    getline(cin, temp);
    tempF.setProfession(temp);
    cin.clear();

    cout << "\n   Insert Faculty's Department: ";
    getline(cin, temp);
    tempF.setDepartment(temp);
    cin.clear();

    tempF.initializeAIDList();

    cout << "\n   Insert Advisee ID or Enter 0 to not add an Advisee: ";
    cin >> id;
    while (!cin.good()) {
        cout << "\n   Invalid response, Enter Advisor ID: ";
        cin.clear();
        cin.ignore();
        cin >> id;
    }
    cin.clear();
    cin.ignore();

    facultyTree->insert(tempF);

    if (id != 0) {
        Student tempS(id);
        removeAdviseeID(id, studentTree->find(tempS)->getData().getAdvisorID());
        addAdvisorID(id, tempF.getID());
    }
}

void Database::addAdvisorID(int SID, int FID) {
    Student tempS(SID);
    Faculty tempF(FID);
    bool hasSID = studentTree->contains(tempS);
    bool hasFID = facultyTree->contains(tempF);
    if (hasSID && hasFID) {
        studentTree->find(tempS)->getData().setAdvisorID(FID); // First call find() to find the student, then return student and call setAdvisorID()
        facultyTree->find(tempF)->getData().addAdvisee(SID);
    } else {
        cout << "Invalid Student or Faculty ID" << endl;
    }
}

void Database::removeAdviseeID(int SID, int FID) {
    Faculty tempF(FID);
    Student tempS(SID);
    bool hasFID = facultyTree->contains(tempF);
    bool hasSID = studentTree->contains(tempS);
    if (hasFID && hasSID) {
        if(studentTree->find(tempS)->getData().getAdvisorID() == facultyTree->find(tempF)->getData().getID()) {
            studentTree->find(tempS)->getData().setAdvisorID(-1);
            facultyTree->find(tempF)->getData().removeAdvisee(SID);
        }
    }
}

// function to balance
    // make an arr[] of students in order from previous BST
    // delete previous BST with Deconstructor
    // take arr[] and recursively find mid points and input into new arrMid[] in the order of which the midpoints are found 

void Database::chooseOption(){
    int x;
    int search;
    int SID, FID;
    bool isNotBal;
    do {
        std::cout << "\nWelcome! Here are your options: " << std::endl;
        std::cout << "1. Print all students and their information (sorted by ascending id #)" << std::endl;
        std::cout << "2. Print all faculty and their information (sorted by ascending id #)" << std::endl;
        std::cout << "3. Find and display student information given the student id" << std::endl;
        std::cout << "4. Find and display faculty information given the faculty id" << std::endl;
        std::cout << "5. Add a new student" << std::endl;
        std::cout << "6. Delete a student given the id" << std::endl;
        std::cout << "7. Add a new faculty member" << std::endl;
        std::cout << "8. Delete a faculty member given the id." << std::endl;
        std::cout << "9. Change a student’s advisor given the student id and the new faculty id." << std::endl;
        std::cout << "10. Remove an advisee from a faculty member given the ids" << std::endl;
        std::cout << "11. Exit" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> x;
        switch (x){
            case 1:
            {
                studentTree->printInOrder();
                break;
            }
            case 2:
            {
                facultyTree->printInOrder();
                break;
            }
            case 3:
            {
                cout << "Enter Student ID to search: ";
                cin >> search;
                Student sTemp(search);
                studentTree->contains(sTemp);
                break;
            }
            case 4:
            {
                cout << "Enter Faculty ID to search: ";
                cin >> search;
                Faculty fTemp(search);
                facultyTree->contains(fTemp);
                break;
            }
            case 5:
            {
                insertStudent();
                // isNotBal = studentTree->checkDepthRatio();
                // if (isNotBal) {
                //     cout << "The function is not balanced\n";
                //     // call function to rebalance
                // } else {
                //     cout << "The function is balanced\n";
                // }
                break;
            }
            case 6:
            {
                cout << "Enter Student ID to remove: ";
                cin >> search;
                Student sDel(search);
                removeAdviseeID(search, studentTree->find(sDel)->getData().getAdvisorID());
                studentTree->remove(sDel);
                break;
            }
            case 7:
            {    
                insertFaculty();
                cout << "\nThis is the mindepth of the tree: " << facultyTree->getMinDepth() << endl;
                cout << "\nThis is the maxdepth of the tree: " << facultyTree->getMaxDepth() << endl;
                // isNotBal = facultyTree->checkDepthRatio();
                // if (isNotBal) {
                //     cout << "The function is not balanced\n";
                //     // call function to rebalance
                // } else if (!isNotBal) {
                //     cout << "The function is balanced\n";
                // }
                break;
            }
            case 8:
            {
                int arr[10];
                cout << "Enter Faculty ID to remove: ";
                cin >> search;
                Faculty fDel(search);
                for (int i = 0; i < 10; ++i) {
                    removeAdviseeID(facultyTree->find(fDel)->getData().getAdviseeID(i), search);
                }
                facultyTree->remove(fDel);
                break;
            }
            case 9:
            {  
                cout << "Enter a Student ID: ";
                cin >> SID;
                cout << "Enter a Faculty ID: ";
                cin >> FID;
                addAdvisorID(SID, FID);
                break;
            }
            case 10:
            {
                cout << "Enter a Student ID: ";
                cin >> SID;
                cout << "Enter a Faculty ID: ";
                cin >> FID;
                removeAdviseeID(SID, FID);
                break;
            }
            case 11:
            {
                cout << "Thank you" << endl;
                break;
            }
            default:
            {
                std::cout << "Invalid option. Choose an option between 1-11:" << std::endl;
                chooseOption();
            }

        }
    } while (x != 11);

    
}