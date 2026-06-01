#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;
class bill
{
private:
    string Item;
    int Rate, Quantity, batch_no;

public:
    bill() : Item(""), Rate(0), Quantity(0), batch_no(0) {}

    // setter functions
    void setItem(string item)
    {
        Item = item;
    }

    void setRate(int rate)
    {
        Rate = rate;
    }

    void setQuant(int quant)
    {
        Quantity = quant;
    }
    void setBatchno(int bn)
    {
        batch_no = bn;
    }

    string getItem()
    {
        return Item;
    }

    int getRate()
    {
        return Rate;
    }

    int getQuant()
    {
        return Quantity;
    }
    int getbn()
    {
        return batch_no;
    }
    int search(int bn)
    {
        if (bn == batch_no)
            return 1;
        else
            return 0;
    }
    void get_data()
    {
        cout << "\t\tEnter the name of the item:";
        cin >> Item;
        cout << "\t\tEnter rate of the item:";
        cin >> Rate;
        cout << "\t\tEnter quantity of that item:";
        cin >> Quantity;
        cout << "Enter it's Batch number:";
        cin >> batch_no;
    }
    void show_data()
    {
        cout << "\t Item | Rate | Quantity | Batch.No" << endl;
        cout << "\t" << Item << "\t " << Rate << "\t " << Quantity << "\t" << batch_no << endl;
    }
};
// additem
void addItem()
{
    bill b;
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t1. Add Item." << endl;
        cout << "\t2. Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            b.get_data();
            b.getbn();
            b.getItem();
            b.getQuant();
            b.getRate();
            

            ofstream fout("bill.txt", ios::app);
            if (!fout)
            {
                cout << "\tError: File Can't Open!" << endl;
            }
            else
            {
                fout << b.getItem() << " | " << b.getRate() << " | " << b.getQuant() << " | " << b.getbn() << endl;
            }
            fout.close();
            cout << "\tItem Added Successfully" << endl;
            Sleep(3000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            Sleep(3000);
        }
        else
        {
            cout << "\tInvalid choice, please try again." << endl;
        }
    }
}

// print section
void printBill()
{
    bill b;
    system("cls");
    int count = 0;
    bool close = false;
    while (!close)
    {
        system("cls");
        int choice;
        cout << "\t1.Add Bill." << endl;
        cout << "\t2.Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            fstream fin;
            fin.open("bill.txt");
            fstream fout;
            fout.open("bill Temp.txt");

            string line;
            bool found = false;

            while (getline(fin, line))
            {
                stringstream ss;
                ss << line;
                string itemName;
                int itemRate, itemQuant;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName)
                {
                    found = true;
                    if (quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        fout << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl;
                    }
                    else
                    {
                        cout << "\tSorry, " << item << " Ended!" << endl;
                    }
                }
                else
                {
                    fout << line << endl;
                }
            }
            if (!found)
            {
                cout << "\tItem Not Available!" << endl;
            }
            fout.close();
            fin.close();
            remove("bill.txt");
            rename("bill Temp.txt", "bill.txt");
        }
        else if (choice == 2)
        {
            close = true;
            cout << "\tCounting Total Bill" << endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout << endl
         << endl;
    cout << "\t Total Bill ----------------- : " << count << endl
         << endl;
    cout << "\tThanks For Shopping!" << endl;
    Sleep(5000);
}

// search function
void search_data()
{
    bill b;
    fstream fin;
    int bn;
    int flag = 0;
    cout << "Enter the batch number of the item to search:";
    cin >> bn;
    fin.open("bill.txt", ios::in | ios::binary);
    while (fin.read((char *)&b, sizeof(b)))
    {
        if (b.search(bn))
        {
            b.show_data();
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "--Data not found--";
}

int main()
{
    bill b;

    while (1)
    {
        system("cls");
        int n;

        cout << "\tWelcome To the Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t\t1.Add Item." << endl;
        cout << "\t\t2.Print Bill." << endl;
        cout << "\t\t3.Search specific item." << endl;
        cout << "\t\tEnter Choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            addItem();
            break;
        case 2:
            printBill();
            break;
        case 3:
            search_data();
            break;
        case 4:
            exit(0);
        default:
            cout << "\t\tThe choice you have entered is invalid\t\t" << endl;
            cout << "\t\tEnter any valid option:\t\t" << endl;
        }
    }
    return 0;
}