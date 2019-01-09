#include <memory>

namespace my_vector {

	template <class T> class Iterator;

	template <class T> class vector {

	private:
		size_t _size;
		T *entries;
		std::unique_ptr<T[]> _data;
		size_t capacity;
		const size_t initial_capacity = 16;
		void init();

	public:
		vector();
		vector(size_t t);
		explicit vector(const vector<T> & other);
		vector(std::initializer_list<T> list);
		vector(vector<T>&& other);
		~vector();

		T *data();
		//int capacity();
		//T *entries;

		const T* begin() const;
		T* begin();
		const T* end() const;
		T* end();
		/*Iterator<T> begin();
		Iterator<T> end();*/
		size_t size() const;

		//T & front();
		//T & back();


		vector<T> & operator=(vector<T> && other);      
		vector<T> & operator=(const vector<T> & other); 

		void assign(size_t count, const T & _data = T());
		void assign(Iterator<T> begin, Iterator<T> end);

		bool empty() const;

		void push_back(T && value);
		void pop_back();
		void clear();
		void swap(vector<T> & other);
		void erase(Iterator<T> start);
		void erase(Iterator<T> start, Iterator<T> end);

		bool operator == (vector<T> & other);
		bool operator != (vector<T> & other);

		T operator[](size_t i) const;
		T& operator[](size_t i);

	};

	template <class T> void swap(vector<T> & rhs, vector<T> & lhs) 	{
		rhs.swap(lhs);
	}

	template <class T> vector<T>::vector() : _data(nullptr), _size(0) {};

	template <class T> vector<T>::vector(size_t t) : _data(new T[t]), _size(t) {};

	template <class T> vector<T>::vector(const vector<T> & other) {
		init();
		for (auto it : other) { this->push_back(it); }
	}
	
	template <class T> vector<T>::vector(std::initializer_list<T> list) : _data(new T[list.size()]), _size(list.size())
	{
		for (int i = 0; i < list.size(); i++)
		{
			_data[i] = list[i];
		}
	}

	template <class T> vector<T>::vector(vector<T> && other)
	{
		this->swap(other);
	}

	template <class T> vector<T>::~vector() {
		delete[] entries;
	}

	template <class T> const T* vector<T>::begin() const
	{
		return _data.get();
	}

	template <class T> T* vector<T>::begin()
	{
		return _data.get();
	}
	template <class T> const T* vector<T>::end() const
	{
		return _data.get() + _size;
	}

	template <class T> T* vector<T>::end()
	{
		return _data.get() + _size;
	}

	template <class T> size_t vector<T>::size() const
	{
		return _size;
	}

	template <class T> void vector<T>::assign(size_t count, const T & data) {
		for (size_t i = 0; i < count; i++) { this->push_back(data); }
	}

	template <class T> void vector<T>::assign(Iterator<T> start, Iterator<T> end) {
		while (start != end) { this->push_back(*start++); }
	}


	template <class T> bool vector<T>::empty() const {
		return !_size;
	}

	template <class T> void vector<T>::push_back(T && value) {
		std::unique_ptr<T[]> temp(new T[_size + 1]);
		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = std::move(_data[i]);
		}
		temp[_size] = std::move(value);
		_data.swap(temp);
		_size++;
	}
	template <class T> void vector<T>::pop_back() {
		std::unique_ptr<T[]> temp(new T[_size - 1]);
		for (size_t i = 0; i < _size - 1; i++)
		{
			temp[i] = std::move(_data[i]);
		}
		_data.swap(temp);
		_size--;
	}

	template <class T> void vector<T>::clear() {
		delete[] entries;
		init();
	}

	template <class T> void vector<T>::swap(vector<T> & other) {
		std::swap(_size, other._size);
		_data.swap(other._data);
	}

	template <class T> void vector<T>::erase(Iterator<T> start) {
		std::unique_ptr<T[]> temp(new T[_size - 1]);
		size_t count = 0;
		for (T i = begin(); i + count != end(); i++)
		{
			if (i == start) count++;
			else temp[i] = std::move(*(i + count));
		}
		_size--;
		_data.swap(temp);
	}
	template <class T> void vector<T>::erase(Iterator<T> start, Iterator<T> end)
	{
		std::unique_ptr<T[]> temp(new T[_size - end + start]);
		size_t count = 0;
		for (T* i = begin(); i + count != end(); i++)
		{
			if (i >= start && i <= end) count++;
			else temp[i] = std::move(*(i + count));
		}
		_size = _size - end + start;
		_data.swap(temp);
	}

	template <class T> vector<T> & vector<T>::operator=(vector<T> const & other) {
		_size = other.size();
		_data.reset(new T[_size]);
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = other[i];
		}
		return *this;
	}

	template <class T> vector<T> & vector<T>::operator=(vector<T> && other) {
		this->swap(other);
		return *this;
	}


	template <class T> bool vector<T>::operator == (vector<T> & other) {
		if (this->size() != other.size()) { return false; }
		else {
			auto m = this->begin(), o = other.begin();
			auto _end = this->end();
			while (m != _end) {
				if (*m++ != *o++) { return false; }
			}
			return true;
		}
	}

	template <class T> bool vector<T>::operator != (vector<T> & other) {
		return !((*this) == other);
	}

	template <class T> T vector<T>::operator[](size_t i) const
	{
		if (i >= _size || i < 0)
			throw std::runtime_error("bad index");
		return _data[i];
	}
	template <class T> T& vector<T>::operator[](size_t i)
	{
		if (i >= _size || i < 0)
			throw std::runtime_error("bad index");
		return _data[i];
	}

};
