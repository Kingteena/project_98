#include "Payroll.h"

using namespace std;

Payroll::Payroll() {
  this->companyFund = 0;
  this->totalPayRollCost = 0;
}

// Constructor that initialises company fund
Payroll::Payroll(double companyFund) {
  this->companyFund = companyFund;
  this->totalPayRollCost = 0;
}

// Pays the outstanding PayRollCost and returns true if funds are sufficient.
// Returns false if not
bool Payroll::processPayRoll() {
  if (companyFund < totalPayRollCost) {
    return false;
  } else
    companyFund -= totalPayRollCost;
  totalPayRollCost = 0;
  return true;
}

// Calculates the total money needed from the company fund
void Payroll::calculateTotalCost() {
  // Reset the cost to 0
  totalPayRollCost = 0;

  // Go through the employees and calculate their total cost using an iterator
  // to iterate over the vector
  for (auto it = employees.begin(); it != employees.end(); ++it) {
    totalPayRollCost += it->calculateTotalPayment();
  }
}

// Add an Employee object to the vector
void Payroll::addEmployee(Employee employee) { employees.push_back(employee); }

/* Takes an employeeID and removes the relevant employee from the payroll and
 returns true. Returns false if no such employee exists. */
bool Payroll::removeEmployee(int employeeID) {
  // Search through the array to find the index using an iterator to iterate
  // over the vector
  for (auto it = employees.begin(); it != employees.end();) {
    if (employeeID == it->getEmployeeID()) {
      employees.erase(it);
      return true;
    } else {
      ++it;
    }
  }
  return false;
}

// Add payslip to the payslip array
void Payroll::addPaySlip(PaySlip payslip) { payslips.push_back(payslip); }

// Returns employee details as a list of strings of the form
// id|name|position|age
std::string *Payroll::getEmployeeDetails() {
  std::string *details = new std::string[employees.size()];
  for (int i = 0; i < (int)employees.size(); i++) {
    Employee employee = employees[i];
    details[i] = to_string(employee.getEmployeeID()) + " | " +
                 employee.getName() + " | " + employee.getPosition() + " | " +
                 to_string(employee.getAge());
  }
  return details;
}

Employee *Payroll::getEmployee(int employeeID) {
  for (int i = 0; i < (int)employees.size(); i++) {
    if (employeeID == employees[i].getEmployeeID()) {
      return &employees[i];
    }
  }
  return nullptr;
}

// Generate payslips of all employees and add to outstanding cost
void Payroll::generatePaySlips() {
  for (PaySlip payslip :
       payslips) {  // Iterates over all Payslips in the "payslip" vector and
    // stores in variable payslip
    payslip.generateSlip();
  }
  calculateTotalCost();
}

// Allow managers to add money
void Payroll::addCompanyFund(double companyFund) {
  this->companyFund = companyFund;
}

// Getter functions defined
int Payroll::getNumberOfEmployees() { return employees.size(); }
double Payroll::getTaxRate() { return taxRate; }
double Payroll::getCompanyFund() { return companyFund; }
double Payroll::getTotalCost() { return totalPayRollCost; }
vector<Employee> Payroll::getEmployees() { return employees; }
