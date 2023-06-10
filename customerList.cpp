#include "customerList.h"

void CustomerList::addCustomer(Customer* customer) {
    customers_.addItem(customer->getCustomerId(), customer);
}

bool CustomerList::removeCustomer(int customerId) {
    auto it = customers_.getItem(customerId);
    if (it != nullptr) {
        delete* it;
        customers_.removeItem(customerId);
        return true;
    }
    return false;
}

Customer* CustomerList::getCustomer(int customerId) const {
    auto it = customers_.getItem(customerId);
    return it != nullptr ? *it : nullptr;
}
