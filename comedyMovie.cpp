#include "comedyMovie.h"

ComedyMovie::ComedyMovie(int stock, const std::string& director, const std::string& title, int year) :
    Movie('F', stock, director, title, year) {}

const string& ComedyMovie::getDirector() const
{
    return director_;
}

const int& ComedyMovie::getYear() const
{
    return year_;
}

const string& ComedyMovie::getTitle() const
{
    return title_;
}

bool ComedyMovie::operator==(const Movie& other) const {
    auto& otherMovie = static_cast<const ComedyMovie&>(other);
    return Movie::operator==(other) && year_ == otherMovie.year_ && title_ == otherMovie.title_ && director_ == otherMovie.director_;
}

bool ComedyMovie::operator!=(const Movie& other) const {
    return !(*this == other);
}