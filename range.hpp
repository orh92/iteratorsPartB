namespace itertools {

	template <class T>

	class _range {
	private:
		const T _begin;
		const T _end;

		//inner class iterator
		class const_iterator {
		public:
			T iter;
			const_iterator(T item) :iter(item) {}

			//override operators of iterator object
			bool operator !=(_range::const_iterator const second)const {
				return (this->iter != (second.iter));
			}

			_range::const_iterator &operator++() {
				++this->iter;
				return *this;
			}

			T operator *()const {
				return this->iter;
			}

		};//end inner class iterator

	public:
		_range(const T begin,const T end) :_begin(begin), _end(end) {}
		_range::const_iterator begin()const { return _range::const_iterator(_begin); }//return _begin
		_range::const_iterator end()const { return _range::const_iterator(_end); }//return _end
	};//end class range

	template <typename T>
	_range<T> range(const T begin,const T end) {
		return _range<T>(begin, end);
	}


};//end itertools namespace
