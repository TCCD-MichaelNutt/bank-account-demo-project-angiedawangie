#pragma once
#include <string>
using namespace std;

class Account
{
public:
    Account(string name, string pin, float startingBalance)
        : m_customerName{ name }, m_pin{ pin }, m_accountBalance{ startingBalance }
    {
        if (m_accountBalance < 0)
            m_accountBalance = 0;
    }
    // Verifies PIN, returns current account balance
    float checkBalance(string pin);
    // Verifies PIN, returns customer name
    string getCustomerName(string pin);
    // Verifies PIN, increases balance by amount
    void deposit(string pin, float amount);
    // Verifies PIN, reduces balance by amount
    void withdraw(string pin, float amount);
private:
    string m_customerName{ "Test Customer" };
    string m_pin{ "1234" };
    float m_accountBalance{ 0.0f };
    void updateBalance(float amount);
};