// This file contains the declaration of the Employee Abstract class as well as
// its subclasses FullTimeEmployee, Contractor, and TempEmployee.

#pragma once
#include <string>


// Enumerate the types of employees.
enum class EmployeeType { FULLTIME, CONTRACTOR, TEMPORARY };


class Employee {
    // Abstract class representing an employee. Has fields for name, years of
    // service, and employment type. Can request the number of vacation days
    // earned. To instantiate an Employee, use one of the child classes
    // FullTimeEmployee, Contractor, or TempEmployee.
public:
    double years;  // Years of service.

    // Create an Employee.
    // name - name of employee
    // years - years worked at this company (default: 0). Will throw
    //         std::range_error if negative.
    Employee(std::string name, double years=0);

    // Return the name of the employee.
    const std::string& getName() const;

    // Return the type of the employee (as one of EmployeeType).
    virtual EmployeeType getType() const = 0;

    // Return the number of vacation days accrued based on the years worked.
    virtual int getVacation() const;

private:
    std::string name;   // The name of the employee.
};


class FullTimeEmployee : public Employee{
    // A FullTimeEmployee is an Employee that earns vacation days.
public:
    // Create a FullTimeEmployee
    // name - name of employee
    // years - years worked at this company (default: 0). Will throw
    //         std::range_error if negative.
    FullTimeEmployee(std::string name, double years=0);

    // Return the type of this employee as one of EmployeeType.
    virtual EmployeeType getType() const;

    // Return the number of vacation days earned. Full-timers get vacation! :)
    virtual int getVacation() const;

private:
    static const int VACATION_DAYS_PER_YEAR = 5;
};


class Contractor : public Employee {
public:
    // Create a Contractor.
    // name - name of employee
    // years - years worked at this company (default: 0). Will throw
    //         std::range_error if negative.
    Contractor(std::string name, double years=0);

    // Return the type of this employee as one of EmployeeType.
    virtual EmployeeType getType() const;
};


class TempEmployee : public Employee {
public:
    // Create a TempEmployee.
    // name - name of employee
    // years - years worked at this company (default: 0). Will throw
    //         std::range_error if negative.
    TempEmployee(std::string name, double years=0);

    // Return the type of this employee as one of EmployeeType.
    virtual EmployeeType getType() const;
};

