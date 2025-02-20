#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
    int* data;
    int sz;

public:
    
    DynamicArray() : sz(0), data(nullptr) {}
    DynamicArray(int n) :sz(n){
        data = new int[n];
        for (int i = 0;i <n; i++) data[i] = 0;
    }
    DynamicArray(const DynamicArray& other) :sz(other.sz){
        data = new int[sz];
        for (int i =0;i <sz; i++) data[i] = other.data[i];
    }
    DynamicArray(DynamicArray&& other) :sz(other.sz),data(other.data){
        other.sz = 0;
        other.data = nullptr;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            sz = other.sz;
            data = new int[sz];
            for (int i = 0; i < sz; i++) data[i] = other.data[i];
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) {
        if (this != &other) {
            delete[] data;
            sz = other.sz;
            data = other.data;
            other.sz = 0;
            other.data = nullptr;
        }
        return *this;
    }

    
    ~DynamicArray() {
        delete[] data;
    }

    int size() { return sz; }

    int& at(int index) {
        if (index >= sz || index< 0) throw out_of_range("Index out of bounds");
        return data[index];
    }

    void resize(int newSize) {
        if (newSize <= 0) {
            delete[] data;
            data = nullptr;
            sz = 0;
        } else {
            int* newData = new int[newSize];
            int copySize = min(sz, newSize);
            for (int i = 0; i <copySize; i++) newData[i] = data[i];
            for (int i = copySize; i < newSize; i++)newData[i] = 0;
            delete[] data;
            data = newData;
            sz = newSize;
        }
    }
};

int main(int argc,char **argv) {
    DynamicArray arr(3);
    arr.at(0) =1; arr.at(1) =2; arr.at(2)=3;
    arr.resize(5);
    for (int i =0;i < arr.size();i++) {
        cout << arr.at(i) << " ";
    }
    cout << endl;
    return 0;
}