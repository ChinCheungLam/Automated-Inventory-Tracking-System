// ------------------------------------------------ commandHandler.h -----------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: The CommandHandler class processes a series of commands from a specified file. It interacts with an Inventory,
//          a TransactionHistory, and a CustomerList to handle commands such as displaying inventory, showing transaction 
//          history, and borrowing/returning movies.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// CommandHandler reads commands from file using std::ifstream and processes them by interacting with various components of the system.
// The class assumes that the command file is correctly formatted and that the referenced objects are initialized properly.
// --------------------------------------------------------------------------------------------------------------------
//By lam & Eugene
#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_
#include<string>
#include<sstream>
#include <fstream>
#include<iostream>
#include "inventory.h"
#include "transactionHistory.h"
#include "customerList.h"

using namespace std;

class CommandHandler {
public:
    CommandHandler(Inventory& inventory, TransactionHistory& history, CustomerList& customers);
    // Process commands from file
    void processCommands(const std::string& filename);

private:
    Inventory& inventory_;
    TransactionHistory& history_;
    CustomerList& customers_;
};
#endif