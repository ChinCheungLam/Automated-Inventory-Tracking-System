#include "customer.h"

Customer::Customer(int customerId, const string& lastName, const string& firstName) :
    customerId_(customerId), lastName_(lastName), firstName_(firstName) {}

int Customer::getCustomerId() const {
    return customerId_;
}

string Customer::getLastName() const {
    return lastName_;
}

string Customer::getFirstName() const {
    return firstName_;
}

void Customer::addTransaction(Transaction* transaction) {
    transactions_.push_back(transaction);
}

const vector<Transaction*>& Customer::getTransactions() const {
    return transactions_;
}

void Customer::displayHistory() const
{
    for (const auto& transaction : transactions_) {
        std::cout << "Movie Title: " << transaction->getMovie()->getTitle()
            << ", Transaction Type: " << transaction->getActionType() << std::endl;
    }
}
