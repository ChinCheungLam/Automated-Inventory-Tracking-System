#include "dataLoader.h"
#include"classicMovie.h"
#include"comedyMovie.h"
#include"dramaMovie.h"

DataLoader::DataLoader(Inventory& inventory, CustomerList& customers)
    : inventory_(inventory), customers_(customers) {}

void DataLoader::loadMovies(const string& filename) {
    std::ifstream infile(filename);
    std::string line;
    if (!infile.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string typeStr, stockStr, director, title;

        std::getline(ss, typeStr, ',');
        std::getline(ss, stockStr, ',');
        std::getline(ss, director, ',');
        std::getline(ss, title,',');

        char type = typeStr[0];
        int stock;

        try {
            stock = std::stoi(stockStr);
        }
        catch (std::invalid_argument const& e) {
            std::cout << "Bad input: std::invalid_argument thrown Movies" << '\n';
            continue;
        }
        catch (std::out_of_range const& e) {
            std::cout << "Integer overflow: std::out_of_range thrown Movies" << '\n';
            continue;
        }

        Movie* newMovie = nullptr;
        switch (type) {
        case 'C': {
            std::string majorActorMonthYear;
            std::getline(ss, majorActorMonthYear);
            newMovie = new ClassicMovie(stock, director, title, majorActorMonthYear);
            break;
        }
        case 'F':
        case 'D': {
            std::string yearStr;
            std::getline(ss, yearStr, ',');
            int year;
            try {
                year = std::stoi(yearStr);
            }
            catch (std::invalid_argument const& e) {
                std::cout << "Bad input: std::invalid_argument thrown Movies" << '\n';
                continue;
            }
            catch (std::out_of_range const& e) {
                std::cout << "Integer overflow: std::out_of_range thrown Movies" << '\n';
                continue;
            }

            if (type == 'F') {
                newMovie = new ComedyMovie(stock, director, title, year);
            }
            else {
                newMovie = new DramaMovie(stock, director, title, year);
            }
            break;
        }
        default:
            std::cout << "Unknown movie type: " << type << '\n';
            continue;
        }

        if (newMovie) {
            inventory_.addMovie(newMovie);
        }
    }
    infile.close();
}

void DataLoader::loadCustomers(const string& filename) {
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        stringstream ss(line);
        string customerIdStr, lastName, firstName;

        getline(ss, customerIdStr);
        getline(ss, lastName);
        getline(ss, firstName);

        int customerId;
        try {
            customerId = std::stoi(customerIdStr);
        }
        catch (std::invalid_argument const& e) {
            std::cout << "Bad input: std::invalid_argument thrown Customers" << '\n';
            continue;
        }
        catch (std::out_of_range const& e) {
            std::cout << "Integer overflow: std::out_of_range thrown Customers" << '\n';
            continue;
        }

        Customer* newCustomer = new Customer(customerId, lastName, firstName);
        customers_.addCustomer(newCustomer);
    }
    infile.close();
}
