// Menuprogram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<map> 
#include<string>
using namespace std;

//enum for the commands
enum commands {
    DISPLAY_ALL_CONTACT = 'l',
    VIEW_CONTACT = 'v',
    ADD_CONTACT = 'a',
    DELETE_CONTACT = 'd',
    EXIT_PROGRAM = 'x'
};

//container to store the contact data
// storing all details using string
struct Contact {
    string name, email, phone;
    //default constructor
    Contact() {}
    //parametrized constructor
    Contact(string name, string email, string phone) {
        this->name = name;
        this->email = email;
        this->phone = phone;
    }
};


int main() {
    //printing the menu for user
    cout << "Contact Manager\n\n";
    cout << "COMMAND MENU\n";
    cout << "l - Display all contacts\n";
    cout << "v - view a contact\n";
    cout << "a - Add a contact\n";
    cout << "d - Delete a contact\n";
    cout << "x - Exit program\n";

    // to check if user command is x or not
    bool flag = true;
    // taking user command as input
    char command;

    //map container to store the contacts where key is the number
    // it is mapping contacts to the index integer
    map<int, Contact> contacts;

    // prompting user to command menu until he wants to exit
    // loop breaks when user press x
    while (flag) {
        // reading the command from user
        cout << "\nCommand: ";
        cin >> command;
        cin.ignore(); // ignoring endl(\n) character
        // using switch case to handle all commands
        switch (command) {
            // if command is to list all contact
        case DISPLAY_ALL_CONTACT: {
            //checking if contacts list is empty
            int x = contacts.size();
            try {
                if (x == 0) {
                    throw x; // throwing an exception
                }
            }
            // handling the exception
            catch (int x) {
                cout << "There are no contacts in the list \n";
            }
            //displaying all the contacts
            for (pair<int, Contact> contact : contacts) {
                cout << contact.first << ". " << contact.second.name << endl;
            }
            cout << endl;
        }
                                break;
                                //view a specific contact
        case VIEW_CONTACT: {
            // asking index of number in the list
            cout << "Number: ";
            int number;
            cin >> number;
            cin.ignore(); // ignoring endl character
            //It returns pointer to the contact
            auto itr = contacts.find(number);
            //checking if the number is valid
            if (itr == contacts.end()) {
                cout << "Invalid contact number\n";
            }
            else {
                cout << "Name: " << itr->second.name << endl;
                cout << "Email: " << itr->second.email << endl;
                cout << "Phone: " << itr->second.phone << endl;
            }
            break;
        }
                         // to add a new contact in the list
        case ADD_CONTACT: {
            string name, email, phone;
            cout << "Name: ";
            getline(cin, name);
            if (name == "")
                getline(cin, name);
            cout << "Email: ";
            getline(cin, email);
            cout << "Phone: ";
            getline(cin, phone);

            //adding contact in the map
            contacts[contacts.size() + 1] = Contact(name, email, phone);
            cout << name << " was added\n";
            break;
        }
                        // deleting contact from given index
        case DELETE_CONTACT: {
            int number;
            cout << "Enter index of Number: ";
            cin >> number;
            cin.ignore(); // ignoring endl character
            //It returns pointer to the contact
            auto itr = contacts.find(number);
            //checking if the contact is valid
            if (itr == contacts.end()) {
                cout << "Invalid contact number\n";
            }
            else {
                string name = contacts[number].name;
                //deleting contact
                contacts.erase(number);
                cout << name << " was deleted\n";
            }
            break;
        }
                           //exit program
        case EXIT_PROGRAM: {
            // setting flag to false
            flag = false;
            break;
        }
        default: {
            cout << "INVALID INPUT\n";
            break;
        }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
