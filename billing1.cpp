#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class shopping {
private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu() {
    int choice;
    string username, password;

    while (true) {
        cout << "\n\t\t\t_____________________________________________\n";
        cout << "\t\t\t            Supermarket Main Menu            \n";
        cout << "\t\t\t_____________________________________________\n";
        cout << "\t\t\t|     1) Administrator     |\n";
        cout << "\t\t\t|     2) Buyer             |\n";
        cout << "\t\t\t|     3) Exit              |\n";
        cout << "\t\t\t Please select: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n\t\t\t Please Login\n";
            cout << "\t\t\t Username: ";
            cin >> username;
            cout << "\t\t\t Password: ";
            cin >> password;

            if (username == "annu@mail.com" && password == "Annu@22") {
                administrator();
            } else {
                cout << "\nInvalid username/password\n";
            }
            break;

        case 2:
            buyer();
            break;

        case 3:
            cout << "THANK YOU! Come again!\n";
            return;

        default:
            cout << "\nPlease select a valid option\n";
        }
    }
}

void shopping::administrator() {
    int choice;

    while (true) {
        cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_______1.) Add the Product________|";
    cout<<"\n\t\t\t|                                  |";
    cout<<"\n\t\t\t|_______2.) Modify the Product_____|";
    cout<<"\n\t\t\t|                                  |";
    cout<<"\n\t\t\t|_______3.) Delete the Product_____|";
    cout<<"\n\t\t\t|                                  |";
    cout<<"\n\t\t\t|_______4.) Back to the main menu__|";

    cout<<"\n\n\t Please enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            return;
        default:
            cout << "\nInvalid choice\n";
        }
    }
}

void shopping::buyer() {
    int choice;

    while (true) {
         cout<<"\t\t\t    Buyer \n";
    cout<<"\t\t\t_______________\n";
    cout<<"                     \n";
    cout<<"\t\t\t 1) Buy Product\n";
    cout<<"                     \n";
    cout<<"\t\t\t 2) Go Back    \n";
        cout << "\t\t\t Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            receipt();
            break;
        case 2:
            return;
        default:
            cout << "\nInvalid choice\n";
        }
    }
}

void shopping::add() {
    fstream data;
    int token = 0;
    int c;
    float p, d;
    string n;

    cout << "\n\t\t\t Add New Product";
    cout << "\n Product Code: ";
    cin >> pcode;
    cin.ignore();
    cout << " Product Name: ";
    getline(cin, pname);
    cout << " Price (Rs): ";
    cin >> price;
    cout << " Discount (%): ";
    cin >> discount;

    data.open("database.txt", ios::in);
    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    } else {
        while (data >> c >> n >> p >> d) {
            if (c == pcode) {
                token = 1;
                break;
            }
        }
        data.close();

        if (token == 1) {
            cout << "\nProduct code already exists. Try again.\n";
            return;
        }

        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }

    cout << "\nProduct Added Successfully!\n";
}

void shopping::edit() {
    fstream data, data1;
    int pkey, c, token = 0;
    float p, d;
    string n;

    cout << "\n\t\t\t Modify Product\n";
    cout << " Product Code to Modify: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\nFile doesn't exist.\n";
        return;
    }

    data1.open("database1.txt", ios::out);
    while (data >> pcode >> pname >> price >> discount) {
        if (pcode == pkey) {
            cout << "\n New Product Code: ";
            cin >> c;
            cin.ignore();
            cout << " New Product Name: ";
            getline(cin, n);
            cout << " New Price: ";
            cin >> p;
            cout << " New Discount: ";
            cin >> d;

            data1 << c << " " << n << " " << p << " " << d << "\n";
            token = 1;
            cout << "\nProduct Modified Successfully!\n";
        } else {
            data1 << pcode << " " << pname << " " << price << " " << discount << "\n";
        }
    }

    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0) {
        cout << "\nProduct Not Found.\n";
    }
}

void shopping::rem() {
    fstream data, data1;
    int pkey, token = 0;
    cout << "\n\t\t\t Delete Product\n";
    cout << " Enter Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\nFile doesn't exist.\n";
        return;
    }

    data1.open("database1.txt", ios::out);
    while (data >> pcode >> pname >> price >> discount) {
        if (pcode == pkey) {
            cout << "\nProduct Deleted Successfully\n";
            token = 1;
        } else {
            data1 << pcode << " " << pname << " " << price << " " << discount << "\n";
        }
    }

    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0) {
        cout << "\nProduct Not Found.\n";
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|____________________________________________|\n";
    cout << "ProCode\tName\t\tPrice\n";
    cout << "|____________________________________________|\n";

    while (data >> pcode >> pname >> price >> discount) {
        cout << pcode << "\t" << pname << "\t\t" << price << "\n";
    }

    data.close();
}

void shopping::receipt() {
    fstream data;
    int arrc[100], arrq[100], c = 0;
    char choice;
    float amount, total = 0;

    list();

    cout << "\n_________________ORDER_________________\n";
    do {
        cout << "\nEnter Product Code: ";
        cin >> arrc[c];
        cout << "Enter Quantity: ";
        cin >> arrq[c];

        bool duplicate = false;
        for (int i = 0; i < c; i++) {
            if (arrc[i] == arrc[c]) {
                cout << "\nDuplicate product code. Try again.\n";
                duplicate = true;
                break;
            }
        }

        if (duplicate) continue;
        c++;

        cout << "Add more products? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\n\n\t\t\t______RECEIPT______\n";
    cout << "Code\tName\tQty\tPrice\tAmount\tAfter Discount\n";

    for (int i = 0; i < c; i++) {
        data.open("database.txt", ios::in);
        while (data >> pcode >> pname >> price >> discount) {
            if (pcode == arrc[i]) {
                amount = price * arrq[i];
                float discAmount = amount - (amount * discount / 100);
                total += discAmount;

                cout << pcode << "\t" << pname << "\t" << arrq[i] << "\t"
                     << price << "\t" << amount << "\t" << discAmount << "\n";
                break;
            }
        }
        data.close();
    }

    cout << "\nTotal Amount: Rs. " << total << "\n";
}

int main() {
    shopping s;
    s.menu();
    return 0;
}
