// ------------------------------------------------ dataLoader.h -----------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: The DataLoader class is responsible for loading movies and customers data from specified files.
//          It uses Inventory and CustomerList instances for storing data. The class provides methods for loading
//          data, which includes error handling for common issues like invalid inputs and unknown movie types.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// DataLoader utilizes std::ifstream to read data from files. The class assumes that the data files are properly
// formatted and that the Inventory and CustomerList objects are initialized correctly.
// --------------------------------------------------------------------------------------------------------------------
//By lam & Eugene
#ifndef DATA_LOADER_H_
#define DATA_LOADER_H_
#include <string>
#include <sstream>
#include <fstream>
#include<iostream>
#include "inventory.h"
#include "customerList.h"
#include"movie.h"

using namespace std;

class DataLoader {
public:
    DataLoader(Inventory& inventory, CustomerList& customers);
    // Load movie data from file
    void loadMovies(const std::string& filename);
    // Load customer data from file
    void loadCustomers(const std::string& filename);

private:
    Inventory& inventory_;
    CustomerList& customers_;
};
#endif