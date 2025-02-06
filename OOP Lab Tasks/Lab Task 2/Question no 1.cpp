#include<bits/stdc++.h>
using namespace std;
int main(int argc,char *argv[]){
	int arr[argc-1];
	for(int i = 0;i<argc-1;i++){
	arr[i]=stoi(argv[i+1]);
	}
	int *ptr;
	ptr = arr;
	int sum = 0;
	for(int i = 0;i<argc-1;i++){
	sum += *ptr;
	ptr++;
	}
	cout<<"The sum is "<<sum;
	return 0;
}