// ------------------------------------------------ movie.h -------------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class represents a generic movie with status, stock, director, title, and year as its attributes.
//          It provides common methods that all movies need, such as borrowMovie and returnMovie, as well as various getters and setters.
//          It also includes methods to compare movies, which are used to manage the inventory.
//          This class is extended by specific movie types like ClassicMovie, ComedyMovie, and DramaMovie.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// The class uses pure virtual functions, which ensures that this base class cannot be instantiated on its own.
// We assume that the status character is always provided and is correct (i.e., 'F', 'C', 'D' for comedy, classic, and drama respectively).
// We assume that stock is always a positive integer. 
// The class provides a virtual destructor to allow derived classes to clean up correctly when a base class pointer is deleted.
// --------------------------------------------------------------------------------------------------------------------
//By lam
#ifndef MOVIE_H_
#define MOVIE_H_
#include <string>
#include <sstream>

using namespace std;

class Movie {
public:
    Movie(char status, int stock, const string& director, const string& title, int year);
    Movie(char status, int stock, const string& director, const string& title, const string& majorActorMonthYear);
    virtual ~Movie() = default;

    char getStatus() const;
    int getStock() const;
    void setStock(int stock);
    const string& getDirector() const;
    const string& getTitle() const;
    const string getMajorActorMonthYear() const;
    int getYear() const;


    // Borrow and return movie
    virtual bool borrowMovie();
    virtual bool returnMovie();

    // Comparison operators
    virtual bool operator==(const Movie& other) const;
    virtual bool operator!=(const Movie& other) const;

private:
    char status_;
    int stock_, year_;
    string director_, title_, majorActorMonthYear_;
};
#endif