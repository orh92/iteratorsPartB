namespace itertools{

template <class T, class E>
class _chain{
private:
   const T &iterableA;    
   const  E &iterableB;   

    // inner class of chain
    template <typename U, typename V>
    class const_iterator {
    public:
        U iteratorA; 
        V iteratorB; 
        bool flagA;

	//constructle of iteratorA and iterator B and flag
        const_iterator(U iterabA, V iterabB) : iteratorA(iterabA), iteratorB(iterabB), flagA(true) {}


        // operators

        bool operator!=(_chain::const_iterator<U,V> const &other) 
        {
            if (flagA && !(iteratorA != (other.iteratorA)))
                flagA = false;

            if(flagA)
                return (iteratorA != (other.iteratorA));
            else 
                return (iteratorB != (other.iteratorB));

            
        }

        decltype(*iteratorA) operator*() const{
            if(flagA)
                return *iteratorA;
            else
                return *iteratorB;
        }

        _chain::const_iterator<U,V> &operator++(){
            if(flagA)
                ++iteratorA;
            else 
                ++iteratorB;
            
            return *this;
        }
    };//end inner class iterator

public:
    _chain(const T &start,const E &end) : iterableA(start), iterableB(end) {}

    auto begin() const{ 
        return  _chain::const_iterator<decltype(iterableA.begin()),decltype(iterableB.begin())>(iterableA.begin(), iterableB.begin()); }  

    auto end() const {
        return _chain::const_iterator<decltype(iterableA.end()),decltype(iterableB.end())>(iterableA.end(), iterableB.end()); }  
};  

template <typename T, typename E>

_chain<T, E> chain(const T &first,const E &second){
    return _chain<T, E>(first, second);
}

}; //end namespace itertools
