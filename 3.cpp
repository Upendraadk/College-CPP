/*Write a program that checks the order of a medicine from a pharmacy store.
The program should read the order quantity and the medicine quantity in the
store. When the order quantity is more than the store quantity, your
program should display the message “No enough quantity”. When the order
quantity is less than the store quantity, you have to check that the order
quantity must be not more than 16 except there is more than 40 items in the
store. The messages that will be displayed in that cases are “Your order is
accepted” OR “You cannot order more than 16 item”
*/


#include <iostream>
using namespace std;

int main() {
    int orderQuantity, storeQuantity;
    cout << "Enter the order quantity: ";
    cin >> orderQuantity;

    cout << "Enter the store quantity: ";
    cin >> storeQuantity;

    if (orderQuantity > storeQuantity) {
        cout << "No enough quantity" << endl;
    } else {
        if (orderQuantity <= 16 || storeQuantity > 40) {
            cout << "Your order is accepted" << endl;
        } else {
            cout << "You cannot order more than 16 items" << endl;
        }
    }

    return 0;
}
