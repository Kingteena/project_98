#ifndef PAYROLL_H
#define PAYROLL_H

#include <vector>

#include "Employee.h"
#include "PaySlip.h"

class Payroll {
 private:
  double taxRate;           // Tax rate
  double totalPayRollCost;  // Cost of total wages
  double companyFund;       // Salaries are paid from the company fund
  // Array of payslips
  vector<PaySlip> payslips;
  // Number of employees in the company
  vector<Employee> employees;

 public:
  // Process payroll
  void processPayRoll();       // Process the payroll for all employees
  float calculateTotalCost();  // Calculates the total cost (including tax and
                               // superannuation)
  void addEmployee(Employee employee);  // Add employee to the payroll system
  void removeEmployee(
      Employee employee);   // Remove employee to the payroll system
  void generatePaySlips();  // Generates payslips for employees

  // Getter functions for data members
  double getTaxRate();
  double getTotalCost();
  double getCompanyFund();
  int getNumberOfEmployees();
};

#endif