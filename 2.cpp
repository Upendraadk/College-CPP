//Program that determines the maximum and the minimum of three numbers

#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3;
    cout << "Enter the first number: ";
    cin >> num1;
    
    cout << "Enter the second number: ";
    cin >> num2;
    
    cout << "Enter the third number: ";
    cin >> num3;
    
    int maxNum = num1;
    if (num2 > maxNum) {
        maxNum = num2;
    }
    if (num3 > maxNum) {
        maxNum = num3;
    }
    
    int minNum = num1;
    if (num2 < minNum) {
        minNum = num2;
    }
    if (num3 < minNum) {
        minNum = num3;
    }
    
    cout << "The maximum number is: " << maxNum << endl;
    cout << "The minimum number is: " << minNum << endl;
    
    return 0;
}
