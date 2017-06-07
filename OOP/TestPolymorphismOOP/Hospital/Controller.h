//
// Created by Ema on 5/10/2017.
//

#ifndef HOSPITAL_CONTROLLER_H
#define HOSPITAL_CONTROLLER_H

#include <string>
#include "HospitalDepartment.h"
#include <fstream>
#include <vector>

using namespace std;

class Controller
{
private:
    string name;
    vector<HospitalDepartment*> departments;

public:
    void addDepartment(HospitalDepartment* d)
    {
        departments.push_back(d);
    }

    vector<HospitalDepartment*> getDepartments()
    {
        return departments;
    }

    vector<HospitalDepartment*> getAllEfficientDepartments()
    {
        vector<HospitalDepartment*> aux;

        for (HospitalDepartment* d : departments)
            if (d->isEfficient())
                aux.push_back(d);
        return aux;
    }

    void writeToFile(string filename)
    {
        vector<HospitalDepartment*> aux = this->getDepartments();
        HospitalDepartment* auxi;
        for (int i = 0; i < aux.size(); i++)
            for (int j = i; j < aux.size(); j++)
            {
                if (aux[i]->getHospitalName() > aux[j]->getHospitalName())
                {
                    auxi = aux[i];
                    aux[i] = aux[j];
                    aux[j] = auxi;
                }
            }

        ofstream f(filename);
        for (HospitalDepartment* d : aux)
        {
            f << d->getDepartment() << ", " << d->toString() << "\n";
        }
        f.close();
    }

};
#endif //HOSPITAL_CONTROLLER_H
