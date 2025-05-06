#include<bits/stdc++.h>

using namespace std;

class InvalidTypeAccess:public exception{
public:
    const char* what() const noexcept override{
        return "Invalid type access in SafeValueHolder.";
    }
};

class SafeValueHolder{
    any storedValue;
public:
    template<typename T>
    void put(const T& input){
        storedValue=input;
    }

    template<typename T>
    T fetch() const{
        if(!storedValue.has_value() || storedValue.type()!=typeid(T)){
            throw InvalidTypeAccess();
        }
        return any_cast<T>(storedValue);
    }
};

int main(){
    try{
        SafeValueHolder box;
        box.put<int>(100);
        cout<<"Fetched integer:"<<box.fetch<int>()<<endl;

        // cout<<"Trying wrong type:"<<box.fetch<string>()<<endl;

    }catch(exception& err){
        cout<<"Caught error:"<<err.what()<<endl;
    }
    return 0;
}

