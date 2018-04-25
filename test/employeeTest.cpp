// This file includes all Employee Class related tests.

#include <gtest/gtest.h>
#include "employee.hpp"
#include <string>
#include <exception>
#include <cmath>

using std::string;

// Number of vacation days per year for fulltime employees.
const double VACATION_DAYS_PER_YEAR{5};


// Test that we can access the employees name.
TEST(EmployeeNameTests, HasName)
{
    string name{"Joe"};
    FullTimeEmployee person = FullTimeEmployee(name);
    EXPECT_EQ(name, person.getName());
}


// Test that we can access # of years worked.
TEST(EmployeeYearsTests, HasYears)
{
    double years = 4.0;
    FullTimeEmployee person{"Jane", years};
    EXPECT_EQ(years, person.years);
}


// Test that construction of employee with negative years fails.
TEST(EmployeeYearsTests, NegativeYears)
{
    double years = -2.0;
    bool raisedException = false;
    try {
        FullTimeEmployee person{"Joe", years};
    }
    catch (std::range_error& e) {
        raisedException = true;
    }
    EXPECT_TRUE(raisedException) << "Error: Accepted negative years";
}


// Test that the fulltime employee reports as FullTime
TEST(EmployeeTypeTests, Fulltime)
{
    FullTimeEmployee person{"Jane"};
    EXPECT_EQ(EmployeeType::FULLTIME, person.getType());
}


// Test that contractor reports as a contractor.
TEST(EmployeeTypeTests, Contractor)
{
    Contractor person{"Jane", 33};
    EXPECT_EQ(EmployeeType::CONTRACTOR, person.getType());
}


// Test that temp employee reports as temp.
TEST(EmployeeTypeTests, Temporary)
{
    TempEmployee person{"Jane", 4};
    EXPECT_EQ(EmployeeType::TEMPORARY, person.getType());
}


// Test for expected vacation for new hire (should be 0).
TEST(EmployeeVacationTests, NewFulltime)
{
    double years = 0;
    int expected = VACATION_DAYS_PER_YEAR * floor(years);
    FullTimeEmployee person{"Jane", years};
    EXPECT_EQ(expected, person.getVacation());
}


// Test for expected vacation days with some years at the company.
TEST(EmployeeVacationTests, SeasonedFulltime)
{
    double years = 10;
    int expected = VACATION_DAYS_PER_YEAR * floor(years);
    FullTimeEmployee person{"Jane", years};
    EXPECT_EQ(expected, person.getVacation());
}


// Test for expected vacation days with weird fractional year.
TEST(EmployeeVacationTests, FractionalVacation)
{
    double years = 0.711;
    int expected = VACATION_DAYS_PER_YEAR * floor(years);
    FullTimeEmployee person{"Jane", years};
    EXPECT_EQ(expected, person.getVacation());
}


// Test to ensure contractors don't get vacation days.
TEST(EmployeeVacationTests, Contractor)
{
    int expected = 0;
    Contractor person{"Jane", 8};
    EXPECT_EQ(expected, person.getVacation());
}


// Test to ensure temp employees don't get vacation days.
TEST(EmployeeVacationTests, Temporary)
{
    int expected = 0;
    TempEmployee person{"Jane", 8};
    EXPECT_EQ(expected, person.getVacation());
}

