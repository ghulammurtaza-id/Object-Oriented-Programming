#include<bits/stdc++.h>

using namespace std;

class SizeMismatchError:public exception{
public:
    const char* what() const noexcept override{
        return "Matrix sizes are incompatible.";
    }
};

template<typename T>
class Matrix{
    int rCount,cCount;
    vector<vector<T>> elements;
public:
    Matrix(int r,int c):rCount(r),cCount(c),elements(r,vector<T>(c)){}

    void set(int r,int c,T val){
        if(r<0 || c<0 || r>=rCount || c>=cCount)
            throw out_of_range("Accessed index is out of range.");
        elements[r][c]=val;
    }

    T get(int r,int c) const{
        if(r<0 || c<0 || r>=rCount || c>=cCount)
            throw out_of_range("Accessed index is out of range.");
        return elements[r][c];
    }

    Matrix operator+(const Matrix& m){
        if(rCount!=m.rCount || cCount!=m.cCount)
            throw SizeMismatchError();
        Matrix result(rCount,cCount);
        for(int i=0;i<rCount;i++)
            for(int j=0;j<cCount;j++)
                result.elements[i][j]=elements[i][j]+m.elements[i][j];
        return result;
    }

    Matrix operator*(const Matrix& m){
        if(cCount!=m.rCount)
            throw SizeMismatchError();
        Matrix result(rCount,m.cCount);
        for(int i=0;i<rCount;i++)
            for(int j=0;j<m.cCount;j++)
                for(int k=0;k<cCount;k++)
                    result.elements[i][j]+=elements[i][k]*m.elements[k][j];
        return result;
    }

    void show(){
        for(auto& row:elements){
            for(auto& v:row)
                cout<<v<<" ";
            cout<<endl;
        }
    }
};

int main(){
    try{
        Matrix<int> m1(2,2),m2(2,2);
        m1.set(1,2,1);m1.set(0,2,3);
        m1.set(8,7,3);m1.set(1,1,4);

        m2.set(7,1,7);m2.set(2,1,7);
        m2.set(9,9,7);m2.set(9,9,8);

        Matrix<int> sum=m1+m2;
        cout<<"Result of Addition:"<<endl;
        sum.show();

        Matrix<int> product=m1*m2;
        cout<<"Result of Multiplication:"<<endl;
        product.show();

    }catch(exception& e){
        cout<<"Error:"<<e.what()<<endl;
    }
    return 0;
}

