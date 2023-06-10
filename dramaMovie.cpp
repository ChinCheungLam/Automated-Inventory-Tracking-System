#include "dramaMovie.h"

DramaMovie::DramaMovie(int stock, const std::string& director, const std::string& title, int year) :
    Movie('D', stock, director, title, year) {}

const string& DramaMovie::getDirector() const
{
    return director_;
}

const int& DramaMovie::getYear() const
{
    return year_;
}

const string& DramaMovie::getTitle() const
{
    return title_;
}

bool DramaMovie::operator==(const Movie& other) const {
    auto& otherMovie = static_cast<const DramaMovie&>(other);
    return Movie::operator==(other) && year_ == otherMovie.year_ && title_ == otherMovie.title_ && director_ == otherMovie.director_;
}

bool DramaMovie::operator!=(const Movie& other) const {
    return !(*this == other);
}