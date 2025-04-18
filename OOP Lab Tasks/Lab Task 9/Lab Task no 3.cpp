#include <bits/stdc++.h>
using namespace std;

class Rec {
private:
    string patientName;
    int patientId;
    string birthDate;
    string medicalHistory;
    string currentTreatment;
    double pendingAmount;

public:
    Rec(string name, int id, string dob)
        : patientName(name), patientId(id), birthDate(dob), medicalHistory(""), currentTreatment(""), pendingAmount(0) {}

    string getBasic() const {
        return "Patient: " + patientName + ", ID: " + to_string(patientId) + ", DOB: " + birthDate;
    }

private:
    void setHistory(string history) { medicalHistory = history; }
    void setTreatment(string treatment) { currentTreatment = treatment; }
    string getMedical() const { return "History: " + medicalHistory + ", Treatment Plan: " + currentTreatment; }

    void addDue(double amount) { pendingAmount += amount; }
    string getDue() const { return "Outstanding Balance: $" + to_string(pendingAmount); }

    friend class Doc;
    friend class Bill;
};

class Doc {
public:
    void update(Rec& record, string history, string treatment) {
        record.setHistory(history);
        record.setTreatment(treatment);
    }

    void view(const Rec& record) {
        cout<<"[Doctor View] "<<record.getMedical()<<endl;
    }
};

class Bill {
public:
    void charge(Rec& record, double amount) {
        record.addDue(amount);
    }

    void view(const Rec& record) {
        cout<<"[Billing View] "<<record.getDue()<<endl;
    }
};

class Front {
public:
    void view(const Rec& record) {
        cout<<"[Reception View] "<<record.getBasic()<<endl;
    }
};

int main() {
    Rec patient("Ali", 101, "1998-08-10");

    Doc doctor;
    doctor.update(patient, "Flu symptoms reported", "Prescribed rest and hydration");
    doctor.view(patient);

    Bill billing;
    billing.charge(patient, 1200);
    billing.view(patient);

    Front receptionist;
    receptionist.view(patient);

    return 0;
}

