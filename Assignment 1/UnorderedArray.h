#pragma once

#include "Array.h"

template <typename T>
class UnorderedArray : public Array<T> {
public:
	inline UnorderedArray(int size, int growBy = 1) : Array<T>(size, growBy) { 
		std::cout << "Created new OrderedArray<" << typeid(T).name() << ">"
			<< " with initial size of " << size
			<< " and growth value of " << growBy << '.'
			<< std::endl << std::endl;
	}

	inline OrderedArray<T> sort(bool allowDuplicates) const {
		OrderedArray<T> oa(allowDuplicates, this->m_maxSize, this->m_growSize);
		for (int i = 0; i < this->m_numElements; i++) {
			oa.push(this->m_array[i]);
		}

		return oa;
	}

	inline virtual void push(T value) override {
		NULLCHECK(this->m_array);

		if (this->m_numElements >= this->m_maxSize) this->expand();
		this->m_array[this->m_numElements++] = value;
	}

	inline virtual int find(T searchKey) const override {
		NULLCHECK(this->m_array);

		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == searchKey) {
				std::cout << "Found " << searchKey << " at index " << i << '.' << std::endl;
				return i;
			}
		}

		std::cout << "Could not find " << searchKey << '.' << std::endl;
		return -1;
	}
};