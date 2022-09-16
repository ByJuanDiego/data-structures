//
// Created by Juan Diego on 9/15/2022.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <vector>
#include <iterator>
#include <iostream>
#include <stdexcept>
using std::vector;


template <typename T>
class heap{

private:

    vector<T> data;

    static int left(int index){
        return index*2 + 1;
    }
    static int right(int index){
        return index*2 + 2;
    }
    static int parent(int index){
        return (index-1) / 2;
    }

    static void heapify_down(vector<T>& container, int index){
        int left  = heap<T>::left(index);
        int right = heap<T>::right(index);

        int size = container.size();
        int max = index;

        if (left < size && container[left] > container[max]){
            max = left;
        }
        if (right < size && container[right] > container[max]){
            max = right;
        }

        if (max != index){
            std::swap(container[index], container[max]);
            heapify_down(container, max);
        }
    }

    static void heapify_up(vector<T>& container, int index){
        int parent = heap<T>::parent(index);
        if (container[parent] < container[index]){
            std::swap(container[parent], container[index]);
            heapify_up(container, parent);
        }
    }

public:

    heap() = default;

    explicit heap(int _cap){
        data.reserve(_cap);
    }

    void push(T value){//O(log n)
        data.push_back(value);
        heapify_up(data, data.size()-1);
    }

    void pop(){//O(log n)
        if (data.empty()){
            throw std::invalid_argument("no puedes hacer pop en un heap vacio");
        }
        data[0] = data[data.size() - 1];
        data.pop_back();
        heapify_down(data, 0);
    }

    static void build_from(vector<T>& container){// O(n log(n))
        int size = container.size();
        for (int i = size/2; i>= 0; --i){    // O(n/2)
            heapify_down(container, i);// O(log n)
        }
    }

    void display(std::ostream& os){
        for (const auto& element: data){
            os << element << ", ";
        }
    }

    T max(){// O(1)
        if (data.empty()){
            throw std::invalid_argument("The heap is empty");
        }
        return data[0];
    }

};


#endif //HEAP_HEAP_H
