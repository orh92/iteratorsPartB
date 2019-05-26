#include <utility>
#include "print.hpp"
namespace itertools{
template <class T, class E>
class _product{
private:
    const T &iterable1;   
    const E &iterable2;    

    template <typename U, typename V>
    class const_iterator{
    public:
        U iteratorA; 
        V iteratorB; 
        V BstartIter; 
        const_iterator(U iterabA, V iterabB):iteratorA(iterabA),iteratorB(iterabB),BstartIter(iterabB){}
        // operators
       
    };
public:
    _product(const T &start,const E &end) : iterable1(start), iterable2(end) {}

    auto begin() const{ 
        return  iterable1.begin();} 

    auto end() const {
        return iterable1.end(); }  
};  
template <typename T, typename E>
_product<T, E> product(const T &first,const E &second)
{
    return _product<T, E>(first, second);
}
}; // end namespace itertools
