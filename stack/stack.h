//
// Created by Juan Diego on 9/4/2022.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "../array/circular_array.cpp"

template<typename T>
class stack {
private:
    circular_array<T> data;
public:
    stack() = default;
    ~stack() = default;
    [[nodiscard]] bool empty() const{
        return data.empty();
    }
    [[nodiscard]] size_t size() const{
        return data.size();
    }
    void push(const T& value){
        data.push_front(value);
    }
    T pop(){
        return data.pop_front();
    }
    [[nodiscard]] T top(){
        return data[0];
    }
};


#endif //STACK_STACK_H
