//
// Created by Juan Diego on 9/5/2022.
//

#ifndef HASH_CHAIN_HASH_H
#define HASH_CHAIN_HASH_H

#include <functional>
#include "../list/forward/forward_list.h"

constexpr float max_fill_factor = 0.5;
constexpr float max_collision = 3;

template <typename KeyType, typename ValueType>
class chain_hash{

public:

    struct triplet{
        KeyType key;
        ValueType value;
        size_t hash_code;

        triplet();
        triplet(const chain_hash::triplet& other);
        explicit triplet(const KeyType& key, const ValueType& value, const size_t& hash_code);
    };

private:

    forward_list<triplet>* array;
    std::hash<KeyType> hash_functor;
    size_t capacity;
    size_t size;

public:

    chain_hash();                                                            // O(1)
    explicit chain_hash(const size_t& capacity);                             // O(n)

    [[nodiscard]] size_t bucket_count() const;                               // O(1)
    [[nodiscard]] size_t bucket_size(const size_t& i_bucket) const;          // O(1)
    [[nodiscard]] bool bucket_empty(const size_t& i_bucket) const;           // O(1)

    [[nodiscard]] size_t get_size() const;                                   // O(1)
    [[nodiscard]] float fill_factor() const;                                 // O(1)

    void rehashing();                                                        // O(n)
    // k := cantidad promedio de elementos en cada bucket
    void insert(const KeyType& key, const ValueType& value);                 // O(n), θ(k)
    void remove(const KeyType& key);                                         // O(n), θ(k)

    ValueType& get(const KeyType& key);                                // O(n), θ(k)
    ValueType& operator[](const KeyType& key);                               // O(n), θ(k)
    ValueType operator[](const KeyType& key) const;                          // O(n), θ(k)

    typename forward_list<triplet>::iterator begin(const index_t& i_bucket); // O(1)
    typename forward_list<triplet>::iterator end(const index_t& i_bucket);   // O(1)

};


template<typename KeyType, typename ValueType>
chain_hash<KeyType, ValueType>::triplet::triplet()
: key(KeyType()), value(ValueType()), hash_code(0){
}

template<typename KeyType, typename ValueType>
chain_hash<KeyType, ValueType>::triplet::triplet(const KeyType &key, const ValueType &value, const size_t &hash_code)
: key(key), value(value), hash_code(hash_code){
}

template<typename KeyType, typename ValueType>
chain_hash<KeyType, ValueType>::triplet::triplet(const chain_hash::triplet &other)
: key(other.key), value(other.value), hash_code(other.hash_code){
}

template<typename KeyType, typename ValueType>
chain_hash<KeyType, ValueType>::chain_hash()
: size(0), capacity(10){
    array = new forward_list<chain_hash<KeyType, ValueType>::triplet>[capacity];
}

template<typename KeyType, typename ValueType>
chain_hash<KeyType, ValueType>::chain_hash(const size_t &capacity)
: size(0), capacity(capacity){
    array = new forward_list<chain_hash<KeyType, ValueType>::triplet>[this->capacity];
}

template<typename KeyType, typename ValueType>
size_t chain_hash<KeyType, ValueType>::bucket_count() const {
    return capacity;
}

template<typename KeyType, typename ValueType>
size_t chain_hash<KeyType, ValueType>::bucket_size(const size_t &i_bucket) const {
    return array[i_bucket].size();
}

template<typename KeyType, typename ValueType>
size_t chain_hash<KeyType, ValueType>::get_size() const{
    return size;
}

template<typename KeyType, typename ValueType>
bool chain_hash<KeyType, ValueType>::bucket_empty(const size_t &i_bucket) const {
    return array[i_bucket].empty();
}

template<typename KeyType, typename ValueType>
float chain_hash<KeyType, ValueType>::fill_factor() const {
    return (size) / (capacity * max_collision);
}

template<typename KeyType, typename ValueType>
void chain_hash<KeyType, ValueType>::rehashing() {
    auto* temp = new forward_list<triplet>[capacity * 2];
    for (size_t i=0; i<bucket_count(); ++i){
        for (const chain_hash<KeyType, ValueType>::triplet & triplet: array[i]){
            size_t index = triplet.hash_code % (this->capacity * 2);
            temp[index].push_front(chain_hash<KeyType, ValueType>::triplet(triplet.key, triplet.value, triplet.hash_code));
        }
    }
    capacity *= 2;
    delete array;
    array = temp;
}

template<typename KeyType, typename ValueType>
void chain_hash<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value) {
    if (fill_factor() >= max_fill_factor){
        rehashing();
    }
    size_t hash_code = hash_functor(key);
    index_t index = hash_code % capacity;
    // TODO: determinar si la llave ya existe
    for (triplet &element: array[index]) {
        if (element.key == key) {
            element.value = value;
            return;
        }
    }
    array[index].push_front(chain_hash<KeyType, ValueType>::triplet(key, value, hash_code));
    ++size;
}

template<typename KeyType, typename ValueType>
void chain_hash<KeyType, ValueType>::remove(const KeyType& key) {
    size_t hash_code = hash_functor(key);
    size_t index = hash_code % capacity;
    array[index].remove_once_if([&](chain_hash<KeyType, ValueType>::triplet& triplet){
        if (triplet.key == key) {
            --size;
        }
        return triplet.key == key;
    });
}

template<typename KeyType, typename ValueType>
ValueType &chain_hash<KeyType, ValueType>::get(const KeyType &key) {
    size_t hash_code = hash_functor(key);
    size_t index = hash_code % capacity;
    for (triplet& triplet: array[index]){
        if (triplet.key == key){
            return triplet.value;
        }
    }
    insert(key, ValueType());
    return get(key);
    // throw std::invalid_argument("Invalid operation, the key is not in the hash");
}

template<typename KeyType, typename ValueType>
ValueType &chain_hash<KeyType, ValueType>::operator[](const KeyType &key) {
    return get(key);
}

template<typename KeyType, typename ValueType>
ValueType chain_hash<KeyType, ValueType>::operator[](const KeyType &key) const {
    return get(key);
}

template<typename KeyType, typename ValueType>
typename forward_list<typename chain_hash<KeyType, ValueType>::triplet>::iterator chain_hash<KeyType, ValueType>::begin(const index_t &i_bucket) {
    return array[i_bucket].begin();
}

template<typename KeyType, typename ValueType>
typename forward_list<typename chain_hash<KeyType, ValueType>::triplet>::iterator chain_hash<KeyType, ValueType>::end(const index_t&i_bucket) {
    return array[i_bucket].end();
}


#endif //HASH_CHAIN_HASH_H
