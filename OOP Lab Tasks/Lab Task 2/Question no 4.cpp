#include <iostream>
#include <string>
using namespace std;
struct employee {
    int employee_id;
    int salary;
    string name;
};

struct organization {
    employee emp;  
    int sizeorg;
    string organization_name;
    string organization_number;
};

int main(){
    organization org;
    org.sizeorg = 123;
    org.emp.employee_id = 127; 
    org.organization_number = "NUFAST123ABC";
    org.organization_name = "NU-Fast";
    org.emp.name = "Linus Sebastian";
    org.emp.salary = 400000;
	
	
cout<< "Output the following data using above structure"<< endl;
cout<< "The size of structure organisation : " <<org.sizeorg<< endl;
cout<< "Organisation Name : "<<org.organization_name<< endl;
cout<< "Organisation Number : "<< org.organization_number<< endl;
cout<< "Employee id : " <<org.emp.employee_id <<endl;
cout<< "Employee name : "<<org.emp.name <<endl;
cout<< "Employee Salary : "<<org.emp.salary << endl;
    
    return 0;
}
