#include <cassert>
#include "Array.h"
#include "UnorderedArray.h"

template <typename T>
void UnorderedArray<T>::push(T value) const {
	assert(m_array != nullptr);

	if (m_numElements > m_maxSize)
		expand();

	m_array[m_numElements++] = value;
}

template <typename T>
void UnorderedArray<T>::pop() const {
	if (m_numElements > 0)
		m_numElements--;
}

template <typename T>
int UnorderedArray<T>::indexOf(const T& searchKey) const {
	assert(m_array != nullptr);

	for (int i = 0; i < m_numElements; i++) {
		if (m_array[i] == searchKey)
			return i;
	}

	return -1;
}