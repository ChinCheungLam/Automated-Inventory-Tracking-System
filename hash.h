// ------------------------------------------------hash.h---------------------------------------------------- -
// Chin Cheung Lam CSS 343 A Spring 2023
// May 28, 2023
// June 2, 2023
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This template class implements a hash table with separate chaining as collision resolution strategy.
//          The class supports basic operations such as adding an item, retrieving an item and removing an item.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// The class uses the std::hash function to compute the hash value for a given key.
// We assume that the key type supports the std::hash function.
// We also assume that the initial size of the hash table does not need to be increased.
// --------------------------------------------------------------------------------------------------------------------
//By lam & Eugene
#ifndef HASH_H_
#define HASH_H_

#include <vector>
#include <list>
#include <functional>
#include <utility>

const int INITIAL_SIZE = 1000; // Choose an initial size for your hash table

template<typename KeyType, typename ValueType>
class Hash {
public:
    Hash() {
        data.resize(INITIAL_SIZE);
    }

    std::size_t size() const {
        size_t count = 0;
        for (auto& bucket : data) {
            count += bucket.size();
        }
        return count;
    }

    bool addItem(const KeyType& key, const ValueType& value) {
        int index = hashFunction(key);
        for (auto& item : data[index]) {
            if (item.first == key) { // update existing
                item.second = value;
                return true;
            }
        }
        // Insert new item
        data[index].push_back(std::make_pair(key, value));
        return true;
    }

    void forEachItem(const std::function<void(const std::pair<KeyType, ValueType>&)>& func) const {
        for (const auto& bucket : data) {
            for (const auto& item : bucket) {
                func(item);
            }
        }
    }

    const ValueType* getItem(const KeyType& key) const {
        int index = hashFunction(key);
        for (const auto& item : data[index]) {
            if (item.first == key) {
                return &item.second;
            }
        }
        return nullptr;
    }

    bool removeItem(const KeyType& key) {
        int index = hashFunction(key);
        for (auto it = data[index].begin(); it != data[index].end(); ++it) {
            if (it->first == key) {
                data[index].erase(it);
                return true;
            }
        }
        return false;
    }

private:
    std::vector<std::list<std::pair<KeyType, ValueType>>> data;

    int hashFunction(const KeyType& key) const {
        return std::hash<KeyType>()(key) % data.size();
    }
};
#endif