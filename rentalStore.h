// ------------------------------------------------ rentalStore.h -----------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: The RentalStore class represents the rental store system. It combines all other system components such as 
//          DataLoader, CommandHandler, Inventory, TransactionHistory, and CustomerList to operate as a unified system.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// The RentalStore class assumes that all data files are correctly formatted and that the DataLoader and CommandHandler 
// classes are initialized and operate correctly. The run() method is used to start the system.
// --------------------------------------------------------------------------------------------------------------------
//by Lam
#ifndef RENTAL_STORE_H_
#define RENTAL_STORE_H_
#include<iostream>
#include "dataLoader.h"
#include "commandHandler.h"
#include"hash.h"

using namespace std;

class RentalStore
{
public:
    RentalStore();

    void run();
private:
    Inventory inventory_;
    CustomerList customerList_; // List of customers
    TransactionHistory transactionHistory_; // Transaction history
};
#endif
