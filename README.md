# Employee in C++
Patrick Schubert, April 2018

This project demonstrates an Employee class in C++. The following files are in this project:  

* inc/employee.hpp, src/employee.cpp - the Employee abstract class and subclasses.
* main.cpp - a demo of Employee, which creates a bunch of employees and prints their info.  
* test/RunAllTests.cpp - test runner  
* test/employeeTest.cpp - contains all tests for Employee classes.  
* Makefile - Builds Employee, demo, and runs tests.  
* README.md - this file.


## Employee Class
### Types
The employer for this project has 3 types of employees: 

* Fulltime
* Contractors
* Temporary

### Longevity
All employees have a period of time they have been employed by the company.

### Vacation
Full-time employees accrue vacation at a rate of 5 days per full year of service.
Contractors and temporary staff do not accrue vacation days.

## Exercise
Write a program to output to screen information about a list of employees.   For each employee, print the name of the employee with a suffix indicating whether the employee is a Full-time employee [FT], contractor [C], or temporary [T], Duration of service, and vacation accrued.

**Example 1**  
Fred Johnson, Fulltime, 1.5 years of service  
**Expected output:**  
Name:  Fred Johnson [FT], Duration:  1.5 years, Vacation Accrued:  5 days  

**Example 2**  
Jane James, Contractor, 0.8 years of service  
**Expected output:**  
Name:  Jane James [C], Duration:  0.8 years, Vacation Accrued:  None  

Create a data set of your choosing which demonstrates your object code being exercised.

