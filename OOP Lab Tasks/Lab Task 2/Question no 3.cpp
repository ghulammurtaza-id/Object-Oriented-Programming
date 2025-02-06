#include <bits/stdc++.h>
using namespace std;
// Process of code
// -- run -- int main 
// create a int with dynamic pointer new keyword pointer
// hence we're here using cmd main argument we are convertiing using atoi/stoi
// also check either current size will not increment above from dynamic count array
//hence iis it then call to the function which doing these tasks
//- taking pointer,count pass by ref and currentsize function type return pointer
//it increase size double and realloc memory with copying data using memcpy and delt old array
// return new array
//while loop execute like that until mainfunction count is greater 
//after that print the looop data 
//
int* solve(int *arr,int &count,int currentSize){
    int old = count;
    count *= 2;
   
    int* newArr = new int[count];
    memcpy(newArr,arr,old*sizeof(int)); 
    delete[] arr; 

    return newArr;
}

int main(int argc,char *argv[]) {
    int count = 5; 
    int* arr = new int[count](); 
    int currentSize = 0; 
   
    while (currentSize < argc-1) { 
        if (currentSize == count) {
            arr = solve(arr,count,currentSize); 
        }
        arr[currentSize] = atoi(argv[currentSize + 1]);
        currentSize++; 
    }
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr; 
    return 0;
}
