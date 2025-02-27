#include <iostream>
using namespace std;
// task pdf me qno 7
class Student {
public:
    const int roll_no;

private:
    Student(int roll) : roll_no(roll){
	
	}

public:
    static Student createStudent(){
        static int count = 0;
        int base;
        cout << "Enter base roll: ";
        cin >> base;
        return Student(base + count++);
    }

    void show()const{
        cout << "Roll: " << roll_no << endl;
    }
};

int main(){
    Student s1 = Student::createStudent();
    Student s2 = Student::createStudent();
    s1.show();
    s2.show();
    return 0;
}