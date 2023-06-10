#include "transactionHistory.h"

void TransactionHistory::addTransaction(Transaction* transaction) {
    int customerId = transaction->getCustomer()->getCustomerId();
    const std::vector<Transaction*>* customerTransactions = transactions_.getItem(customerId);
    if (customerTransactions == nullptr) {
        std::vector<Transaction*> newTransactionList;
        newTransactionList.push_back(transaction);
        transactions_.addItem(customerId, newTransactionList);
    }
    else {
        std::vector<Transaction*> updatedTransactionList = *customerTransactions;
        updatedTransactionList.push_back(transaction);
        transactions_.addItem(customerId, updatedTransactionList);
    }
}

std::vector<Transaction*> TransactionHistory::getTransactions(int customerId) const {
    const std::vector<Transaction*>* customerTransactions = transactions_.getItem(customerId);
    return customerTransactions != nullptr ? *customerTransactions : std::vector<Transaction*>();
}