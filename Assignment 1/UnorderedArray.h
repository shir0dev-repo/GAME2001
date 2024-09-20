#pragma once

#include "Array.h"

template <typename T>
class UnorderedArray : public Array<T> {
public:
	inline UnorderedArray(int size, int growBy = 1) : Array<T>(size, growBy) { }

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

	inline virtual void pop() override {
		if (this->m_numElements > 0)
			this->m_numElements--;
	}

	inline virtual int find(T searchKey) const override {
		NULLCHECK(this->m_array);

		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == searchKey) return i;
		}

		return -1;
	}
};