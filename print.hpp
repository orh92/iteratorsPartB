#pragma once
#include <iostream>
#include <vector>
#include <utility> 

template <typename T,typename E>
std::ostream &operator<<(std::ostream &os, const std::pair<T,E>&p){
    os << p.first << ',' << p.second;//take first , second and return
    return os;
}



template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &S)
{
    os << "{"; //open set
    auto it = S.begin();
    if(it != S.end()){
        os << *it; 
        ++it;
    }

    while (it != S.end()){
        os << ',' << *it;//take each element of the set
        ++it;
    }
    os << "}";//and set
    return os;
}
