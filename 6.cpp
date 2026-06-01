/* write a C++ program to add two private data members using friend functions.*/

#include <iostream>

using namespace std;

class AddNumbers {
private:
    int num1;
    int num2;

public:
    AddNumbers(int n1, int n2) : num1(n1), num2(n2) {}
    friend int add(AddNumbers obj);
};

int add(AddNumbers obj) {
    return obj.num1 + obj.num2;
}

int main() {
    int a, b;
    cout << "Enter the first and second number: ";
    cin >> a >> b;
    AddNumbers obj(a, b);
    int result = add(obj);
    cout << "The sum of the two numbers is: " << result << endl;

    return 0;
}
