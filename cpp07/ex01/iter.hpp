#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *array, unsigned int len, F fn) {
	if (!array)
		return;
	for (unsigned int i = 0; i < len; ++i)
		fn(array[i]);
}

template <typename T, typename F>
void iter(T const *array, unsigned int len, F fn) {
	if (!array)
		return;
	for (unsigned int i = 0; i < len; ++i)
		fn(array[i]);
}

#endif
