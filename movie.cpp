#include "movie.h"

Movie::Movie(char status, int stock, const string& director, const string& title, int year) : status_(status), stock_(stock), director_(director), title_(title), year_(year)
{
}

Movie::Movie(char status, int stock, const string& director, const string& title, const string& majorActorMonthYear) : status_(status), stock_(stock), director_(director), title_(title), majorActorMonthYear_(majorActorMonthYear)
{
}

char Movie::getStatus() const
{
    return status_;
}

int Movie::getStock() const {
    return stock_;
}

void Movie::setStock(int stock) {
    stock_ = stock;
}

const string& Movie::getDirector() const {
    return director_;
}

const string& Movie::getTitle() const {
    return title_;
}

const string Movie::getMajorActorMonthYear() const
{
    stringstream ss(majorActorMonthYear_);
    string actorF, actorL, month, year;
    ss >> actorF >> actorL >> month >> year;
    return month + " " + year + ", " + actorF + " " + actorL;
}

int Movie::getYear() const {
    return year_;
}

bool Movie::borrowMovie() {
    if (stock_ > 0) {
        --stock_;
        return true;
    }
    return false;
}

bool Movie::returnMovie() {
    ++stock_;
    return true;
}

bool Movie::operator==(const Movie& other) const {
    return title_ == other.title_ && director_ == other.director_ && year_ == other.year_ || title_ == other.title_ && director_ == other.director_ && majorActorMonthYear_ == other.majorActorMonthYear_;
}

bool Movie::operator!=(const Movie& other) const {
    return !(*this == other);
}