#include <bits/stdc++.h>
using namespace std;

class StackEmptyError:public exception{
public:
    const char* what()const noexcept override{return"Stack is empty.";}
};

template<typename T>
class Stack{
    vector<T> items;
public:
    void add(T val){items.push_back(val);}
    void drop(){
        if(items.empty())throw StackEmptyError();
        items.pop_back();
    }
    T getTop(){
        if(items.empty())throw StackEmptyError();
        return items.back();
    }
    bool isEmpty(){return items.empty();}
};

int main(){
    try{
        Stack<string> stack;
        stack.add("LUMS");
        stack.add("SE");
        cout<<"Top:"<<stack.getTop()<<endl;
        stack.drop();
        stack.drop();
    }catch(exception& err){
        cout<<"Error:"<<err.what()<<endl;
    }
    return 0;
}
