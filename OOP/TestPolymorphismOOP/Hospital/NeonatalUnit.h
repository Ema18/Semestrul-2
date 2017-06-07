//
// Created by Ema on 5/10/2017.
//

#ifndef HOSPITAL_NEONATALUNIT_H
#define HOSPITAL_NEONATALUNIT_H

#include "HospitalDepartment.h"
#include <sstream>

class NeonatalUnit : public HospitalDepartment
{
private:
    int numberOfMothers;
    int numberOfNewborns;
    double averageGrade;

public:
    NeonatalUnit(string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns, double averageGrade) : HospitalDepartment(hospitalName, numberOfDoctors), numberOfMothers(numberOfMothers), numberOfNewborns(numberOfNewborns), averageGrade(averageGrade) {};

    bool isEfficient() override
    {
        return averageGrade > 8.5 && numberOfNewborns >= numberOfMothers;
    }

    string toString() override
    {
        stringstream s;
        s << HospitalDepartment::toString() << ", NoMothers: " << numberOfMothers << ", NoNewborns: " << numberOfNewborns << ", Average grade: " << averageGrade << ", isEfficient: " << isEfficient();
        return s.str();
    }

    string getDepartment() override
    {
        return "Neonatal";
    }
};
#endif //HOSPITAL_NEONATALUNIT_H
