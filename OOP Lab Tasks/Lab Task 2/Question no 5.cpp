#include<bits/stdc++.h>
using namespace std;
struct employee {
	int id;
 	string name;	
};
void create(int n){
	employee arr[n];
	for(int i = 0;i<n;i++){
		cout<<"Employee Id: "<<endl;
		cin>>arr[i].id;
		cout<<"Employee Name: "<<endl;
		cin>>arr[i].name;
	}
	cout<<"-----------------Done thanks for your data -----------------"<< endl;
	cout<<"--------------------/  before Sort Data  \-------------- "<< endl;
	for(int i=0;i<n;i++){
		cout<<"ID : "<<arr[i].id<<endl;
		cout<<"Name : "<<arr[i].name<<endl;
	}
	for(int i = 0;i<n;i++){
		for(int j = i;j<n-1;j++){
			if(arr[i].id<arr[i+1].id){
			int temp = arr[i].id;
			arr[i].id = arr[i+1].id;
			arr[i+1].id = temp;
			
			string temps = arr[i].name;
			arr[i].name = arr[i+1].name;
			arr[i+1].name = temps;
			}	
		}
	}
	cout<<"Sort by Id completed"<<endl;
	cout<<"-------------------After Sort Data ------------------- "<< endl;
	for(int i=0;i<n;i++){
		cout<<"ID : "<<arr[i].id<<endl;
		cout<<"Name : "<<arr[i].name<<endl;
	}
	cout<< "NoW time to do with 1st Character of Name "<< endl;
	cout<<"before Sort Data "<< endl;
	for(int i=0;i<n;i++){
		cout<<"ID : "<<arr[i].id<<endl;
		cout<<"Name : "<<arr[i].name<<endl;
	}
	for(int i = 0;i<n;i++){
		for(int j = i;j<n-1;j++){
			if(arr[i].name[0]>arr[i+1].name[0]){
			int temp = arr[i].id;
			arr[i].id = arr[i+1].id;
			arr[i+1].id = temp;
			
			string temps = arr[i].name;
			arr[i].name = arr[i+1].name;
			arr[i+1].name = temps;
			}
			
		}
	}
	cout<<"------------------------Sort by First Character Name --------------------------"<<endl;
	
	
	cout<<"After Sort Data "<< endl;
	for(int i=0;i<n;i++){
		cout<<"ID : "<<arr[i].id<<endl;
		cout<<"Name : "<<arr[i].name<<endl;
	}
}
int main(){
	int n; 
	cin>> n;		
	create(n);
	return 0;
}