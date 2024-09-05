#include <iostream>
#include <string>
#include "account.h"
using namespace std;

static void menu(Account customer)
{
    int numTries{ 0 };
    int limit{ 3 };
    string pin{};
    bool correctPin{ false };
    int option{ 0 };
    const int deposit{ 1 };
    const int withdraw{ 2 };
    const int balance{ 3 };
    const int history{ 4 };
    const int exit{ 5 };

    do
    {
        cout << "Enter your pin: ";
        cin >> pin;
        correctPin = customer.checkPin(pin);
        numTries++;
    } while (!correctPin && numTries <= limit);

    // If the pin is still incorrect
    if (!correctPin)
    {
        cout << "Too many attempts\n";
        return;
    }

    // Now the menu:
    do
    {
        cout << "1. Deposit\n"
            << "2. Withdraw\n"
            << "3. Check Balance\n"
            << "4. Print Deposit History\n"
            << "5. Exit\n";

        cin >> option;

        switch (option)
        {
        case deposit:
            customer.deposit(pin, 20.0f);
            break;
        case withdraw:
            customer.withdraw(pin, -20.0f);
            break;
        case balance:
            cout << customer.checkBalance(pin) << endl;
            break;
        case history:
            customer.printDepositHistory();
            break;
        case exit:
            return;
        default:
            cout << "Invalid menu option\n";
            option = 0;
            break;
        }

    } while (true);
}

int main()
{
    Account testAccount{ "test name", "1234", 100.0f };

    menu(testAccount);

    return 0;
}