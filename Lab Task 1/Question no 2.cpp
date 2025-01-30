#include <iostream>
using namespace std;

float sum(float *arr) {
    float sum = 0; 
    for (int i = 0; i < 20; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    float arr[20] = {2.0, 1.0, 2.0,23.3,23,211,21,2321,1123};
    float s = sum(arr);
    cout << s << endl;
    return 0;
}
