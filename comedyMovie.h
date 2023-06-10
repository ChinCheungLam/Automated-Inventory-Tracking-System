// ------------------------------------------------ comedyMovie.h ---------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class represents a Comedy Movie. It inherits from the base Movie class.
//          It overrides some functions of the base class, such as the comparison operators.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// The class overrides the comparison operators to provide specialized comparison logic for comedy movies.
// --------------------------------------------------------------------------------------------------------------------
//By Lam
#ifndef COMEDY_MOVIE_H_
#define COMEDY_MOVIE_H_
#include "movie.h"

class ComedyMovie : public Movie {
public:
    ComedyMovie(int stock, const std::string& director, const std::string& title, int year);
    ~ComedyMovie() override = default;

    const string& getDirector() const;
    const int& getYear() const;
    const string& getTitle() const;

    // Override comparison operators
    bool operator==(const Movie& other) const override;
    bool operator!=(const Movie& other) const override;

private:
    string director_, title_;
    int year_;
};
#endif