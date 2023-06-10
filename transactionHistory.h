// ------------------------------------------------ transactionHistory.h ------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class represents the Transaction History for a set of customers.
//          It provides a method to add a new transaction, and another to get the list of transactions for a specific customer.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// The TransactionHistory class uses a vector to store the transactions for each customer.
// It makes use of the customer's ID to identify and retrieve their respective transactions.
// --------------------------------------------------------------------------------------------------------------------
//By lam
#ifndef TRANSACTION_HISTORY_H_
#define TRANSACTION_HISTORY_H_
#include <vector>
#include <unordered_map>
#include "transaction.h"
#include "hash.h"

class TransactionHistory {
public:
    // Add a transaction to the history
    void addTransaction(Transaction* transaction);
    // Get all transactions of a customer
    vector<Transaction*> getTransactions(int customerId) const;

private:
    Hash<int, std::vector<Transaction*>> transactions_;
};
#endif