/*Create a 'DISTANCE' class with :
- feet and inches as data members
- member function to input distance
- member function to output distance
- member function to add two distance objects
Write a main function to create objects of DISTANCE class. Input two distances
and
output the sum
*/

#include <iostream>
using namespace std;

class DISTANCE {
private:
    int feet;
    int inches;

public:
    DISTANCE() : feet(0), inches(0) {}
    void inputDistance() {
        cout << "Enter feet and inches:";
        cin >> feet>>inches;
        
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    
    void outputDistance() const {
        cout << feet << " feet " << inches << " inches" <<endl;
    }

    DISTANCE addDistance(const DISTANCE& d) const {
        DISTANCE result;
        result.feet = feet + d.feet;
        result.inches = inches + d.inches;
        
        if (result.inches >= 12) {
            result.feet += result.inches / 12;
            result.inches = result.inches % 12;
        }
        return result;
    }
};

int main() {
    DISTANCE d1, d2, d3;
    cout << "Enter the first distance:" <<endl;
    d1.inputDistance();
    cout << "Enter the second distance:" <<endl;
    d2.inputDistance();
    d3 = d1.addDistance(d2);
    cout << "The sum of the two distances is: ";
    d3.outputDistance();

    return 0;
}
