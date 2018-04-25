// This is a demonstration of Employee classes. It creates a small list of
// employees and prints their details to stdout.

#include <iostream>
#include "employee.hpp"
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::endl;

void printEmployee(const Employee* person);


int main()
{
    std::vector<Employee*> people;

    // Create list of employees.
    people.push_back(new FullTimeEmployee("Alice"));
    people.push_back(new FullTimeEmployee("Bob", 4.3));
    people.push_back(new FullTimeEmployee("Charles", 8));
    people.push_back(new TempEmployee("David", 0.5));
    people.push_back(new Contractor("Erin"));
    people.push_back(new Contractor("Francis", 4));

    // Foreach employee, print their stats.
    for (auto person : people){
        printEmployee(person);
    }

    return 0;
}


// Print the details of an employee to stdout.
void printEmployee(const Employee* person)
{
    // Create abbreviation for employee type.
    string typeString;
    switch(person->getType()){
        case (EmployeeType::FULLTIME):   typeString = "FT"; break;
        case (EmployeeType::CONTRACTOR): typeString = "C"; break;
        case (EmployeeType::TEMPORARY):  typeString = "T"; break;
        default: typeString = "?"; break;
    }

    // Print the details.
    cout << "Name: " << person->getName();
    cout << " [" << typeString << "]";
    cout << ", Duration: " << person->years;
    cout << ", Vacation Accrued: ";

    // If vacation days are 0, say "none" rather than "0 days".
    int vacationDays = person->getVacation();
    if (vacationDays){
        cout << vacationDays << " days";
    } else {
            cout << "None";
    }

    cout << endl;

    return;
}

