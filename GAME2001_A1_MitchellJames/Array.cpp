#include "Array.h"
#include <cassert>

template <typename T>
Array<T>::Array<T>(int size, int growBy) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0) {
	if (size > 0) {
		m_maxSize = size;
		m_array = new T[m_maxSize];
		memset(m_array, 0, sizeof(T) * m_maxSize);

		m_growSize = ((growBy > 0) ? growBy : 0);
	}
}

template <typename T>
Array<T>::~Array<T>() {
	if (m_array != nullptr) {
		delete[] m_array;
		m_array = nullptr;
	}
}

template<typename T> 
void Array<T>::remove(int index) {
	assert(m_array != nullptr);
	
	if (index < 0 || index >= m_numElements) return;

	for (int i = index; i < m_numElements; i++) {
		if (i + 1 < m_numElements) {
			m_array[i] = m_array[i + 1];
		}
	}

	m_numElements--;
}

template <typename T>
void Array<T>::clear() {
	m_numElements = 0;
}

template <typename T>
bool Array<T>::expand() {
	if (m_growSize <= 0) return false; // can't expand by anything less than 1

	T* temp = new T[m_maxSize + m_growSize]; // temporarily assign memory for newly sized array
	assert(temp != nullptr); // ensure temp memory isn't null

	memcpy(temp, m_array, sizeof(T) * m_maxSize); // copy over old data to larger array
	delete[] m_array; // delete stale copy of data

	m_array = temp; // pass over copied data back to reference
	temp = nullptr; // delete temp memory

	m_maxSize += m_growSize; // increment size to account for expansion
	return true; // successfully expanded array, yippee!
}

template <typename T>
T& Array<T>::operator[](int index) {
	assert(m_array != nullptr && (index > 0 && index < m_numElements)); // ensure proper array indexing
	return m_array[index];
}