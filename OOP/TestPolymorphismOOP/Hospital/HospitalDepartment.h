//
// Created by Ema on 5/10/2017.
//

#ifndef HOSPITAL_HOSPITALDEPARTMENT_H
#define HOSPITAL_HOSPITALDEPARTMENT_H

#pragma once

#include <sstream>

using namespace std;

class HospitalDepartment
{
protected:
    string hospitalName;
    int numberOfDoctors;

public:
    HospitalDepartment(string hospitalName, int numberOfDoctors) : hospitalName(hospitalName), numberOfDoctors(numberOfDoctors) {};

    virtual bool isEfficient() = 0;

    virtual string toString()
    {
        stringstream s;
        s << "Hospital name: " << hospitalName << ", NoDoctors: " << numberOfDoctors;
        return s.str();
    }

    virtual string getDepartment() = 0;

    string getHospitalName() { return this->hospitalName; }

    int getNumberOfDoctors() { return this->numberOfDoctors; }

};

#endif //HOSPITAL_HOSPITALDEPARTMENT_H
