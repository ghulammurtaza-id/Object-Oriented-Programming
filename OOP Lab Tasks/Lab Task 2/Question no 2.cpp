#include <iostream>

using namespace std;

void* addArrayElements(void* arr, int size) {

    int* intArr = (int*)(arr);
    for (int i = 0; i < size; ++i) {
        intArr[i] += 5;
    }
    arr = (void*)intArr;
    return arr;
	}

int main(int argc,char *argv[]) {
    int arr[argc-1];
    cout << "Original Array: ";
    for (int i = 0; i < argc-1; ++i) {
	arr[i] =stoi(argv[i+1]);
	cout<<arr[i]<< " ";
    }
    cout << endl;
    void* modifiedArr = addArrayElements((void*)(arr), argc-1);
    cout << "Modified Array: ";
    for (int i = 0; i < argc-1; ++i) {
        cout << ((int*)modifiedArr)[i] << " ";
    }
    cout << endl;
   
    return 0;
}