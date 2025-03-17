#include <iostream>
#include <string>
using namespace std;
class Student {
protected:
    string name;
    int id;
public:
    Student(string n, int i):name(n), id(i) {}
    void displayStudent() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};
class Marks : public Student {
protected:
    int math;
    int science;
    int english;
public:
    Marks(string n, int i,int m,int s,int e): Student(n, i),math(m), science(s),english(e) {}
    void displayMarks() {
        cout << "Math:: " << math<< ", Science: " << science << "English:: " << english << endl;
    }
};

class Result : public Marks {
public:
    Result(string n, int i, int m, int s, int e) : Marks(n, i, m, s, e) {}
    void displayResult() {
        int total = math + science + english;
        double avg = total / 3.0;
        cout << "Total Marks: " << total << ", Average Marks: " << avg << endl;
    }
};

int main() {
    Result student("Ali", 101, 85,90,88);
    student.displayStudent();
    student.displayMarks();
    student.displayResult();

    return 0;
}
