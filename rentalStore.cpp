#include "rentalStore.h"

RentalStore::RentalStore() {}

void RentalStore::run() {
    DataLoader dataLoader(inventory_, customerList_);
    CommandHandler commandHandler(inventory_, transactionHistory_, customerList_);

    dataLoader.loadMovies("data4movies.txt");
    dataLoader.loadCustomers("data4customers.txt");

    //inventory_.printInventory();
    // process commands using CommandHandler
    commandHandler.processCommands("data4commands.txt");
}