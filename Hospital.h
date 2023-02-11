#ifndef HOSPITALMANAGEMENTSYSTEM_HOSPITAL_H
#define HOSPITALMANAGEMENTSYSTEM_HOSPITAL_H

#include "SpecializationQueue.h"
#include <vector>
class Hospital {
private:
    friend std::ostream & operator<<(std::ostream &os, const Hospital &h);
    std::vector<SpecializationQueue *> hospital;
public:

    Hospital() {
        for(int i = 0; i < 20; i++) {
            auto * temp = new SpecializationQueue(i+1);
            hospital.push_back(temp);
        }
    }

    bool addPatient(const std::string& name, int spec, int status) {
        if(hospital[spec-1]->getSize() < 5) {
            if (status == 0)
                hospital[spec - 1]->addRegular(name, spec, status);
            else
                hospital[spec - 1]->addUrgent(name, spec, status);

            return true;
        }
        else {
            return false;
        }
    }

    std::string pickUpPatient(int spec) {
        if(hospital[spec-1]->getSize() > 0) {
            std::string pName = hospital[spec-1]->removePatient();
            return pName;
        }
        else {
            return std::string{"None"};
        }
    }

    void printAllPatients() const {
        for(int i = 0; i < 20; i++) {
            if(hospital[i]->getSize())
                std::cout << *hospital[i] << std::endl;
        }
    }

};

std::ostream &operator<<(std::ostream &os, const Hospital &h) {
    h.printAllPatients();
    return os;
}


#endif
