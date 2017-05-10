//
// Created by Ema on 5/10/2017.
//

#ifndef HOSPITAL_SURGERY_H
#define HOSPITAL_SURGERY_H

#include "HospitalDepartment.h"
#include <sstream>

class Surgery : public HospitalDepartment
{
private:
    int numberOfPatients;

public:
    Surgery(string hospitalName, int numberOfDoctors, int numberOfPatients) : HospitalDepartment(hospitalName, numberOfDoctors), numberOfPatients(numberOfPatients) {};

    bool isEfficient() override
    {
        return numberOfPatients/numberOfDoctors >= 2;
    }

    string toString() override
    {
        stringstream s;
        s << HospitalDepartment::toString() << ", NoPatients: " << numberOfPatients << ", isEfficient: " << isEfficient();
        return s.str();
    }

    string getDepartment() override
    {
        return "Surgery";
    }
};

#endif //HOSPITAL_SURGERY_H
