#include <bits/stdc++.h>
using namespace std;

int main(){
    cout <<"Enter string  : ";
    string inputStr;
    getline(cin, inputStr);

    ofstream outStream("Question 1.txt", ios::app);
    if (!outStream){
        cout << "Failed to open file!";return 1;
    }

    for (int idx = 0;idx< inputStr.size();++idx) {
        char encChar= inputStr[idx]+idx + 1;
        outStream<< encChar;
    }
    outStream << endl;
    outStream.close();

    ifstream inStream("Question 1.txt", ios::in);
    if (!inStream){
        cout<<"Failed to open file!";
        return 1;
    }

    string decLine;
    while (getline(inStream, decLine)){
        for (int idx = 0;idx <decLine.size(); ++idx) {
            char decChar=decLine[idx] - (idx + 1);
            cout<<decChar;
        }
        cout<< endl;
    }
    return 0;
}

