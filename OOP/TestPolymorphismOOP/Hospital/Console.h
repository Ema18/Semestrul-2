//
// Created by Ema on 5/10/2017.
//

#ifndef HOSPITAL_CONSOLE_H
#define HOSPITAL_CONSOLE_H

#include <vector>
#include "Controller.h"
#include "Surgery.h"
#include "NeonatalUnit.h"
using namespace std;

class Exception
{
private:
    string message;

public:
    Exception(string message) : message{ message } {};
    string getMessage() { return message; };
};

class Console
{
private:
    Controller c;

public:

    Console(Controller _c) : c{ _c } {};

    int read_department()
    {
        int department;
        cout << "department: ";
        cin >> department;
        if (department != 1 && department != 2)
            throw Exception{ " Error: department Surgery or Neonatal\n" };
        return department;
    }

    void run()
    {
        HospitalDepartment* hd = new Surgery("HospitalName1", 20, 45);
        c.addDepartment(hd);

        while (true)
        {
            cout << "1. add department\n";
            cout << "2. show departments\n";
            cout << "3. show efficient departments\n";
            cout << "4. save to file\n";
            cout << "0. exit\n";
            int answer;
            cin >> answer;

            if (answer == 1)
                add_department();
            else if (answer == 2)
                show_departments();
            else if (answer == 3)
                show_efficient();
            else if (answer == 4)
                save_file();
            else if (answer == 0)
                return;
        }
    }

    void add_department()
    {
        cout << "1. Surgery\n";
        cout << "2. NeonatalUnit\n";

        int department;
        try
        {
            department = read_department();
        }
        catch (Exception& e)
        {
            cout << e.getMessage();
            return;
        }

        string hospitalName;
        cout << "Hospital name: ";
        cin >> hospitalName;

        int numberOfDoctors;
        cout << "Number of doctors: ";
        cin >> numberOfDoctors;

        if (department == 1) {
            int numberOfPatients;
            cout << "numberOfPatients: ";
            cin >> numberOfPatients;
            HospitalDepartment *department = new Surgery(hospitalName, numberOfDoctors, numberOfPatients);
            c.addDepartment(department);
            cout << "department efficiency " << (department->isEfficient() ? "yes" : "no");
            cout << "\n";
        }
        else if (department == 2)
        {
            int mothers, newborns;
            double grade;
            cout << "mothers: ";
            cin >> mothers;
            cout << "newborns: ";
            cin >> newborns;
            cout << "grade: ";
            cin >> grade;
            HospitalDepartment* d = new NeonatalUnit(hospitalName, numberOfDoctors, mothers, newborns, grade);
            c.addDepartment(d);
            cout << "department efficiency " << (d->isEfficient() ? "yes" : "no");
            cout << "\n";
        }
    }

    void show_departments()
    {
        for (HospitalDepartment* d : c.getDepartments())
        {
            cout << d->getDepartment() << ", " << d->toString() << "\n";
        }
    }

    void show_efficient()
    {
        for (HospitalDepartment* d : c.getAllEfficientDepartments())
        {
            cout << d->getDepartment() << ", " << d->toString() << "\n";
        }
    }

    void save_file()
    {
        c.writeToFile("C:\\Users\\Ema\\CLionProjects\\Hospital\\file.txt");
    }

    ~Console() {};
};
#endif //HOSPITAL_CONSOLE_H
