#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Subject {
    string name;
};
struct Student {
    int id;
    static const int num_subject = 4; 
    Subject subjects[num_subject]; 
};
int main() {
    vector<Student> students; 
    int ns;
    cout<< "Enter the number of students: ";
    cin>> ns;

    for (int i = 0; i < ns; ++i) {
        Student s; 
        cout <<"\nEnter ID for Student "<< i + 1 << ": ";
        cin >> s.id;
	cin.ignore();//important except its doesn't take input correctly
	

        cout << "Enter " << Student::num_subject << " subjects:\n";
        for (int j = 0; j < Student::num_subject; ++j) {
            cout << "Subject " << j + 1 << ": ";
            getline(cin, s.subjects[j].name);
        }

        students.push_back(s);
    }

    
    cout << "\n\nStudent Records:\n";
    for (const auto& s : students) {
        cout << "\nID: " << s.id << "\nSubjects:\n";
        for (int j = 0; j < Student::num_subject; ++j) {
            cout << j+1 <<" - "<< s.subjects[j].name << "\n";
        }
    }

    return 0;
}
