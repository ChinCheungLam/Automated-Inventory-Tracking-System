// ------------------------------------------------ customer.h -----------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: The Customer class represents a customer in the system. It stores the customer's ID, last name, and first name.
//          The class also provides functionality for adding transactions to the customer's history and displaying the transaction history.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// Customer stores a list of transactions performed by the customer. It assumes that the Customer object is properly initialized.
// --------------------------------------------------------------------------------------------------------------------
//By Eugene
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <vector>
#include<iostream>
#include"transaction.h"
using namespace std;

class Transaction; // Forward declaration
class DataLoader; // Forward declaration
class CommandHandler; // Forward declaration


class Customer {
public:
    Customer(int customerId, const string& lastName, const string& firstName);
    int getCustomerId() const;
    string getLastName() const;
    string getFirstName() const;
    void addTransaction(Transaction* transaction);
    const vector<Transaction*>& getTransactions() const;
    void displayHistory() const;

private:
    int customerId_;
    string lastName_;
    string firstName_;
    vector<Transaction*> transactions_;
};
#endif