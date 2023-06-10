// ------------------------------------------------ assignment4.cpp -----------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This is the entry point of the program. It initializes a RentalStore object and invokes the run() method 
//          to start the system. The system loads data, processes commands, and manages movie rentals for customers.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// The main function assumes that the RentalStore class is correctly implemented. The run() method in the RentalStore 
// class is responsible for handling all tasks related to the operation of the store.
// --------------------------------------------------------------------------------------------------------------------
#include"rentalStore.h"
#include <iostream>

int main()
{
    RentalStore store;
    store.run();
}
