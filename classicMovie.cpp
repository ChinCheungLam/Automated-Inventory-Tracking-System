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
#include "classicMovie.h"

ClassicMovie::ClassicMovie(int stock, const string& director, const string& title, const string& majorActorMonthYear) :
    Movie('C', stock, director, title, majorActorMonthYear), title_(title), director_(director), majorActorMonthYear_(majorActorMonthYear) {}

const string& ClassicMovie::getMajorActor() const {
    return majorActorMonthYear_;
}

const string& ClassicMovie::getTitle() const
{
    return title_;
}

const string& ClassicMovie::getDirector() const
{
    return director_;
}


bool ClassicMovie::operator==(const Movie& other) const {
    auto& otherMovie = static_cast<const ClassicMovie&>(other);
    return Movie::operator==(other) && majorActorMonthYear_ == otherMovie.majorActorMonthYear_ && title_ == otherMovie.title_ && director_ == otherMovie.director_;
}

bool ClassicMovie::operator!=(const Movie& other) const {
    return !(*this == other);
}
