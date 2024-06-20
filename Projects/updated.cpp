#include <iostream>
#include <fstream>

using namespace std;

class temp
{
    string username, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signup();
    void forget();
};

temp obj; // Move the object declaration outside main

int main()
{
    char choice;
    cout << "1-Login" << endl;
    cout << "2-Sign-up" << endl;
    cout << "3-Forget Password" << endl;
    cout << "4-Exit" << endl;
    cout << "Enter Your Choice:" << endl;
    cin >> choice;
    cin.ignore(); // Ignore the newline character left in the buffer

    switch (choice)
    {
    case '1':
        obj.login();
        break;

    case '2':
        obj.signup();
        break;

    case '3':
        obj.forget();
        break;

    case '4':
        return 0;

    default:
        cout << "Invalid Option..." << endl;
    }
}

void temp ::signup()
{
    cout << "Enter Your User Name :" << endl;
    getline(cin, username);
    cout << "Enter Your Email Address :" << endl;
    getline(cin, Email);
    cout << "Enter Your Password :" << endl;
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);

    if (file.is_open())
    {
        file << username << "*" << Email << "*" << password << endl;
        file.close();
        cout << "Account created successfully." << endl;
    }
    else
    {
        cout << "Error opening file for writing." << endl;
    }
}

void temp ::login()
{
    cout << ".........Login.........." << endl;
    cout << "Enter Your User Name :" << endl;
    getline(cin, searchName);
    cout << "Enter Your Password :" << endl;
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    while (!file.eof())
    {
        getline(file, username, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');

        if (username == searchName && password == searchPass)
        {
            cout << "Account Login Successfully..." << endl;
            cout << "Username: " << username << endl;
            cout << "Email: " << Email << endl;
            break; // Break out of the loop once a match is found
        }
    }

    file.close();
}

void temp::forget()
{
    cout << "Enter Your Username :" << endl;
    getline(cin, searchName);
    cout << "Enter your Email Address :" << endl;
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    bool found = false;

    while (!file.eof())
    {
        getline(file, username, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');

        if (username == searchName && Email == searchEmail)
        {
            cout << "Account Found..." << endl;
            cout << "Your Password: " << password << endl;
            found = true;
            break; // Break out of the loop once a match is found
        }
    }

    if (!found)
    {
        cout << "Account not found." << endl;
    }

    file.close();
}
