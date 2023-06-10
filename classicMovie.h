// ------------------------------------------------ classicMovie.h --------------------------------------------------
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class represents a Classic Movie. It inherits from the base Movie class and adds the attributes of the major actor and date.
//          It overrides some functions of the base class, such as the comparison operators, to include the new attributes.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// The class overrides the comparison operators to include new attributes in the comparison process.
// We assume that the major actor and date are always provided and are correct.
// --------------------------------------------------------------------------------------------------------------------
//by Lam & Eugene
#ifndef CLASSIC_MOVIE_H_
#define CLASSIC_MOVIE_H_
#include "movie.h"

class ClassicMovie : public Movie {
public:
    ClassicMovie(int stock, const string& director, const string& title, const string& majorActorMonthYear);
    ~ClassicMovie() override = default;

    // Accessors
    const string& getMajorActor() const;
    const string& getTitle() const;
    const string& getDirector() const;

    // Override comparison operators
    bool operator==(const Movie& other) const override;
    bool operator!=(const Movie& other) const override;

private:
    string majorActorMonthYear_, title_, director_;
};
#endif