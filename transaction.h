// ------------------------------------------------ transaction.h -----------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class represents a Transaction, with a customer, movie, and action type (like borrow or return).
//          It provides getter methods for these attributes.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// We assume that the action type is always provided and is correct.
// The Transaction class does not modify the state of the customer or the movie. 
// --------------------------------------------------------------------------------------------------------------------
//By lam
#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include "movie.h"
#include "customer.h"

using namespace std;

// Forward declarations
class Customer;
class Movie;

class Transaction {
public:
    Transaction(Customer* customer, Movie* movie, char actionType);
    char getActionType() const;
    Customer* getCustomer() const;
    Movie* getMovie() const;

private:
    char actionType_;
    Customer* customer_;
    Movie* movie_;
};
#endif
