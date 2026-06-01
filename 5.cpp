/*write a program to categorize employees based on designation using
static data members*/
#include <iostream>
#include <string>

using namespace std;

class EMPLOYEE {
private:
    int empNumber;
    string empName;
    string designation;
    double basic;
    double da;
    double it;
    double netSalary;

    static int managerCount;
    static int engineerCount;
    static int technicianCount;

public:
    void readData() {
        cout << "Enter Employee Number: ";
        cin >> empNumber;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, empName);
        cout << "Enter Designation (Manager/Engineer/Technician): ";
        getline(cin, designation);
        cout << "Enter Basic Salary: ";
        cin >> basic;
        computeNetSalary();
        updateDesignationCount();
    }

    void computeNetSalary() {
        da = 0.52 * basic; 
        double grossSalary = basic + da;
        it = 0.30 * grossSalary; 
        netSalary = grossSalary - it;
    }

    void updateDesignationCount() {
        if (designation == "Manager") {
            managerCount++;
        } else if (designation == "Engineer") {
            engineerCount++;
        } else if (designation == "Technician") {
            technicianCount++;
        }
    }


    static void printDesignationCounts() {
        cout << "Number of Managers: " << managerCount << endl;
        cout << "Number of Engineers: " << engineerCount << endl;
        cout << "Number of Technicians: " << technicianCount << endl;
    }


    void printData() const {
        cout << "Employee Number: " << empNumber << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Designation: " << designation << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "DA: " << da << endl;
        cout << "Income Tax: " << it << endl;
        cout << "Net Salary: " << netSalary << endl;
    }
};


int EMPLOYEE::managerCount = 0;
int EMPLOYEE::engineerCount = 0;
int EMPLOYEE::technicianCount = 0;

int main() {
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    EMPLOYEE* employees = new EMPLOYEE[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for employee " << (i + 1) << endl;
        employees[i].readData();
    }

    
    for (int i = 0; i < n; ++i) {
        cout << "\nDetails of employee " << (i + 1) << endl;
        employees[i].printData();
    }

    cout << "\nDesignation counts:" << endl;
    EMPLOYEE::printDesignationCounts();

    delete[] employees;

    return 0;
}
