#pragma once
#include <utility> 
#include <iostream>
#include "print.hpp"
namespace itertools{
template <class T, class E>
class _zip{
private:
   const T &iterableA;    
   const E &iterableB;   
    // inner class of zip
    template <typename U, typename V>
    class const_iterator{
    public:
        U iterA; 
        V iterB; 
        const_iterator(U iterabA, V iterabB) : iterA(iterabA), iterB(iterabB) {}
        // operators
        bool operator!=(_zip::const_iterator<U,V> const &other) {
            return (iterA != other.iterA) && (iterB != other.iterB);
        }
        std::pair<decltype(*iterA),decltype(*iterB)> operator*() const{
            return std::pair< decltype(*iterA),decltype(*iterB)> (*iterA,*iterB);
        }
        _zip::const_iterator<U,V> &operator++(){
            ++iterA;
            ++iterB;   
            return *this;
        }
    };
public:
    _zip(const T &start,const E &end) : iterableA(start), iterableB(end) {} 
    auto begin() const{ 
        return  _zip::const_iterator<decltype(iterableA.begin()),decltype(iterableB.begin())>(iterableA.begin(), iterableB.begin()); } 

    auto end() const {
        return _zip::const_iterator<decltype(iterableA.end()),decltype(iterableB.end())>(iterableA.end(), iterableB.end()); }   
}; 
template <typename T, typename E>
_zip<T, E> zip(const T &first,const E &second){
    return _zip<T, E>(first, second);
}
} // namespace itertools
