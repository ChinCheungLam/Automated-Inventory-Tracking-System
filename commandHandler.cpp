#include "commandHandler.h"

CommandHandler::CommandHandler(Inventory& inventory, TransactionHistory& history, CustomerList& customers) : inventory_(inventory), history_(history), customers_(customers) {}

void CommandHandler::processCommands(const std::string& filename) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string commandTypeStr, customerIdStr, mediaTypeStr, movieTypeStr;

        ss >> commandTypeStr >> customerIdStr >> mediaTypeStr >> movieTypeStr;

        char commandType = commandTypeStr[0];
        char movieType = movieTypeStr[0];

        if (commandType == 'I') {
            inventory_.printInventory();
        }
        else if (commandType == 'H') {
            int customerId = std::stoi(customerIdStr);

            // Fetch the customer from the customer list
            Customer* customer = customers_.getCustomer(customerId);
            if (customer != nullptr) {
                // Fetch the customer's transaction history
                std::vector<Transaction*> transactions = history_.getTransactions(customerId);

                // Print the transaction history
                std::cout << "Transaction history for: "<< customer->getFirstName()<<" "<< customer->getLastName() << "customer ID " << customerId << ":\n";
                for (Transaction* transaction : transactions) {
                    Movie* movie = transaction->getMovie();
                    char actionType = transaction->getActionType();
                    std::cout << "Action: " << actionType
                        << ", Movie: " << movie->getTitle()
                        << ", Director: " << movie->getDirector();
                    if(movie->getStatus() == 'C') {
                        std::cout << ", Actor and Date: " << movie->getMajorActorMonthYear() << endl;
                    }
                    else
                    {
                        std::cout << ", Year: " << movie->getYear() << endl;
                    }
                }
            }
            else {
                std::cout << "No such customer with ID: " << customerId << endl;
            }
        }
        else if (commandType == 'B' || commandType == 'R') {
            Movie* movie = nullptr;

            if (movieType == 'C') {
                std::string majorActorMonthYear, title;
                std::getline(ss >> std::ws, majorActorMonthYear, ' ');
                std::string yearStr;
                ss >> yearStr;
                majorActorMonthYear += " " + yearStr;
                ss.ignore(); // ignore space after majorActorMonthYear
                std::getline(ss >> std::ws, title);
                if (!title.empty() && title.back() == '\r') {
                    title.pop_back();
                }
                movie = inventory_.getMovieByData(movieTypeStr, majorActorMonthYear, title);
            }
            else if (movieType == 'F') {
                std::string title, yearStr;
                getline(ss, title, ','); // read title up to comma
                ss.ignore(); // ignore space after comma
                getline(ss, yearStr); // read rest of line into yearStr
                // Remove carriage return character if present
                if (!yearStr.empty() && yearStr.back() == '\r') {
                    yearStr.pop_back();
                }
                movie = inventory_.getMovieByData(movieTypeStr, title, yearStr);
            }
            else if (movieType == 'D') {
                std::string director, title;
                getline(ss, director, ','); // read director up to comma
                //ss.ignore(); // ignore space after comma
                getline(ss, title,','); // read rest of line into title
                movie = inventory_.getMovieByData(movieTypeStr, director, title);
            }

            if (movie == nullptr) {
                std::cout << "No such movie in inventory.\n";
                continue;
            }

            int customerId = std::stoi(customerIdStr);
            Customer* customer = customers_.getCustomer(customerId);
            if (customer == nullptr) {
                std::cout << "No such customer with ID: " << customerId << "\n";
                continue;
            }

            if (commandType == 'B') {
                if (movie->borrowMovie()) {
                    Transaction* transaction = new Transaction(customer, movie, 'B');
                    history_.addTransaction(transaction);
                    customer->addTransaction(transaction);
                }
                else {
                    std::cout << "Movie is out of stock.\n";
                }
            }
            else if (commandType == 'R') {
                if (movie->returnMovie()) {
                    Transaction* transaction = new Transaction(customer, movie, 'R');
                    history_.addTransaction(transaction);
                    customer->addTransaction(transaction);
                }
                else {
                    std::cout << "Invalid return operation.\n";
                }
            }
        }
        else {
            std::cout << "Unknown command: " << commandType << "\n";
        }
    }
    infile.close();
}