#include<bits/stdc++.h>
using namespace std;
int main(int argc,char *argv[]){
	
	cout<< "Enter the Weight of the Person in KG : "<< endl;
	float kg,po;
	cin>>kg;
	po = kg * 2.2;
	cout<< "The Weight of the Person in Pound : "<< endl;
	cout<<fixed<<setprecision(2);
	cout<< po;
//	cout<<round(po) ; 
	
	return 0;
	
}