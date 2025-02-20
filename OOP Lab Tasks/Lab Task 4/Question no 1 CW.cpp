#include<bits/stdc++.h>
using namespace std;

class Matrix {
    double* data;    
    int rows, cols;

public:
    
    Matrix() :rows(0), cols(0), data(nullptr) {}

    
    Matrix(int r, int c) :rows(r),cols(c){
        data = new double[r * c];
        for (int i = 0; i < r * c; i++){
            data[i] = 0;
        }
    }
	Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new double[rows * cols];
        for (int i= 0; i< rows * cols; i++){
            data[i] = other.data[i];}
    	}

    
    Matrix(Matrix&& other) : rows(other.rows), cols(other.cols), data(other.data) {
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }

    // auto delte -Destructor
    ~Matrix() {
        delete[] data;
    }

    int getRows() { return rows; }
    int getCols() { return cols; }

    double& at(int r, int c){
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            throw out_of_range("Index out of bounds");
        }
        return data[r * cols + c];
    }

    void fill(double value){
        for (int i = 0; i < rows * cols; i++) {
            data[i] = value;
        }
    }

    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.at(j, i) = data[i * cols + j];
            }
        }
        cout << "Transposed Matrix:\n";
        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.cols; j++) {
                cout << result.at(i, j) << " ";
            }
            cout << endl;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Matrix m1(2,3);
    m1.at(0,0) = 1; m1.at(0,1) = 2; m1.at(0,2) = 3;
    m1.at(1,0) = 4; m1.at(1,1) = 5; m1.at(1,2) = 6;
    cout << "Original Matrix:\n";
    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            cout << m1.at(i, j) << " ";
        }
        cout << endl;
    }
    Matrix m2 = m1.transpose();
    return 0;
}