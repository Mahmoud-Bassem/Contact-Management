#include<bits\stdc++.h>
#include<fstream>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;

struct contact {
    string name, number, category, email;
    contact() {
        name = "";
        number = "";
        category = "";
        email = "";
    }   
};

void menu() {
    int choice;
    cout << "1) Add contact" << endl;
    cout << "2) Search contact" << endl;
    cout << "3) Edit contact" << endl;
    cout << "4) Delete contact" << endl;
    cout << "5) Import contact" << endl;
    cout << "6) Export contact" << endl;
    cout << "7) Exit" << endl;

}

void login() {

    string email, password;            // will it be of any benefit to make it static?
    cout << "Enter 1 if you want to log in, any other input will terminate the program : ";
    int ch; cin >> ch; 
    if (ch != 1) exit(0);
    cout << "email : "; cin >> email;
    cout << "password : "; cin >> password;
    if (email != "email" || password != "password") {
        cout << "invalid info, try again"; login();
    }
}

contact a[500];


int i;

void add(contact a[]) {
    // cout << a[0] ;
    contact c;
    cout << "Enter name, number, email : ";
    cin >> c.name >> c.number >> c.email;
    cout << endl << "Do you want to categorize this contact?";
    string ans;
    cin >> ans;
    if (ans == "yes") {
        cout << "Enter category : ";
        cin >> c.category; //mp[category].pb(c);
    }
    a[i++] = c; 
    
    cout << "\n contact added!\n";

}

void srsh() {
    cout << "\n Do you want to filter by category?\n";
    string ans, category, name, number, email;
    cin >> ans;
    if (ans == "yes") {

        cout << "1) Search by name : \n";
        cout << "2) Search by phone number : " << endl;
        cout << "3) Search by email address : " << endl;
        int ch; cin >> ch;
        bool found;
        switch (ch) {

        case 1:
            cout << "Enter category: ";
            cin >> category;
            cout << "\n Enter name : "; cin >> name;
            found = 0;
            for (auto& it : a) {
                if (it.name == name && it.category == category) {
                    found = 1;
                    cout << "email : " << it.email << " number : " << it.number << " category : " << it.category << endl; break;
                }
                
            }
            cout << (found ? "" : "contact not found!\n");
            break;

        case 2: cout << "Enter category: ";
            cin >> category;
            cout << "\n Enter number : "; cin >> number;
            found = 0;
            for (auto& it : a) {
                if (it.number == number && it.category == category) {
                    found = 1;
                    cout << "name : " << it.name << " email : " << it.email << " category : " << it.category << endl; break;
                }
                
            }
            cout << (found ? "" : "contact not found!\n");
            break;

        case 3: cout << "Enter category: ";
            cin >> category;
            cout << "\n Enter email : "; cin >> email;
            found = 0;
            for (auto& it : a) {
                if (it.email == email && it.category == category) {
                    found = 1;
                    cout << "name : " << it.name << " number : " << it.number << " category : " << it.category << endl; break;
                }
                
            }
            cout << (found ? "" : "contact not found!\n");
            break;


        }


    }
    else {
        cout << "1) Search by name : \n";
        cout << "2) Search by phone number : " << endl;
        cout << "3) Search by email address : " << endl;
        int ch; cin >> ch;
        bool found;
        switch (ch) {

        case 1:

            cout << "\n Enter name : "; cin >> name;
            found = 0;
            for (auto& it : a) {
                if (it.name == name) {
                    found = 1;
                    cout << "email : " << it.email << " number : " << it.number << " category : " << it.category << endl; break;
                }
                
            }
            cout << found ? "" : "contact not found!\n";
            break;

        case 2:
            cout << "\n Enter number : "; cin >> number;
            found = 0;
            for (auto& it : a) {
                if (it.number == number) {
                    found = 1;
                    cout << "name : " << it.name << " email : " << it.email << " category : " << it.category << endl;
                    break;
                }
                
            }
            cout << found ? "" : "contact not found!\n";
            break;

        case 3:
            cout << "\n Enter email : "; cin >> email;
            found = 0;
            for (auto& it : a) {
                if (it.email == email) {
                    found = 1;
                    cout << "name : " << it.name << " number : " << it.number << " category : " << it.category << endl; break;
                }
                
            }
            cout << found ? "" : "contact not found!\n";
            break;


        }
    }
}

void edit() {
    string name;
    cout << "Enter contact name : " << endl;
    cin >> name;
    for (auto& it : a) {

        if (it.name == name) {
            string name;
            cout << "Enter new name : "; cin >> name; it.name = name;
            string number;
            cout << "Enter new number : "; cin >> number; it.number = number;
            string email;
            cout << "Enter new email : "; cin >> email; it.email = email;
            string category;
            cout << "Enter new category : "; cin >> category; it.category = category;
            cout << "new info saved! \n";
            break;
        }
    }

}

void dlt() {
    cout << "Enter name of contact: ";
    string name; cin >> name;
    for (auto& it : a) {
        if (it.name == name) {
            it.name = ""; it.number = ""; it.email = ""; it.category = ""; break;
        }
    }
    
    cout << "contact deleted!" << endl;
}

void imprt() {
    ifstream fin;
    fin.open("read.txt");
    contact c;
    fin >> c.name >> c.number >> c.email;
    forn(i, 500) {
        if (a[i].name == "") {
            a[i] = c;  break;
        }
    }
    cout << "contact imported successfully!\n";
}

void exprt() {
    ofstream fout;
    fout.open("cout.txt");
    contact c;
    cout << "Enter name, number, email : ";
    cin >> c.name >> c.number >> c.email;
    cout << endl << "Do you want to categorize this contact?";
    string ans;
    cin >> ans;
    if (ans == "yes") {
        cout << "Enter category : ";
        cin >> c.category; //mp[category].pb(c);
        fout << c.name << "  " << c.number << "    " << c.email << c.category;
    }


    else fout << c.name << "  " << c.number << "    " << c.email;


}

signed main() {
    
    login();
    while (true) {
        menu();
        int choice{};
        cin >> choice;
        switch (choice) {
        case 1: add(a); break;
        case 2: srsh(); break;
        case 3: edit(); break;
        case 4: dlt(); break;
        case 5: imprt(); break;
        case 6: exprt(); break;
        default: exit(0);

        }
    }



    return 0;
}
