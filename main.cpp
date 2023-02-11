#include <iostream>
#include <string>
#include "Hospital.h"

using namespace std;

void printDmenu() {
    cout << "==================================" << endl;
    cout << "Welcome to the Hospital, Enter " << endl;
    cout << "1 : Add new Patient" << endl;
    cout << "2 : Print all Patients" << endl;
    cout << "3 : Pick next Patient" << endl;
    cout << "4 : Exit" << endl;

}

void takeInput(Hospital *h) {

    string name;
    int spec, status;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter specialization : ";
    cin >> spec;
    cout << "Enter Status 0 : Regular, 1 : Urgent : ";
    cin >> status;

    bool accepted = h->addPatient(name,spec,status);

    if(accepted) {
        cout << "Your request is accepted !" << endl;
        cout << "Wait until Your turn comes" << endl;
    }
    else {
        cout << "Sorry, we cannot accept your request now " << endl;
        cout << "The queue is full, Try again later." << endl;
    }

}

void pickNextPatient(Hospital *h) {
    int spec;
    cout << "Please Enter Your specialization : ";
    cin >> spec;

    auto patientName = h->pickUpPatient(spec);

    if(patientName != "None") {
        cout << "Please enter, " << patientName << " This is your turn." << endl;
    }
    else {
        cout << "There is no patients, Take rest, Dr." << endl;
    }

}

int main() {
    auto *h = new Hospital;
    int select;
    do {
        printDmenu();
        cout << "Your input : ";
        cin >> select;
        cout << "==================================" << endl;
        switch (select) {
            case 1: takeInput(h);
                    break;
            case 2: std::cout << *h;
                    break;
            case 3: pickNextPatient(h);
                    break;
            case 4: cout << "Thank you for using our App !";
                    break;
            default: std::cout << "Invalid Input, Please Try again." << std::endl;
        }
    } while (select != 4);
    system("pause");
    return 0;
}
