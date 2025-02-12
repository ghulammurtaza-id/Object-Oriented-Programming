#include<bits/stdc++.h>
#define c cout

using namespace std;

class Date{
	int month;
	int day;
	int year;
	public:
		void DisplayDate(){
		c<<month<<"/"<<day<<"/"<<year<<endl;
		}
		void setday(int day){
		this->day = day;
		}
		void setmonth(int month){
		this->month = month;
		}
		void setyear(int year){
		this->year = year;
		}
};
void testApplication(Date &cp,char **arr){
	cp.setmonth(stoi(arr[1]));
	cp.setday(stoi(arr[2]));
	cp.setyear(stoi(arr[3]));
	cp.DisplayDate();
}
int main(int argc,char **argv){
		Date cp;
		testApplication(cp,argv);
}s