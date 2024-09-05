#include <iostream>
#include <string>
#include "account.h"
using namespace std;

void Account::deposit(string pin, float amount)
{
    int result{ 0 };

    while (pin != m_pin)
    {
        cout << "Invalid PIN\nTry again.\n";
        cin >> pin;
    }
    if (amount > 0)
    {
        updateBalance(amount);
        switch (result)
        {
        case 0:
        {
            cout << "Deposit Successful\n";
            m_depositHistory.push_back(amount);
            break;
        }
        case -1:
        {
            cout << "Deposit failed ...\n";
            break;
        }
        }
    }
    return;
}

void Account::withdraw(string pin, float amount)
{
    int result{ 0 };

    while (pin != m_pin)
    {
        cout << "Invalid PIN\nTry again.\n";
        cin >> pin;
    }
    if (amount < 0 && m_accountBalance > -amount)
    {
        updateBalance(amount);
        switch (result)
        {
        case 0:
        {
            cout << "Withdraw Successful\n";
            break;
        }
        case -1:
        {
            cout << "Deposit failed ...\n";
            break;
        }
        }
    }
    return;
}

void Account::updateBalance(float amount)
{
    m_accountBalance += amount;
}

string Account::getCustomerName(string pin)
{
    if (pin == m_pin)
        return m_customerName;
    return "Invalid PIN\n";
}

float Account::checkBalance(string pin)
{
    if (pin == m_pin)
        return m_accountBalance;
    return -1.0f;
}

void Account::printDepositHistory()
{
    int numDeposits = m_depositHistory.size();

    for (int i{ 0 }; i < numDeposits; i++)
    {
        cout << m_depositHistory[i] << "\n";
    }

    return;
}}