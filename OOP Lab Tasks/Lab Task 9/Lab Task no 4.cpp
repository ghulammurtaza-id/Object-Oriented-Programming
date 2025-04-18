#include <bits/stdc++.h>
using namespace std;

class Flight {
    string flightNumber, departure, arrival;
    int capacity, bookedSeats;

public:
    Flight(string num, string dep, string arr, int cap)
        : flightNumber(num), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool book() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    bool cancel() {
        if (bookedSeats > 0) {
            bookedSeats--;
            return true;
        }
        return false;
    }

    bool upgrade() {
        return bookedSeats > 0;
    }

    void info() const {
        cout<<"Flight "<<flightNumber<<":"<<departure<<"->"<<arrival<<",Seats:"<<bookedSeats<<"/"<<capacity<<"\n";
    }

    friend class Passenger;
};

class Passenger {
    string passengerName;
    int passengerId;

public:
    Passenger(string name, int id) : passengerName(name), passengerId(id) {}

    void bookSeat(Flight &flight) {
        if (flight.book()) cout<<passengerName<<" booked successfully\n";
        else cout<<passengerName<<" failed to book\n";
    }

    void cancelSeat(Flight &flight) {
        if (flight.cancel()) cout<<passengerName<<" canceled seat\n";
        else cout<<passengerName<<" had no seat to cancel\n";
    }

    void upgradeSeat(Flight &flight) {
        if (flight.upgrade()) cout<<passengerName<<" upgraded seat\n";
        else cout<<passengerName<<" can't upgrade\n";
    }
};

int main() {
    Flight flight1("PK101", "LHE", "KHI", 2);
    Flight flight2("PK202", "ISB", "DXB", 1);

    Passenger passenger1("Ali", 1);
    Passenger passenger2("Sara", 2);
    Passenger passenger3("Zain", 3);

    passenger1.bookSeat(flight1);
    passenger2.bookSeat(flight1);
    passenger3.bookSeat(flight1);

    passenger1.upgradeSeat(flight1);
    passenger3.upgradeSeat(flight1);

    passenger2.cancelSeat(flight1);
    passenger2.cancelSeat(flight1);

    cout<<"\nFlight Status:\n";
    flight1.info();
    flight2.info();

    return 0;
}

