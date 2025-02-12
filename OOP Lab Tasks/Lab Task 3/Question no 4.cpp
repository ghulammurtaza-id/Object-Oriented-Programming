#include <bits/stdc++.h>
using namespace std;

class employee {
    string first_name;
    string last_name;
    double monthly_salary;
    double yearly_salary;

public:
    void setfName(string name) { first_name = name; }
    void setlName(string name) { last_name = name; }
    string getfname() { return first_name; }
    string getlname() { return last_name; }
    void setsalary(int salary) {
        monthly_salary = (salary < 0) ? 0 : salary;
        yearly_salary = 12 * monthly_salary;
    }
    int getsalary() { return monthly_salary; }
};

void EmployeeTest() {
    employee e1, e2;
    string fname, lname;
    double ssalary;
    
    cout << "Please Enter First Employee Data" << endl;
    cout << "Employee 1\nFirst Name: ";
    cin >> fname;
    e1.setfName(fname);
    cout << "Second Name: ";
    cin >> lname;
    e1.setlName(lname);
    cout << "Set the salary: ";
    cin >> ssalary;
    e1.setsalary(ssalary);

    cout << "Employee 2\nFirst Name: ";
    cin >> fname;
    e2.setfName(fname);
    cout << "Second Name: ";
    cin >> lname;
    e2.setlName(lname);
    cout << "Set the salary: ";
    cin >> ssalary;
    e2.setsalary(ssalary);

    cout << "Each Employee gets a 10% raise." << endl;
    double raised;
    
    raised = e1.getsalary() * 1.10;
    cout << "After a 10% raise, total salary of first Employee: " << raised << endl;
    e1.setsalary(raised);
    
    raised = e2.getsalary() * 1.10;
    cout << "After a 10% raise, total salary of second Employee: " << raised << endl;
    e2.setsalary(raised);
}

int main() {
    cout << "Test Application called" << endl;
    EmployeeTest();
    return 0;
}
