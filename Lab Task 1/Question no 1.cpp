#include <bits/stdc++.h>
using namespace std;

float sechighest(float *arr) {
    float s = -8, f;
    f = arr[0];
    for (int i = 0; i < 20; i++) {
        if (arr[i] > f) {
            s = f;
            f = arr[i];
        } else {
            if (arr[i] > s && arr[i] < f)
                s = arr[i];
        }
    }
    return s;
}

int main() {
    float arr[20] = {2.0, 1.0, 2.0,23.3,23,211,21,2321,1123};
    float s = sechighest(arr);
    cout << fixed<<setprecision(2) << s << endl;

    return 0;
}
