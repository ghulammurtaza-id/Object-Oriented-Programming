#include <bits/stdc++.h>

using namespace std;

void addTask();
void showTasks();
void completeTask();

int main(){
    int option;
    while(1){
        cout<<"----------------------"<<endl;
        cout<<"1. Add Tasks"<<endl;
        cout<<"2. View Tasks"<<endl;
        cout<<"3. Mark Tasks as done"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"----------------------"<<endl;
        cin>>option;
        switch(option){
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: completeTask(); break;
            case 4: return 0;
            default: cout<<"Invalid Command!\n";
        }
    }
    return 0;
}

void addTask(){
    ofstream outputFile;
    outputFile.open("Question 5.txt", ios::app);
    if(!outputFile){
        cout<<"Failed to open file!";
        exit(1);
    }
    string newTask;
    cout<<"Enter Task = ";
    getchar();
    getline(cin,newTask);
    outputFile<<newTask<<endl;
    cout<<"Task Added Successfully!\n";
    outputFile.close();
}

void showTasks(){
    ifstream inputFile;
    inputFile.open("Question 5.txt", ios::in);
    if(!inputFile){
        cout<<"Failed to open file!";
        exit(1);
    }
    string line;
    int index=1;
    cout<<"Tasks:\n";
    while(getline(inputFile,line)){
        cout<<index<<". "<<line<<endl;
        index++;
    }
    inputFile.close();
}

void completeTask(){
    ifstream inputFile;
    inputFile.open("Question 5.txt", ios::in);
    if(!inputFile){
        cout<<"Failed to open file!";
        exit(1);
    }
    vector<string> updatedTasks;
    string currentLine,completedTask;
    cout<<"Enter Completed Task = ";
    getchar();
    getline(cin,completedTask);
    while(getline(inputFile,currentLine)){
        if(currentLine!=completedTask){
            updatedTasks.push_back(currentLine);
        }
    }
    inputFile.close();

    ofstream outputFile;
    outputFile.open("Question 5.txt", ios::out);
    if(!outputFile){
        cout<<"Failed to open file!";
        exit(1);
    }
    for(int i=0;i<updatedTasks.size();i++){
        outputFile<<updatedTasks[i]<<endl;
    }
    outputFile.close();
    cout<<"Marked task as done!\n";
}

