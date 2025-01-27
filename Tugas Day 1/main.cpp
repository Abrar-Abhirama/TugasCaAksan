#include <iostream>
#include <string>

using namespace std;

class Contact {
private:
    string name;
    string address;
    string strength;

public:
    Contact(string n = "", string a = "", string s = "") {
        name = n;
        address = a;
        strength = s;
    }

    void displayContact() {
        if (name != "") {
            cout << "Name: " << name << ", Address: " << address << ", Strength: " << strength << endl;
        }
    }

    string getName() {
        return name;
    }

    void setContact(string n, string a, string s) {
        name = n;
        address = a;
        strength = s;
    }
};

class PhoneBook {
private:
    Contact contacts[8];  // Maksimal 8 kontak
    int currentSize;

public:
    PhoneBook() : currentSize(0) {}

    void addContact(string name, string address, string strength) {
        if (currentSize < 8) {
            contacts[currentSize].setContact(name, address, strength);
            currentSize++;
            cout << "Contact Ditambah" << endl;
        } else {
            for (int i = 0; i < 7; i++) {
                contacts[i] = contacts[i + 1];  
            }
            contacts[7].setContact(name, address, strength); 
            cout << "Phonebook penuh, Contact lama di hapus\n";
        }
    }

    void searchContact(string name) {
        bool found = false;
        cout << "Contacts :\n";
        for (int i = 0; i < currentSize; i++) {
            cout << i + 1 << ". " << contacts[i].getName() << endl;
        }
        cout << "Pilih Contact: ";
        int choice;
        cin >> choice;

        // Validasi input
        if (choice >= 1 && choice <= currentSize) {
            contacts[choice - 1].displayContact(); 
        } else {
            cout << "Error.\n";
        }
    }

    void resetPhoneBook() {
        currentSize = 0; 
        cout << "Phonebook ter reset\n";
    }
};

int main() {
    PhoneBook phonebook;
    string name, address, strength;
    int choice;

    while (true) {
        cout << "1. ADD\n";
        cout << "2. SEARCH\n";
        cout << "3. EXIT\n";
        cout << "Ketik nomor fitur : ";
        cin >> choice;

        if (choice == 1) {
            cout << "Masukan name: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "masukan address: ";
            getline(cin, address);
            cout << "masukan strength: ";
            getline(cin, strength);
            phonebook.addContact(name, address, strength);
        } else if (choice == 2) {
            phonebook.searchContact(name);
        } else if (choice == 3) {
            phonebook.resetPhoneBook(); 
            return 0; 
        } else {
            cout << "Error, coba lagi\n";
        }
    }
}
