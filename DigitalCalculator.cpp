#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


void input(int &x, int &y) {
    cout << "\t Enter First Number: ";
    cin >> x;
    cout << "\t Enter Second Number: ";
    cin >> y;
}

int menu() {
    int choice;
    cout << right << setw(50) << "Main Menu" << endl << endl << endl;
    cout << right << setw(25) << "1" << " Addition." << endl;
    cout << right << setw(25) << "2" << " Subtraction." << endl;
    cout << right << setw(25) << "3" << " Division." << endl;
    cout << right << setw(25) << "4" << " Multiplication." << endl;
    cout << right << setw(25) << "5" << " Exponent." << endl;
    cout << right << setw(25) << "6" << " Matrix Addition." << endl;
    cout << right << setw(25) << "7" << " Matrix Multiplication." << endl;
    cout << right << setw(25) << "8" << " Average." << endl;
    cout << right << setw(25) << "9" << " Percentage." << endl;
    cout << right << setw(25) << "10" << " Factorial." << endl;
    cout << right << setw(25) << "999" << " Exit." << endl;
    cout << endl << "PLEASE ENTER YOUR CHOICE: ";
    cin >> choice;
    return choice;
}

void Add() {
    cout << "xx Addition xx" << endl;
    int First, Second;
    input(First, Second);
    cout << "\n\t Addition of given two numbers is: " << First + Second << endl;
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void Sub() {
    cout << "xx Subtraction xx" << endl;
    int First, Second;
    input(First, Second);
    cout << "\n\t Subtraction of given two numbers is: " << First - Second << endl;
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void Divide() {
    cout << "xx Division xx" << endl;
    int First, Second;
    input(First, Second);
    if (Second == 0) {
        cout << "\n\t Division by zero is not allowed." << endl;
    } else {
        cout << "\n\t Division of given two numbers is: " << static_cast<double>(First) / Second << endl;
    }
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void Multiply() {
    cout << "xx Multiplication xx" << endl;
    int First, Second;
    input(First, Second);
    cout << "\n\t Multiplication of given two numbers is: " << First * Second << endl;
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void Exponent() {
    cout << "xx Exponent xx" << endl;
    int base, Pow;
    long long int exp = 1;
    cout << "\t Enter Base Number: ";
    cin >> base;
    cout << "\n\t Enter Exponent Power: ";
    cin >> Pow;
    for (int i = 0; i < Pow; i++) {
        exp *= base;
    }
    cout << "\n\t Result: " << exp << endl;
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void MatrixAdd() {
    cout << "xx Matrix Addition xx" << endl;
    int mat1[3][3], mat2[3][3], result[3][3];
    
   
    cout << "Enter the elements of the first Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat1[i][j];
        }
    }
    
  
    cout << "Enter the elements of the second Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat2[i][j];
        }
    }
    
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    

    cout << "Matrix Addition Result:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void MatrixMultiply() {
    cout << "xx Matrix Multiplication xx" << endl;
    int mat1[3][3], mat2[3][3], result[3][3];
    

    cout << "Enter the elements of the first Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat1[i][j];
        }
    }
    
  
    cout << "Enter the elements of the second Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat2[i][j];
        }
    }
    
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    
    
    cout << "Matrix Multiplication Result:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void Average() {
    cout << "xx Average xx" << endl;
    int n, sum = 0;
    cout << "\nEnter Number of Elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter Numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "The Average is: " << static_cast<float>(sum) / n << endl;
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void Percentage() {
   
    cout << "Percentage function not implemented yet." << endl;
    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}

void Factorial() {
    cout << "xx Factorial xx" << endl;
    long long int n, fact = 1;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Sorry, factorial does not exist for negative integers" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        cout << "Factorial of " << n << " is: " << fact << endl;
    }

    cout << "\n\t\t(Press any key to continue)" << endl;
    cin.ignore();
    cin.get();
}











int main() {
   int flag=1;
    do {
        switch (menu()) {
            case 1:
                Add();
                break;
            case 2:
                Sub();
                break;
            case 3:
                Divide();
                break;
            case 4:
                Multiply();
                break;
            case 5:
                Exponent();
                break;
            case 6:
                MatrixAdd();
                break;
            case 7:
                MatrixMultiply();
                break;
            case 8:
                Average();
                break;
            case 9:
                Percentage();
                break;
            case 10:
                Factorial();
                break;
            case 999:
                cout << "Thanks for using the calculator!" << endl;
                flag=0;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (flag);

    return 0;
}


