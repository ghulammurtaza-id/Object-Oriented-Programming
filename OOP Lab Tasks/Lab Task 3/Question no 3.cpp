#include<bits/stdc++.h>
#define c cout
#define e endl
using namespace std;

class Glass{
	public:
	int liquidlevel;
	Glass() : liquidlevel(200){}
	void Drink(int milliliters){
		liquidlevel -= milliliters;
	}
	void Refill(){
		liquidlevel = 200;
	}
};

int main(int argc,char **argv){
	Glass g;
	c<<"Welcome to RoboDrink Game :]"<<e;
	int count = argc -1 ;
	int i = 1;
	while(count){
		
		c<<"kid drink water "<<argv[i]<<" - ml"<< e;
			g.Drink(stoi(argv[(int)i]));
		c<<"Current Water Store"<<g.liquidlevel<<e;
	
			i++;	 
			count--;
			if(g.liquidlevel <100){
			c<<"Oh yeah Going to Refil NoW 200ml"<<e;
			g.Refill();
		}
	}
	
}