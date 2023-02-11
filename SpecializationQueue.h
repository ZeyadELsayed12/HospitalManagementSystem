#ifndef HOSPITALMANAGEMENTSYSTEM_SPECIALIZATIONQUEUE_H
#define HOSPITALMANAGEMENTSYSTEM_SPECIALIZATIONQUEUE_H

#include "Patient.h"

class SpecializationQueue {
private :
    friend std::ostream & operator<<(std::ostream &os, const SpecializationQueue &s);
    Patient **patients;
    int size;
    int id;
public:
    explicit SpecializationQueue(int id) {
        patients = new Patient*[5];

        for (int i = 0; i < 5; ++i)
            patients[i] = nullptr;

        size = 0;
        this->id = id;
    }

    int getSize() const{
        return size;
    }

    void addRegular(std::string name, int spec, int status) {
        auto *p = new Patient(name,spec,status);
        patients[size++] = p;
    }

    void addUrgent(std::string name, int spec, int status) {
        auto *p = new Patient(name,spec,status);
        for(int i = size; i > 0; i--) {
            patients[i] = patients[i-1];
        }
        patients[0] = p;
        size++;
    }

    std::string removePatient() {
        std::string pName = patients[0]->getName();
        delete patients[0];
        for(int i = 0; i < size; i++) {
            patients[i] = patients[i+1];
        }
        size--;
        return pName;
    }

    void printSpec() const{
        std::cout << "Specialization # " << this->id << " Patients : \n";
        for(int i = 0; i < size; i++) {
            std::cout << *patients[i];
        }
    }

    ~SpecializationQueue() {
        for(int i = 0; i < 5 ; i++) {
            delete patients[i];
        }
        delete patients;
    }
};

std::ostream &operator<<(std::ostream &os, const SpecializationQueue &s) {
    s.printSpec();
    return os;
}

#endif
