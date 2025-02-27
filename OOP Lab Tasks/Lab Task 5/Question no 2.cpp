#include <iostream>
using namespace std;
// task pdf me qno 5
class Car {
public:

    int engine_horsepower;
    int seating_capacity;
    int no_of_speakers;
    int& getEngineHorsepower()const{
        return const_cast<int&>(engine_horsepower);
    }
    int& getSeatingCapacity() const{
        return const_cast<int&> (seating_capacity);
    }

    int& getNoOfSpeakers()const{
        return const_cast<int&>(no_of_speakers);
    }
};

int main() {
    
    Car car;
    car.engine_horsepower = 0;
    car.seating_capacity = 0;
    car.no_of_speakers = 0;

    car.getEngineHorsepower() = 200;  
    car.getSeatingCapacity() = 5;     
    car.getNoOfSpeakers() = 4;     
    cout << "Engine Horsepower: " << car.engine_horsepower << endl;
    cout << "Seating Capacity: " << car.seating_capacity << endl;
    cout << "Number of Speakers: " << car.no_of_speakers << endl;

    return 0;
}