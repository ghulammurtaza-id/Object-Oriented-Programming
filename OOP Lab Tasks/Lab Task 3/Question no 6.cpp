#include <bits/stdc++.h>

using namespace std;

class Matrix {
    int rows;
    int columns;
    vector<vector<int>> elements;
    
	public:
    Matrix(int r, int c) : rows(r), columns(c), elements(r, vector<int>(c, 0)) {}
    int getNumRows() const { 
	return rows; }
    int getNumColumns() const { 
	return columns; }
    
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < columns)
            elements[i][j] = value;
        else
            cout << "Invalid index\n";
    }
    
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                cout << elements[i][j] << " ";
            cout << "\n";
        }
    }
    
    Matrix add(const Matrix &other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Matrices cannot be added\n";
            return Matrix(0, 0);
        }
    Matrix result(rows,columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
        return result;
    }
    
    Matrix multiply(const Matrix &other) const {
        if (columns != other.rows) {
            cout << "Matrices cannot be multiplied\n";
            return Matrix(0, 0);
        }
        Matrix result(rows, other.columns);
        for (int i = 0;i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                int sum =0;
                for (int k = 0; k < columns; k++)
                    sum += elements[i][k] * other.elements[k][j];
                result.elements[i][j] = sum;
            }
        }
        return result;
    }
};

int main() {
    int r, c;
    cout << "Enter dimensions for Matrix A first rows then columns like (r c):: ";
    cin >> r >> c;
    Matrix A(r, c);
    cout << "Enter elements for Matrix A:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            int val;
            cin >> val;
            A.setElement(i, j, val);
        }
    
    cout << "Enter dimensions for Matrix B pehly rows phir columns like (r c): ";
    cin >> r >> c;
    Matrix B(r, c);
    cout << "Enter elements for Matrix B:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            int val;
            cin >> val;
            B.setElement(i, j, val);
        }
    
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Matrix A\n";
        cout << "2. Display Matrix B\n";
        cout << "3. Set an element in Matrix A\n";
        cout << "4. Set an element in Matrix B\n";
        cout << "5. Get number of rows in Matrix A\n";
        cout << "6. Get number of columns in Matrix A\n";
        cout << "7. Add Matrix A and Matrix B\n";
        cout << "8. Multiply Matrix A and Matrix B\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\nMatrix A:\n";
                A.display();
                break;
            case 2:
                cout << "\nMatrix B:\n";
                B.display();
                break;
            case 3: {
                int i, j, val;
                cout << "Enter row, column and value for Matrix A: ";
                cin >> i >> j >> val;
                A.setElement(i, j, val);
                break;
            }
            case 4: {
                int i, j, val;
                cout << "Enter row, column and value for Matrix B: ";
                cin >> i >> j >> val;
                B.setElement(i, j, val);
                break;
            }
            case 5:
                cout << "\nNumber of rows in Matrix A: " << A.getNumRows() << "\n";
                break;
            case 6:
                cout << "\nNumber of columns in Matrix A: " << A.getNumColumns() << "\n";
                break;
            case 7: {
                Matrix sum = A.add(B);
                if (sum.getNumRows() > 0 && sum.getNumColumns() > 0) {
                    cout << "\nSum of matrices:\n";
                    sum.display();
                }
                break;
            }
            case 8: {
                Matrix product = A.multiply(B);
                if (product.getNumRows() > 0 && product.getNumColumns() > 0) {
                    cout << "\nProduct of matrices:\n";
                    product.display();
                }
                break;
            }
            case 9:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "\nInvalid choice.Try again.\n";
        }
    } while (choice != 9);
    
    return 0;
}
