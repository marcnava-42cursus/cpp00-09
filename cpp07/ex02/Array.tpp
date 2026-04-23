template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n) {
	if (_size > 0)
		_data = new T[_size]();
}

template <typename T>
Array<T>::Array(Array const &other) : _data(NULL), _size(0) {
	*this = other;
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
	if (this != &other) {
		delete[] _data;
		_data = NULL;
		_size = other._size;
		if (_size > 0) {
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw IndexOutOfBoundsException();
	return _data[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw IndexOutOfBoundsException();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}

template <typename T>
Array<T>::IndexOutOfBoundsException::IndexOutOfBoundsException(void) throw() {}

template <typename T>
Array<T>::IndexOutOfBoundsException::IndexOutOfBoundsException(
	IndexOutOfBoundsException const &other) throw() {
	(void)other;
}

template <typename T>
typename Array<T>::IndexOutOfBoundsException &
Array<T>::IndexOutOfBoundsException::operator=(
	IndexOutOfBoundsException const &other) throw() {
	(void)other;
	return *this;
}

template <typename T>
Array<T>::IndexOutOfBoundsException::~IndexOutOfBoundsException(void) throw() {}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what(void) const throw() {
	return "Array index is out of bounds";
}
