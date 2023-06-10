// ------------------------------------------------ inventory.h -----------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class represents the inventory of movies. 
//          It uses the Hash class to maintain the inventory and provides methods to add, borrow, return, and retrieve movies.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// The inventory class uses different keys for the hash table based on the status of the movie.
// For Classic movies, it uses the major actor and the month/year as the key.
// For Drama movies, it uses the director and the title as the key.
// For other types of movies, it uses the title and the year as the key.
// We assume that the input data for each movie is correct and sufficient to construct the respective key.
// --------------------------------------------------------------------------------------------------------------------
//By lam & Eugene
#ifndef INVENTORY_H_
#define INVENTORY_H_
#include "hash.h"
#include<iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "movie.h"

class DataLoader;//Forward
class CommandHandler;//Forward


class Inventory {
public:
    // Add a movie to the inventory
    bool addMovie(Movie* movie);
    // Borrow a movie from the inventory
    bool borrowMovie(const Movie& movie);
    // Return a movie to the inventory
    bool returnMovie(const Movie& movie);
    // Get a movie from the inventory
    Movie* getMovie(const Movie& movie) const;
    Movie* getMovieByTitle(const string& title) const;
    Movie* getMovieByData(const std::string& movieType, const std::string& movieData, const std::string& movieData2) const;
    Movie* getMovieByKey(const std::string& key) const;
    void printInventory() const;

private:
    Hash<std::string, Movie*> inventory_;
};
#endif