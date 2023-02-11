#ifndef HOSPITALMANAGEMENTSYSTEM_PATIENT_H
#define HOSPITALMANAGEMENTSYSTEM_PATIENT_H
#include <string>
#include <iostream>
class Patient {
private:
    friend std::ostream & operator<<(std::ostream &os, const Patient &p);
    std::string name;
    int spec;
    int status;
public:
    Patient(std::string &n, int sp, int st) {
        name = n;
        spec = sp;
        status = st;
    }
    std::string getName() const {
        return name;
    }
    void printPatient() const {
        std::cout << "Patient Name : " << name << ", requested spec : " << spec << ", Status : " << status << std::endl;
    }
};
std::ostream &operator<<(std::ostream &os, const Patient &p) {
    p.printPatient();
    return os;
}


#endif
