#include<bits/stdc++.h>

using namespace std;

class UnderflowError:public exception{ public: const char* what()const noexcept override{return "Stack is empty.";} };

template<typename T> class Stack{ vector<T>elements; public: void add(T val){elements.push_back(val);} void remove(){if(elements.empty())throw UnderflowError();elements.pop_back();} T peek(){if(elements.empty())throw UnderflowError();return elements.back();} bool isEmpty(){return elements.empty();} };

int main(){ try{ Stack<string>words; words.add("FAST"); words.add("CS"); cout<<"Top:"<<words.peek()<<endl; words.remove(); words.remove(); }catch(exception&e){ cout<<"Exception:"<<e.what()<<endl; } return 0; }

