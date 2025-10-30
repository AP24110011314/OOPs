#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
private:
    int empID;
    string name, designation;
    float basicSalary, bonus, deductions;

public:
    void inputData() {
        cout << "\nEnter Employee ID: ";
        cin >> empID;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter Bonus: ";
        cin >> bonus;
        cout << "Enter Deductions: ";
        cin >> deductions;
    }

    void displayData() const {
        cout << left << setw(10) << empID
             << setw(20) << name
             << setw(20) << designation
             << setw(12) << fixed << setprecision(2) << basicSalary
             << setw(10) << bonus
             << setw(12) << deductions
             << setw(12) << calculateNetSalary()
             << endl;
    }

    int getEmpID() const { return empID; }
    float calculateNetSalary() const { return basicSalary + bonus - deductions; }

    void generatePayslip() const {
        cout << "\n===============================";
        cout << "\n        PAYSLIP REPORT";
        cout << "\n===============================";
        cout << "\nEmployee ID   : " << empID;
        cout << "\nName          : " << name;
        cout << "\nDesignation   : " << designation;
        cout << "\nBasic Salary  : " << basicSalary;
        cout << "\nBonus         : " << bonus;
        cout << "\nDeductions    : " << deductions;
        cout << "\n-------------------------------";
        cout << "\nNet Salary    : " << calculateNetSalary();
        cout << "\n===============================\n";
    }

    // Write employee data to a text file
    void writeToFile(ofstream &ofs) {
        ofs << empID << endl
            << name << endl
            << designation << endl
            << basicSalary << endl
            << bonus << endl
            << deductions << endl;
    }

    // Read employee data from a text file
    bool readFromFile(ifstream &ifs) {
        if (!(ifs >> empID)) return false;
        ifs.ignore();
        getline(ifs, name);
        getline(ifs, designation);
        ifs >> basicSalary >> bonus >> deductions;
        ifs.ignore();
        return true;
    }
};


void addEmployee();
void displayAllEmployees();
void searchEmployee();
void generatePayslip();

int main() {
    int choice;
    do {
        cout << "\n===============================";
        cout << "\n  Employee Payroll Management";
        cout << "\n===============================";
        cout << "\n1. Add Employee";
        cout << "\n2. Display All Employees";
        cout << "\n3. Search Employee";
        cout << "\n4. Generate Payslip";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAllEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: generatePayslip(); break;
            case 5: cout << "\nExiting Program. Goodbye!\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 5);
}

void addEmployee() {
    ofstream file("employees.txt", ios::app);
    if (!file) {
        cout << "\nError opening file!";
        return;
    }
    Employee emp;
    emp.inputData();
    emp.writeToFile(file);
    file.close();
    cout << "\nEmployee record added successfully!\n";
}

void displayAllEmployees() {
    ifstream file("employees.txt");
    if (!file) {
        cout << "\nNo employee records found!\n";
        return;
    }
    Employee emp;
    cout << "\n==================================================================================================================\n";
    cout << left << setw(10) << "EmpID"
         << setw(20) << "Name"
         << setw(20) << "Designation"
         << setw(12) << "Basic"
         << setw(10) << "Bonus"
         << setw(12) << "Deductions"
         << setw(12) << "NetSalary" << endl;
    cout << "==================================================================================================================\n";
    while (emp.readFromFile(file)) emp.displayData();
    file.close();
}

void searchEmployee() {
    ifstream file("employees.txt");
    if (!file) {
        cout << "\nNo records available!\n";
        return;
    }
    int id;
    cout << "\nEnter Employee ID to search: ";
    cin >> id;
    Employee emp;
    bool found = false;
    while (emp.readFromFile(file)) {
        if (emp.getEmpID() == id) {
            cout << "\nEmployee Found:\n";
            emp.displayData();
            found = true;
            break;
        }
    }
    if (!found) cout << "\nEmployee with ID " << id << " not found!\n";
    file.close();
}

void generatePayslip() {
    ifstream file("employees.txt");
    if (!file) {
        cout << "\nNo records available!\n";
        return;
    }
    int id;
    cout << "\nEnter Employee ID to generate payslip: ";
    cin >> id;
    Employee emp;
    bool found = false;
    while (emp.readFromFile(file)) {
        if (emp.getEmpID() == id) {
            emp.generatePayslip();
            found = true;
            break;
        }
    }
    if (!found) cout << "\nEmployee not found!\n";
    file.close();
}