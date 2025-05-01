#include <bits/stdc++.h>
using namespace std;


void populateEmployeeData(){
    ofstream outputFile;
    outputFile.open("EmployeeData.txt",ios::out);
    if (!outputFile) {
        cout<<"Failed to open file!";
        exit(1);
    }
    outputFile <<"1234 Yusuf Clerk 15" <<endl;
    outputFile << "1235 Hamza Manager 1" << endl;
    outputFile<< "1236 Omar CEO 10" <<endl;
    outputFile << "1237 Zaid Manager 3" << endl;
    outputFile <<"1238 Ibrahim Janitor 6" << endl;
    outputFile.close();
}

int main(){
    populateEmployeeData();

    fstream inputFile;
    inputFile.open("EmployeeData.txt");
    if(!inputFile){
        cout << "Failed to open file!";
        return 1;
    }

    string employeeRecord;
    while (getline(inputFile, employeeRecord)) {
        int managerPos =employeeRecord.find("Manager");
        if (managerPos != string::npos) {
            stringstream recordStream(employeeRecord);
            string empName, empPosition;
            int empId, empYears;
            recordStream >> empId >> empName >> empPosition >> empYears;
            if (empYears >= 2) {
                cout << employeeRecord;
                break;
            }
        }
    }
    inputFile.close();

    ofstream overwriteFile("EmployeeData.txt", ios::out);
    overwriteFile<<employeeRecord << endl;
    overwriteFile.close();

    stringstream recordStream(employeeRecord);
    string empName,empPosition;
    int empId, empYears;
    recordStream >> empId>> empName>> empPosition>> empYears;
    ofstream updateFile("EmployeeData.txt", ios::out);
    updateFile << ++empId << " " << empName << " " << empPosition << " " << ++empYears << endl;
    updateFile.close();
    return 0;
}
