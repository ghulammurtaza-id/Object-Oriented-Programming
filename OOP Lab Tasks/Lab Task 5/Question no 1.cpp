#include <bits/stdc++.h>
#include <windows.h>
// task pdf me task no 4
using namespace std;

class Blend {
public:
    void step() {
        cout << "Blending..." << endl;
    }
};

class Grind {
public:
    void step() {
        cout << "Grinding..." << endl;
    }
};

class JuiceMaker {
private:
    Blend blend;
    Grind grind;

public:
    void blendJuice() {
        cout << "Selecting fruits for blending..."<<endl;
        for (int i = 0; i < 4;++i) {
            blend.step();
            Sleep(1000);
        }
        cout << "Blending complete."<<endl;
    }

    void grindJuice() {
        cout << "Selecting fruits for grinding..."<<endl;
        grind.step();
        Sleep(5000);
        cout << "Grinding complete."<<endl;
    }
};

int main() {
    JuiceMaker jm;
    cout << "Starting blendJuice..."<<endl;
    jm.blendJuice();
    cout << "Starting grindJuice...."<<endl;
    jm.grindJuice();
    return 0;
}