// ------------------------------------------------ customerList.h -----------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: The CustomerList class manages a collection of Customer objects. It provides functions for adding, retrieving,
//          and removing customers.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// CustomerList stores customers in a hash table where the key is the customer's ID. It assumes that the customers have unique IDs.
// --------------------------------------------------------------------------------------------------------------------
//By Eugene
#ifndef CUSTOMER_LIST_H_
#define CUSTOMER_LIST_H_
#include "hash.h"
#include "customer.h"

class CustomerList {
public:
    // Add a customer to the list
    void addCustomer(Customer* customer);
    // Remove a customer from the list
    bool removeCustomer(int customerId);
    // Get a customer by ID
    Customer* getCustomer(int customerId) const;

private:
    Hash<int, Customer*> customers_;
};
#endif
