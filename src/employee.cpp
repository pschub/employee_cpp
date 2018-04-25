// This file contains the Employee Abstract class as well as its subclasses
// FullTimeEmployee, Contractor, and TempEmployee.

#include "employee.hpp"
#include <stdexcept>
#include <cmath>


// Create an Employee.
// name - name of employee
// years - years worked at this company (default: 0). Will throw
//         std::range_error if negative.
Employee::Employee(std::string name, double years) :
    years{years}, name{name}
{
    if (years < 0){
        throw std::range_error("Employee years cannot be negative.");
    }
}


// Return the name of the employee.
const std::string& Employee::getName() const
{
    return name;
}


// Return the number of vacation days accrued based on the years worked.
int Employee::getVacation() const
{
    return 0;
}


// Create a FullTimeEmployee
// name - name of employee
// years - years worked at this company (default: 0). Will throw
//         std::range_error if negative.
FullTimeEmployee::FullTimeEmployee(std::string name, double years) :
    Employee(name, years)
{
}


// Return the type of this employee as one of EmployeeType.
EmployeeType FullTimeEmployee::getType() const
{
    return EmployeeType::FULLTIME;
}


// Return the number of vacation days earned. Full-timers get vacation! :)
int FullTimeEmployee::getVacation() const
{
    return std::floor(years) * FullTimeEmployee::VACATION_DAYS_PER_YEAR;
}


// Create a Contractor.
// name - name of employee
// years - years worked at this company (default: 0). Will throw
//         std::range_error if negative.
Contractor::Contractor(std::string name, double years) :
    Employee(name, years)
{
}


// Return the type of this employee as one of EmployeeType.
EmployeeType Contractor::getType() const
{
    return EmployeeType::CONTRACTOR;
}


// Create a TempEmployee.
// name - name of employee
// years - years worked at this company (default: 0). Will throw
//         std::range_error if negative.
TempEmployee::TempEmployee(std::string name, double years) :
    Employee(name, years)
{
}


// Return the type of this employee as one of EmployeeType.
EmployeeType TempEmployee::getType() const
{
    return EmployeeType::TEMPORARY;
}

