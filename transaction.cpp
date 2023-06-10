#include "transaction.h"
#include "customer.h" 

Transaction::Transaction(Customer* customer, Movie* movie, char actionType) :customer_(customer), movie_(movie), actionType_(actionType)
{
}

char Transaction::getActionType() const {
    return actionType_;
}

Customer* Transaction::getCustomer() const {
    return customer_;
}

Movie* Transaction::getMovie() const {
    return movie_;
}
