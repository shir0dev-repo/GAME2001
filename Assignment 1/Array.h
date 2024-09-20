#pragma once

#include <cassert>
#include <iostream>

#define NULLCHECK(x) assert(x != nullptr)

template <typename T>
class Array {
public:
	inline Array(int size, int growBy = 1) :
		m_array(nullptr), m_maxSize(0), m_growSize(0), m_numElements(0) {
		
		if (size > -1) {
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = growBy > 0 ? growBy : 0;
		}
	}

	inline ~Array() {
		if (m_array != nullptr) {
			delete[] m_array;
			m_array = nullptr;
		}
	}

	virtual void push(T) = 0;
	virtual void pop() = 0;
	virtual int find(T) const = 0;

	inline void remove(int index) {
		NULLCHECK(m_array);

		if (index >= m_numElements) {
			std::cout << "Could not remove element at index " << index << std::endl;
			return;
		}

		for (int i = index; i < m_numElements; i++) {
			if (i + 1 < m_numElements)
				m_array[i] = m_array[i + 1];
		}

		m_numElements--;
	}

	inline void clear() {
		m_numElements = 0;
	}

	inline T operator[](int index) {
		NULLCHECK(m_array);
		assert(index >= 0 && index < m_numElements);

		return m_array[index];
	}

	inline int getSize() { return m_numElements; }
	inline int getMaxSize() { return m_maxSize; }
	inline int getGrowSize() { return m_growSize; }
	inline void setGrowSize(int growBy) { m_growSize = growBy > 0 ? growBy : 0; }

	inline friend std::ostream& operator<<(std::ostream& os, const Array<T>& a) {
		os << "Elements: ";
		
		for (int i = 0; i < a.m_numElements; i++) {
			os << a.m_array[i] << " ";
		}

		os << std::endl;

		os << "Current Size: " << a.m_numElements << std::endl 
			<< "Max Size: " << a.m_maxSize << std::endl
			<< "Grow Size: " << a.m_growSize << std::endl;

		return os;
	}

protected:
	T* m_array;

	int m_maxSize;
	int m_numElements;
	int m_growSize;

	virtual bool expand() {
		if (m_growSize <= 0) return false;

		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;

		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;
		m_growSize <<= 1; // double expansion size each time

		return true;
	}


};