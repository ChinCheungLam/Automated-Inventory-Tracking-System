#include "inventory.h"

bool Inventory::addMovie(Movie* movie) {
    std::string key;
    if (movie->getStatus() == 'C') {
        key = movie->getMajorActorMonthYear();
    }
    else if (movie->getStatus() == 'D') {
        key = movie->getDirector() + ", " + movie->getTitle() + ",";
    }
    else {
        key = movie->getTitle() + ", " + std::to_string(movie->getYear());
    }
    return inventory_.addItem(key, movie);
}

bool Inventory::borrowMovie(const Movie& movie) {
    std::string key;
    if (movie.getStatus() == 'C') {
        key = movie.getMajorActorMonthYear() + " " + movie.getTitle();
    }
    else if (movie.getStatus() == 'D') {
        key = movie.getDirector() + ", " + movie.getTitle() + ",";
    }
    else {
        key = movie.getTitle() + ", " + std::to_string(movie.getYear());
    }
    Movie* const* movieInInventory = inventory_.getItem(key);
    if (movieInInventory == nullptr || *movieInInventory == nullptr) return false;
    // check if movie is available
    if ((*movieInInventory)->getStock() <= 0) return false;

    bool borrowResult = (*movieInInventory)->borrowMovie();
    if (borrowResult) {
        // remove movie from inventory if borrowed
        inventory_.removeItem(key);
    }
    return borrowResult;
}

bool Inventory::returnMovie(const Movie& movie) {
    std::string key;
    if (movie.getStatus() == 'C') {
        key = movie.getMajorActorMonthYear() + " " + movie.getTitle();
    }
    else if (movie.getStatus() == 'D') {
        key = movie.getDirector() + ", " + movie.getTitle() + ",";
    }
    else {
        key = movie.getTitle() + ", " + std::to_string(movie.getYear());
    }
    Movie* const* movieInInventory = inventory_.getItem(key);
    Movie* newMovie = new Movie(movie);
    inventory_.addItem(key, newMovie);
    return (*movieInInventory)->returnMovie();
}

Movie* Inventory::getMovie(const Movie& movie) const {
    std::string key;
    if (movie.getStatus() == 'C') {
        key = movie.getMajorActorMonthYear() +" " + movie.getTitle();
    }
    else if (movie.getStatus() == 'D') {
        key = movie.getDirector() +", " + movie.getTitle() + ",";
    }
    else if (movie.getStatus() == 'F') {
        key = movie.getTitle() + ", " + std::to_string(movie.getYear());
    }
    Movie* const* movieInInventory = inventory_.getItem(key);
    return movieInInventory != nullptr ? *movieInInventory : nullptr;
}

Movie* Inventory::getMovieByTitle(const std::string& title) const {
    // Assuming movies are indexed by title in the Hash.
    Movie* const* movieInInventory = inventory_.getItem(title);
    return movieInInventory != nullptr ? *movieInInventory : nullptr;
}

Movie* Inventory::getMovieByData(const std::string& movieType, const std::string& movieData, const std::string& movieData2) const
{
    if (movieType == "C")
    {
        std::string key = movieData + ", " + movieData2;
        Movie* const* movieInInventory = inventory_.getItem(key);
        return movieInInventory != nullptr ? *movieInInventory : nullptr;
    }
    else if (movieType == "D")
    {
        std::string key = movieData + ", " + movieData2+ ",";
        Movie* const* movieInInventory = inventory_.getItem(key);
        return movieInInventory != nullptr ? *movieInInventory : nullptr;
    }
    else if (movieType == "F")
    {
        std::string key = movieData + ", " + movieData2;
        Movie* const* movieInInventory = inventory_.getItem(key);
        return movieInInventory != nullptr ? *movieInInventory : nullptr;
    }
}

Movie* Inventory::getMovieByKey(const std::string& key) const
{
    Movie* const* movieInInventory = inventory_.getItem(key);
    return movieInInventory != nullptr ? *movieInInventory : nullptr;
}

void Inventory::printInventory() const
{
    inventory_.forEachItem([](const std::pair<std::string, Movie*>& pair) {
        if (pair.second != nullptr) {
            Movie* movie = pair.second;
            if (movie->getStatus() == 'C') {
                std::cout << "Status: " << movie->getStatus()
                    << ", Stock: " << movie->getStock()
                    << ", Director: " << movie->getDirector()
                    << ", Title: " << movie->getTitle()
                    << ", Major Actor and Month Year: " << movie->getMajorActorMonthYear() << std::endl;
            }
            else
            {
                std::cout << "Status: " << movie->getStatus()
                    << ", Stock: " << movie->getStock()
                    << ", Director: " << movie->getDirector()
                    << ", Title: " << movie->getTitle()
                    << ", Year: " << movie->getYear() << std::endl;
            }
        }
    });
}
