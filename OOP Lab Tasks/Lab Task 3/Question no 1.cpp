#include<bits/stdc++.h>


using namespace std;
class user {
 	public:
	int age ;
 	string Name;
	private :
	string getName(){
		return Name;	
	}
	int getage(){
		return age;
	}
	
};

int main(int argc,char ** argv){

	user monis;
	monis.age = stoi(argv[2]);
	monis.Name = argv[1];
	cout<< "My name is "<< monis.Name<<" ." <<endl;
	cout<< "I am "<< monis.age<< "year Old"<< endl;
	
	return 0;
}
	
