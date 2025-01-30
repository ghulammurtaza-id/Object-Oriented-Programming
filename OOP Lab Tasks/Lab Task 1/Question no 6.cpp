#include<bits/stdc++.h>
using namespace std;
int main(int argc,char*argv[]){
	string a,b;
	a = argv[1];
	b = argv[2];
	float arr[5];
	float sum;
	for(int i = 0;i<5;i++){
		arr[i] = stof(argv[i+3]);
		sum += arr[i];
	}
	float avg = sum / 5;
	cout<< "Student name: " <<a<<" "<<b<<endl;
	cout<<"Test scores: ";
	for(int i = 0;i<5;i++){
	cout<<arr[i]<<" ";
	}
	cout<<"\nAverage test score: "<<avg; 

	
	return 0;
}